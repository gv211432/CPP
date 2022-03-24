// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
// #include <iostream>
// #include <stdlib.h>
using namespace std;

// Number of vertices in the graph
#define V 5

// print the given array
void PrintArr(int arr[], int n, string s = "")
{

    std::cout << std::endl;
    std::cout << s << std::endl;

    int totalChar = 0;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
        totalChar += std::to_string(arr[i]).length();
        // std::cout << std::to_string(arr[i]).length() << std::endl;
    }
    std::cout << std::endl;

    // std::cout << totalChar << std::endl;

    for (int i = 0; i < totalChar; i++)
    {
        std::cout << "=";
    }
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << "=";
    }

    std::cout << std::endl;
}

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t   " << graph[i][parent[i]] << " \n";
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mstSet[V];

    // Initialize all keys as INFINITE and corresponding mstSet as false
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST because its source
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    // for every count in the following loop it represents the vertex and in
    // this loop another loop checks for other vertex's shortest connection
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in
        std::cout << std::endl;
        // std::cout << "For count : " << count << std::endl;

        printf("\x1B[31m For count :  %d\033[0m\n", count);

        for (int v = 0; v < V; v++)
        {
            std::cout << "Trying for the vertex : " << v << std::endl;

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                std::cout << "\tCompleted for the vertex : "
                          << "\033[32m" << v << ":::::" << u << "\033[0m"
                          << "  => "
                          << "\x1b[42;30m " << graph[u][v] << " \033[0m" << std::endl;
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    PrintArr(parent, V, "Printing the parent array");
    PrintArr(key, V, "Printing the Keys");

    // print the constructed MST
    printMST(parent, graph);
}

// Driver code
int main()
{
    /* Let us create the following graph

        2     3
     (0)--(1)--(2)
      |   / \   |
     6| 8/   \5 |7
      | /     \ |
     (3)-------(4)
           9                            */

    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};

    // PrintArr(graph[0], V);
    // PrintArr(graph[1], V);
    // PrintArr(graph[2], V);
    // PrintArr(graph[3], V);
    // PrintArr(graph[4], V);

    // printing the tree
    std::cout << "   2     3   " << std::endl
              << "(0)--(1)--(2)" << std::endl
              << " |   / \\   | " << std::endl
              << "6| 8/   \\5 |7" << std::endl
              << " | /     \\ | " << std::endl
              << "(3)-------(4)" << std::endl
              << "      9      " << std::endl
              << std::endl;

    // Print the solution
    primMST(graph);

    return 0;
}

// This code is contributed by rathbhupendra
