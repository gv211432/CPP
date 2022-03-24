<!-- ┏━┓╻  ╻     ┏━┓┏┓ ┏━┓╻ ╻╺┳╸   ╺┳┓┏━╸╺┳╸┏━╸┏━╸╺┳╸┏━╸╻ ╻┏━╸╻  ┏━╸
     ┣━┫┃  ┃     ┣━┫┣┻┓┃ ┃┃ ┃ ┃     ┃┃┣╸  ┃ ┣╸ ┃   ┃ ┃  ┗┳┛┃  ┃  ┣╸
     ╹ ╹┗━╸┗━╸   ╹ ╹┗━┛┗━┛┗━┛ ╹    ╺┻┛┗━╸ ╹ ┗━╸┗━╸ ╹ ┗━╸ ╹ ┗━╸┗━╸┗━╸ -->

<!-- Disjoint Set (Or Union-Find) | Set 1 (Detect Cycle in an Undirected Graph) -->

    Difficulty Level : Medium
    Last Updated : 17 Jan, 2022

A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure:

Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.

Union: Join two subsets into a single subset. Here first we have to check if the two subsets belong to same set. If no, then we cannot perform union.

In this post, we will discuss the application of Disjoint Set Data Structure. The application is to check whether a given graph contains a cycle or not.

Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. Note that we have discussed an algorithm to detect cycle. This is another method based on Union-Find. This method assumes that the graph doesn’t contain any self-loops.

We can keep track of the subsets in a 1D array, let’s call it parent[].
Let us consider the following graph:

cycle-in-graph

For each edge, make subsets using both the vertices of the edge. If both the vertices are in the same subset, a cycle is found.

Initially, all slots of parent array are initialized to -1 (means there is only one item in every subset).

0 1 2
-1 -1 -1

Now process all edges one by one.
Edge 0-1: Find the subsets in which vertices 0 and 1 are. Since they are in different subsets, we take the union of them. For taking the union, either make node 0 as parent of node 1 or vice-versa.

0 1 2 <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
1 -1 -1

Edge 1-2: 1 is in subset 1 and 2 is in subset 2. So, take union.

0 1 2 <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
1 2 -1

Edge 0-2: 0 is in subset 2 and 2 is also in subset 2. Hence, including this edge forms a cycle.
How subset of 0 is same as 2?
0->1->2 // 1 is parent of 0 and 2 is parent of 1  
Recommended: Please try your approach on {IDE} first, before moving on to the solution.

Based on the above explanation, below are implementations:

// A union-find algorithm to detect cycle in a graph

<!-- ================================================================ -->

#include <bits/stdc++.h>
using namespace std;

// a structure to represent an edge in graph
class Edge
{
public:
int src, dest;
};

// a structure to represent a graph
class Graph
{
public:
// V-> Number of vertices, E-> Number of edges
int V, E;

    // graph is represented as an array of edges
    Edge* edge;

};

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
Graph* graph = new Graph();
graph->V = V;
graph->E = E;

    graph->edge = new Edge[graph->E * sizeof(Edge)];

    return graph;

}

// A utility function to find the subset of an element i
int find(int parent[], int i)
{
if (parent[i] == -1)
return i;
return find(parent, parent[i]);
}

// A utility function to do union of two subsets
void Union(int parent[], int x, int y)
{
parent[x] = y;
}

// The main function to check whether a given graph contains
// cycle or not
int isCycle(Graph* graph)
{
// Allocate memory for creating V subsets
int* parent = new int[graph->V * sizeof(int)];

    // Initialize all subsets as single element sets
    memset(parent, -1, sizeof(int) * graph->V);

    // Iterate through all edges of graph, find subset of
    // both vertices of every edge, if both subsets are
    // same, then there is cycle in graph.
    for (int i = 0; i < graph->E; ++i) {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if (x == y)
            return 1;

        Union(parent, x, y);
    }
    return 0;

}

// Driver code
int main()
{
/_ Let us create the following graph
0
| \
 | \
 1---2 _/
int V = 3, E = 3;
Graph\* graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if (isCycle(graph))
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";

    return 0;

}

// This code is contributed by rathbhupendra

<!-- ================================================================ -->

Output:

graph contains cycle

<!-- ================================================================ -->

Note that the implementation of union() and find() is naive and takes O(n) time in the worst case. These methods can be improved to O(Logn) using Union by Rank or Height. We will soon be discussing Union by Rank in a separate post.
https://youtu.be/mHz-mx-8lJ8?list=PLqM7alHXFySEaZgcg7uRYJFBnYMLti-nh

Related Articles :
Union-Find Algorithm | Set 2 (Union By Rank and Path Compression)
Disjoint Set Data Structures (Java Implementation)
Greedy Algorithms | Set 2 (Kruskal’s Minimum Spanning Tree Algorithm)
Job Sequencing Problem | Set 2 (Using Disjoint Set)
This article is compiled by Aashish Barnwal and reviewed by GeeksforGeeks team. Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.
