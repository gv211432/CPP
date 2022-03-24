#include <bits/stdc++.h>
using namespace std;
// DSU data structure
// path compression + rank by union

class DSU
{
    int *parent;
    int *rank;
    int n;

public:
    DSU(int n)
    {
        this->n = n;
        // following are dynamically allocated arrays(decelared with new keyword)
        parent = new int[n]; // index= source vertex, index data = destination vertex
        // this array contains the number of element whose parent is this index
        rank = new int[n];

        // initializing every element of parent with -1 and rank with 1(a unit weight to all)
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // for debugging, printing ranks
    void printRank()
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << rank[i] << ", ";
        }
        std::cout << std::endl;
    }

    // Find function
    int find(int i)
    {
        // if the given node is parent of its own, just return its index
        if (parent[i] == -1)
            return i;

        // else finds its parent resursively and update in its array and return the parnent's index
        return parent[i] = find(parent[i]);
    }

    // union function
    void unite(int x, int y)
    {
        // if given two elements belongs to two disjoint sets, merge them
        int s1 = find(x);
        int s2 = find(y);

        // following code will merge the two nodes, if they have different parents
        // this code is independent of any outer influence. It is just used for internal understanding of whom to make parent of whom
        // following block makes the any one node the parent node, who is having more no. childrens
        // also cumulating the children's no.of children in the parnet's no. of children
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                // allocating s2 as a parent of s1
                parent[s1] = s2;
                // also incresing the weight of s2 with weight of s1
                rank[s2] += rank[s1];
            }
            else
            {
                // here rank[s2] >= rank[s1]
                parent[s2] = s1;
                // increasing the rank of s1 by adding the rank of s2
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    // adjecenct list data structure
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }

    // function to insert new edge (source, destination, weight)
    void addEdge(int src, int dest, int wt)
    {
        // keeping in the format (weight, source, destination)
        edgelist.push_back({wt, src, dest});
    }

    void print()
    {
        std::cout << "======================================" << std::endl;
        for (auto x : edgelist)
        {
            std::cout << *(x.begin()) << ", " << *(x.begin() + 1) << ", " << *(x.begin() + 2) << std::endl;
        }
        std::cout << "======================================" << std::endl;
    }

    void kruskals_mst()
    {
        // 1. Sort all edges
        // sort(edgelist.begin(), edgelist.end());

        // this sorts the element in ascending order
        sort(edgelist.begin(), edgelist.end(), [](vector<int> node1, vector<int> node2)
             { return node1 < node2; });

        // print the sorted elements
        for (auto x : edgelist)
        {
            // directly printin the elements
            // std::cout << *(x.begin()) << ", " << *(x.begin() + 1) << ", " << *(x.begin() + 2) << std::endl;

            // printing elements in the loop
            std::cout << "[ ";
            for (auto n : x)
            {
                std::cout << n << ", ";
            }
            std::cout << "]" << std::endl;
        }

        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for (auto edge : edgelist)
        {
            int weight = edge[0];
            int node1 = edge[1];
            int node2 = edge[2];

            // take that edge in MST if it doesn't form a cycle
            if (s.find(node1) != s.find(node2))
            { // but above comperasion will put those values in the DSU cache
                // and it will use it for next comperision

                // this will unite/merge the given two nodes in the DSU cache
                // (which is already inserted in DSU cache by comparision)
                s.unite(node1, node2);
                ans += weight;
                cout << node1 << " -- " << node2 << " == " << weight
                     << endl;
            }
        }
        s.printRank();
        cout << "Minimum Cost Spanning Tree: " << ans << endl;
    }
};
int main()
{
    /* Let us create following weighted graph
                10
            0--------1
            |\	     |
            | \      |
            |  \     |
            |   \5   |
           6|    \   |15
            |     \  |
            |      \ |
            |       \|
            2--------3
                4	 */

    Graph g(7);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

    g.print();

    g.kruskals_mst();

    Graph g2(7);
    int nodes2[11][3] = {
        {1, 'a', 'c'}, {4, 'a', 'b'}, {5, 'a', 'd'}, {15, 'b', 'd'}, {3, 'b', 'e'}, {12, 'c', 'd'}, {7, 'c', 'f'}, {18, 'd', 'e'}, {14, 'd', 'f'}, {8, 'e', 'g'}, {10, 'f', 'g'}};

    for (size_t i = 0; i < 11; i++)
    {
        g2.addEdge(nodes2[i][1] - 97, nodes2[i][2] - 97, nodes2[i][0]);
    }

    g2.print();
    g2.kruskals_mst();

    // int n, m;
    // cin >> n >> m;

    // Graph g(n);
    // for (int i = 0; i < m; i++)
    // {
    //	 int x, y, w;
    //	 cin >> x >> y >> w;
    //	 g.addEdge(x, y, w);
    // }

    return 0;
}
