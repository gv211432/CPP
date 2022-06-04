#ifndef gauravs_print_arr_vec
#define gauravs_print_arr_vec

namespace print_vec
{
#include <iostream>
#include <vector>
    using namespace std;

    class Print
    {
    public:
        // Print the array of size "n"
        void print_arr(int *arr, size_t len)
        {
            std::cout << "[ ";
            for (size_t i = 0; i < len; i++)
            {
                // std::cout << arr[i] << std::endl;
                // std::cout << "Hello" << std::endl;
                cout << *(arr + i), ((i + 1) < len) ? cout << ", " : cout << " ";
            }
            std::cout << "]" << std::endl;
        }

        // Prints the vector "v"
        void print_arr(vector<int> &v)
        {
            std::cout << "[ ";
            for (auto &n : v)
                std::cout << n, &n == &v.back() ? cout << " " : cout << ", ";
            std::cout << "]" << std::endl;
        }

        // Prints the array of array with length "len" and width as "width"
        void print_aoa(int *arr, size_t len, size_t width)
        {
            std::cout << "[ ";
            for (size_t i = 0; i < len; i++)
            {
                std::cout << "[ ";
                for (size_t j = 0; j < width; j++)
                    cout << *(arr + i + j), ((j + 1) < width) ? cout << ", " : cout << " ";
                std::cout << "]" << std::endl;
            }
            std::cout << "]" << std::endl;
        }

        // Prints the vector of vector
        void print_aoa(vector<vector<int>> &v)
        {
            for (auto x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }

        // Prints the vector "v"
        void print_vov(vector<int> &v)
        {
            std::cout << "{ ";
            for (auto &n : v)
                std::cout << n, &n == &v.back() ? cout << " " : cout << ", ";
            std::cout << "}" << std::endl;
        }

        // template <typyname T>
        void print_vov(vector<vector<int>> &v)
        {
            for (auto x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }

        void print_vov(vector<vector<string>> &v)
        {
            for (auto x : v)
            {
                std::cout << "{ ";
                for (auto &n : x)
                    std::cout << n, &n == &x.back() ? cout << " " : cout << ", ";
                std::cout << "}" << std::endl;
            }
        }
    };
} // namespace print_vov

#endif