// Performing graph traversals technique
// There are two traversals technique BFS,DFS
// traversal technique is a technique in which we traverse or print the graph nodes in some order.
#include <bits/stdc++.h>
using namespace std;


// prepared adjacency list for the nodes and there neighbours.
void prepareAdj(unordered_map<int, list<int>> &adj, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> Q;
    Q.push(node);
    visited[node] = true;
    while (!Q.empty())
    {
        int frontNode = Q.front();
        Q.pop();
        ans.push_back(frontNode);
        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                Q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int>> adj;
    vector<int> ans;                  // the final array we are getting.
    unordered_map<int, bool> visited; // keep track of the nodes which have been visited

    prepareAdj(adj, edges);

    // calling the bfs function for all the nodes if not visited

    // the below for loop will also be handling the disconnected graph.
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adj, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    int vertex = 6; // Example: Number of vertices in the graph
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 4}, {3, 5}, {4, 5}}; // Example: List of edges in the graph

    vector<int> result = BFS(vertex, edges); // Calling BFS function to perform graph traversal

    // Printing the result
    cout << "BFS Traversal: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
