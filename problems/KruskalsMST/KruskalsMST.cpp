// ╻┏ ┏━┓╻ ╻┏━┓╻┏ ┏━┓╻  ┏━┓   ┏┳┓╻┏┓╻╻┏┳┓╻ ╻┏┳┓   ┏━┓┏━┓┏━┓┏┓╻┏┓╻╻┏┓╻┏━╸
// ┣┻┓┣┳┛┃ ┃┗━┓┣┻┓┣━┫┃  ┗━┓   ┃┃┃┃┃┗┫┃┃┃┃┃ ┃┃┃┃   ┗━┓┣━┛┣━┫┃┗┫┃┗┫┃┃┗┫┃╺┓
// ╹ ╹╹┗╸┗━┛┗━┛╹ ╹╹ ╹┗━╸┗━┛   ╹ ╹╹╹ ╹╹╹ ╹┗━┛╹ ╹   ┗━┛╹  ╹ ╹╹ ╹╹ ╹╹╹ ╹┗━┛
// ╺┳╸┏━┓┏━╸┏━╸   ┏━┓╻  ┏━╸┏━┓┏━┓╻╺┳╸╻ ╻┏┳┓
//  ┃ ┣┳┛┣╸ ┣╸    ┣━┫┃  ┃╺┓┃ ┃┣┳┛┃ ┃ ┣━┫┃┃┃
//  ╹ ╹┗╸┗━╸┗━╸   ╹ ╹┗━╸┗━┛┗━┛╹┗╸╹ ╹ ╹ ╹╹ ╹

// debug this is not properly working!!

#include <bits/stdc++.h>
using namespace std;

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

    void releseMem()
    {
        delete[] parent;
        delete[] rank;
    }
};

// ====================================================================
class Graph1
{
private:
    // in the vector, in the pair, [First = destination, second = wight] of the graph
    // map<int, vector<pair<int, int>>> vertex;
    map<int, vector<pair<int, int>>> vertex;
    size_t vertexCount;

public:
    Graph1(int n)
    {
        vertexCount = n;
        // for (size_t i = 0; i < n; i++)
        // {
        //     verte
        // }
    }

    // It adds new edges(vertex connection in the graph)
    void addEdge(size_t src, size_t dest, int weight)
    {
        if (src <= vertexCount && dest <= vertexCount)
        {
            vertex[src].push_back(make_pair(dest, weight));
        }
    }

    // It prints all the vertices present in the graph
    void print()
    {
        for (size_t i = 0; i < vertexCount; i++)
        {
            std::cout << i << " ==> ";
            auto itr = vertex[i].begin();
            for (size_t j = 0; j < vertex[i].size(); j++)
            {
                std::cout << "[" << itr[j].first << "," << itr[j].second << "] ";
            }
            std::cout << std::endl;
        }
    }
};

// ====================================================================

class Graph2
{
private:
    vector<pair<int, int>> *vertex;
    size_t vertexCount = 0;
    bool isChar = 0;

public:
    Graph2(size_t n, bool isChar = 0)
    {
        this->isChar = isChar;
        vertexCount = n;
        // dynamically allocating the space in the memory
        vertex = (vector<pair<int, int>> *)calloc(vertexCount, vertexCount * sizeof(vector<pair<int, int>> *));
    }

    // It adds new edges(vertex connection in the graph)
    void addEdge(size_t src, size_t dest, int weight)
    {
        if (src <= vertexCount && dest <= vertexCount)
        {
            vertex[src].push_back(make_pair(dest, weight));
        }
    }

    // It prints all the vertices present in the graph
    void print()
    {
        if (isChar)
        {
            for (size_t i = 0; i < vertexCount; i++)
            {
                char a = i + 97;
                std::cout << a << " ==> ";
                for (auto x : vertex[i])
                {
                    char a = x.first + 97;
                    std::cout << "[" << a << "," << x.second << "] ";
                }
                std::cout << std::endl;
            }
        }
        else
        {

            for (size_t i = 0; i < vertexCount; i++)
            {
                std::cout << i << " ==> ";
                auto itr = vertex[i].begin();
                for (size_t j = 0; j < vertex[i].size(); j++)
                {
                    std::cout << "[" << itr[j].first << "," << itr[j].second << "] ";
                }
                std::cout << std::endl;
            }
        }
    }

    size_t getVertexCount()
    {
        return vertexCount;
    }

    vector<pair<int, int>> *getVertex()
    {
        return vertex;
    }
};

// ====================================================================
// ====================================================================

// The main function to check whether a given graph contains
// cycle or not
int isCycle(Graph2 *graph)
{
    DSU s(graph->getVertexCount());

    // Iterate through all edges of graph, find subset of
    // both vertices of every edge, if both subsets are
    // same, then there is cycle in graph.

    for (size_t i = 0; i < graph->getVertexCount(); i++)
    {
        // std::cout << i << " ==> ";

        for (auto x : graph->getVertex()[i])
        {
            // std::cout << "[" << itr[j].first << "," << itr[j].second << "] ";

            // doesn't stop looping until reach the parnet(-1) vertex
            int src = s.find(i);

            // doesn't stop looping until reach the parnet(-1) vertex
            int dest = s.find(x.first);

            // src and dest may have the same parent
            // if loop found exit the block with 1
            if (src == dest)
            {
                s.releseMem();
                return 1;
            }

            // else merge the found value in the parent array
            s.unite(i, x.first);
        }
        // std::cout << std::endl;
    }
    return 0;
}

// ====================================================================
// ====================================================================

// The steps for finding MST using Kruskal’s algorithm

//     1. Sort all the edges in non-decreasing order of their weight.
//     2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far.
//        If cycle is not formed, include this edge. Else, discard it.
//     3. Repeat step#2 until there are (V-1) edges in the spanning tree.

struct vertex
{
    size_t src;
    int weight, dest;
};

class CompareEdge
{
public:
    bool operator()(vertex x, vertex y)
    {
        return x.weight > y.weight;
    }
};

void KruskalMST(Graph2 *graph, bool isChar = 0)
{
    priority_queue<vertex, vector<vertex>, CompareEdge> min_heap;

    // following block pushes all the graph's vertices in the min heap
    for (size_t i = 0; i < graph->getVertexCount(); i++)
    {
        for (auto x : graph->getVertex()[i])
        {
            vertex v;
            v.src = i;
            v.dest = x.first;
            v.weight = x.second;

            min_heap.push(v);
        }
    }

    size_t MSTcounter = 0;

    DSU s(graph->getVertexCount());

    std::cout << "================================" << std::endl;

    for (size_t i = 0; i < graph->getVertexCount(); i++)
    {
        for (auto x : graph->getVertex()[i])
        {
            // if edge count exceeds (verter - 1) count, exit the function
            if (MSTcounter == graph->getVertexCount() - 1)
            {
                s.releseMem();
                break;
            }

            // doesn't stop looping until reach the parnet(-1) vertex
            int src = s.find(i);
            // doesn't stop looping until reach the parnet(-1) vertex
            int dest = s.find(x.first);

            // getting the top element of the heap then deleting it
            auto q = min_heap.top();
            min_heap.pop();

            // if (findAndUnite.find(i) != findAndUnite.find(itr[j].first))
            if (src != dest)
            {
                // removing the top element form min heap and then delenting it.
                // this takes O(nlogn)
                if (isChar)
                {
                    char a = q.src + 97;
                    char b = q.dest + 97;
                    std::cout << a << "-------" << q.weight << "--------" << b << std::endl;
                }
                else
                {
                    std::cout << q.src << "-------" << q.weight << "--------" << q.dest << std::endl;
                }
                MSTcounter++;

                // findAndUnite.unite(i, itr[j].first);
                s.unite(i, x.first);
            }
        }
    }

    std::cout << "================================" << std::endl;
    return;
}

void printInHeap(Graph2 g)
{
    priority_queue<vertex, vector<vertex>, CompareEdge> min_heap;

    // following block pushes all the graph's vertices in the min heap
    for (size_t i = 0; i < g.getVertexCount(); i++)
    {
        for (auto x : g.getVertex()[i])
        {
            vertex v;
            v.src = i;
            v.dest = x.first;
            v.weight = x.second;

            min_heap.push(v);
        }
    }

    std::cout << "================================" << std::endl;

    auto l = min_heap.size();
    for (size_t i = 0; i < l; i++)
    {
        auto q = min_heap.top();
        min_heap.pop();
        char a = q.src + 97;
        char b = q.dest + 97;
        std::cout << a << "-------" << q.weight << "--------" << b << std::endl;
    }
}

// ====================================================================
// ====================================================================

int main()
{

    std::cout << "Source => [ Destination,Weight ]" << std::endl;

    Graph2 graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);
    graph.addEdge(2, 0, 6);
    graph.addEdge(0, 3, 5);

    graph.print();

    if (isCycle(&graph))
        cout << "graph contains cycle" << endl;
    else
        cout << "graph doesn't contain cycle" << endl;

    KruskalMST(&graph);

    Graph2 g1(5);

    int nodes1[5][3] = {
        {9, 'a', 'c'}, {6, 'a', 'd'}, {4, 'c', 'd'}, {26, 'd', 'b'}, {20, 'd', 'e'}};

    for (size_t i = 0; i < 5; i++)
    {
        g1.addEdge(nodes1[i][1] - 97, nodes1[i][2] - 97, nodes1[i][0]);
    }

    KruskalMST(&g1, 1);

    Graph2 g2(7, true);

    int nodes2[11][3] = {
        {1, 'a', 'c'}, {4, 'a', 'b'}, {5, 'a', 'd'}, {15, 'b', 'd'}, {3, 'b', 'e'}, {12, 'c', 'd'}, {7, 'c', 'f'}, {18, 'd', 'e'}, {14, 'd', 'f'}, {8, 'e', 'g'}, {10, 'f', 'g'}};

    for (size_t i = 0; i < 11; i++)
    {
        g2.addEdge(nodes2[i][1] - 97, nodes2[i][2] - 97, nodes2[i][0]);
    }
    g2.print();

    printInHeap(g2);

    KruskalMST(&g2, 1);

    return 0;
}