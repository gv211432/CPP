#include <iostream>
#include <time.h>

#define ASIO_STANDALONE
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

// structure for holding time
struct tm *ptrToTime;
time_t currentTime;

// vector place for incoming data
std::vector<char> vBuffer(20 * 1024);

void GrabSomeData(boost::asio::ip::tcp::socket &socket)
{
    socket.async_read_some(boost::asio::buffer(vBuffer.data(), vBuffer.size()),
                           [&](std::error_code ec, std::size_t length)
                           {
                               if (!ec)
                               {
                                   std::cout << "\n\nRead " << length << " bytes\n\n";
                                   for (size_t i = 0; i < length; i++)
                                   {
                                       std::cout << vBuffer[i];
                                   }
                                   GrabSomeData(socket);
                               }
                               std::cout << ""
                                         << std::endl;
                           });
}

int main(void)
{
    // container for error code
    boost::system::error_code ec;

    // input output object
    boost::asio::io_context context;

    // giving some fake task to keep the program runnig
    boost::asio::io_context::work idleWork(context);

    // starting the context in other thread without blocking the current
    std::thread thrContext = std::thread([&]()
                                         { context.run(); });

    // adding info to i/o object to connect to with protocol
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("15.206.246.196", ec), 80);
    boost::asio::ip::tcp::socket socket(context);

    // on socket connection or error in connection
    // ec will contain the error object..
    socket.connect(endpoint, ec);

    if (!ec)
    {
        // if no error in connection
        std::cout << "Connected" << std::endl;
    }
    else
    {
        // if error in the connection
        std::cout << "Failed to connect to address :\n"
                  << ec.message() << std::endl;
    }

    // as soon as socket opens on successful connection,
    // transect data in between
    if (socket.is_open())
    {
        // Async way of reading data on data arrival.
        GrabSomeData(socket);

        // sending the standard http get reauest
        std::string sRequest = "GET /index.html HTTP/1.1\r\n\
                                HOST: vishwakarmahome.tk\r\n\
                                Connection: close\r\n\r\n";

        socket.write_some(boost::asio::buffer(sRequest.data(), sRequest.size()), ec);

        currentTime = time(NULL);
        ptrToTime = localtime(&currentTime);
        printf("%s", asctime(ptrToTime));

        // keeping the process going on for child process (context) to stay alive.
        sleep(2);

        currentTime = time(NULL);
        ptrToTime = localtime(&currentTime);
        printf("%s", asctime(ptrToTime));

        // socket.wait(socket.wait_read);
        // size_t bytes = socket.available();
        // std::cout << "Bytes availabel" << bytes << std::endl;
        // if (bytes > 0)
        // {
        //     std::vector<char> vBuffer(bytes);
        //     socket.read_some(boost::asio::buffer(vBuffer.data(), vBuffer.size()), ec);
        //     for (auto c : vBuffer)
        //     {
        //         std::cout << c;
        //     }
        //     std::cout << "\n"
        //               << std::endl;
        // }

        // on task completion killing(joining) the process to the main.
        context.stop();
        if (thrContext.joinable())
            thrContext.join();
    }

    return 0;
}
