// concepts of the minimum spanning tree

// First of all lets understand what is a spanning tree.

// lets draw a graph

//  1 <------> 2
//  |          |
//  |          |
//  3 <------> 4

// Now from the above graph the spanning tree is the one which is
// connected and contains V-1 edges.
// And minimum spanning tree is the one whose sum is the minimum of all spanning trees.
// to find the minimum spanning tree we have two famous named algorithm which are
// 1.Prim's Algorithm.
// 2.Kruskal's Algorithm.
#include <bits/stdc++.h>
using namespace std;

//  code for the prims algorithm.
class Solution
{
    typedef pair<int, int> P;

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<P, vector<P>, greater<P>> pq;
        // pushing the (weight,node);
        vector<bool> inMst(V, false);
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {

            // take out the first node
            auto fn = pq.top();
            pq.pop();

            int node = fn.second;
            int wt = fn.first;

            if (inMst[node] == true)
            {
                continue;
            }
            inMst[node] = true;
            sum += wt;

            // now traverse the node and find its neighbours
            for (auto &v : adj[node])
            {
                int neighbor = v[0];
                int neighborWt = v[1];

                if (inMst[neighbor] == false)
                {
                    pq.push({neighborWt, neighbor});
                }
            }
        }
        return sum;
    }
};

int main()
{

    return 0;
}