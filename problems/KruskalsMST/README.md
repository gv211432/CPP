<!-- ┏━┓╻  ╻     ┏━┓┏┓ ┏━┓╻ ╻╺┳╸   ╻┏ ┏━┓╻ ╻┏━┓╻┏ ┏━┓╻  ┏━┓┏┳┓┏━┓╺┳╸
     ┣━┫┃  ┃     ┣━┫┣┻┓┃ ┃┃ ┃ ┃    ┣┻┓┣┳┛┃ ┃┗━┓┣┻┓┣━┫┃  ┗━┓┃┃┃┗━┓ ┃
     ╹ ╹┗━╸┗━╸   ╹ ╹┗━┛┗━┛┗━┛ ╹    ╹ ╹╹┗╸┗━┛┗━┛╹ ╹╹ ╹┗━╸┗━┛╹ ╹┗━┛ ╹  -->

Kruskal’s Minimum Spanning Tree Algorithm | Greedy Algo-2

    Difficulty Level : Hard
    Last Updated : 11 Feb, 2022

What is Minimum Spanning Tree?
Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a tree and connects all the vertices together. A single graph can have many different spanning trees. A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, undirected graph is a spanning tree with a weight less than or equal to the weight of every other spanning tree. The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.
How many edges does a minimum spanning tree has?
A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.
What are the applications of the Minimum Spanning Tree?
See this for applications of MST.

Below are the steps for finding MST using Kruskal’s algorithm

    1. Sort all the edges in non-decreasing order of their weight.
    2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
    3. Repeat step#2 until there are (V-1) edges in the spanning tree.

Step #2 uses the Union-Find algorithm to detect cycles. So we recommend reading the following post as a prerequisite.
Union-Find Algorithm | Set 1 (Detect Cycle in a Graph)
Union-Find Algorithm | Set 2 (Union By Rank and Path Compression)
The algorithm is a Greedy Algorithm. The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the MST constructed so far. Let us understand it with an example: Consider the below input graph.

The graph contains 9 vertices and 14 edges. So, the minimum spanning tree formed will be having (9 – 1) = 8 edges.

After sorting:

Weight Src Dest
1 7 6
2 8 2
2 6 5
4 0 1
4 2 5
6 8 6
7 2 3
7 7 8
8 0 7
8 1 2
9 3 4
10 5 4
11 1 7
14 3 5

Now pick all edges one by one from the sorted list of edges

1. Pick edge 7-6: No cycle is formed, include it.

Kruskal’s Minimum Spanning Tree Algorithm

2. Pick edge 8-2: No cycle is formed, include it.

Kruskal’s Minimum Spanning Tree Algorithm

3. Pick edge 6-5: No cycle is formed, include it.

Kruskal’s Minimum Spanning Tree Algorithm

4. Pick edge 0-1: No cycle is formed, include it.

Kruskal’s Minimum Spanning Tree Algorithm

5. Pick edge 2-5: No cycle is formed, include it.

Kruskal’s Minimum Spanning Tree Algorithm

6. Pick edge 8-6: Since including this edge results in the cycle, discard it.
7. Pick edge 2-3: No cycle is formed, include it.

Kruskal’s Minimum Spanning Tree Algorithm

8. Pick edge 7-8: Since including this edge results in the cycle, discard it.
9. Pick edge 0-7: No cycle is formed, include it.

Kruskal’s Minimum Spanning Tree Algorithm

10. Pick edge 1-2: Since including this edge results in the cycle, discard it.
11. Pick edge 3-4: No cycle is formed, include it.

Kruskal’s Minimum Spanning Tree Algorithm

Since the number of edges included equals (V – 1), the algorithm stops here.

Recommended: Please try your approach on {IDE} first, before moving on to the solution.

Below is the implementation of the above idea:

<!-- ===================================================================== -->

#include <bits/stdc++.h>
using namespace std;
// DSU data structure
// path compression + rank by union

class DSU {
int* parent;
int* rank;

public:
DSU(int n)
{
parent = new int[n];
rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }
    // union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

};

class Graph {
vector<vector<int> > edgelist;
int V;

public:
Graph(int V) { this->V = V; }

    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
    }

    void kruskals_mst()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());

        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // take that edge in MST if it does form a cycle
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }

};
int main()
{
/_ Let us create following weighted graph
10
0--------1
| \ |
6| 5\ |15
| \ |
2--------3
4 _/
Graph g(4);
g.addEdge(0, 1, 10);
g.addEdge(1, 3, 15);
g.addEdge(2, 3, 4);
g.addEdge(2, 0, 6);
g.addEdge(0, 3, 5);

    // int n, m;
    // cin >> n >> m;

    // Graph g(n);
    // for (int i = 0; i < m; i++)
    // {
    //     int x, y, w;
    //     cin >> x >> y >> w;
    //     g.addEdge(x, y, w);
    // }

    g.kruskals_mst();
    return 0;

}

<!-- ===================================================================== -->

Output

Following are the edges in the constructed MST
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Minimum Cost Spanning Tree: 19

<!-- ===================================================================== -->

Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time. The value of E can be at most O(V2), so O(LogV) is O(LogE) the same. Therefore, the overall time complexity is O(ElogE) or O(ElogV)
