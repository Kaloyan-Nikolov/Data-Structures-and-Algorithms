#include <vector>
#include <iostream>
using namespace std;

vector<bool> visited;
int dfs(int v, int& result, vector<vector<int>>& adj)
{
    visited[v] = 1;
    int components = 1;
    for (auto i : adj[v])
    {
        if (!visited[i])
        {
            int subtreenodecount = dfs(i, result, adj);
            if (subtreenodecount % 2 == 0)
                result++;
            components += subtreenodecount;
        }
    }
    return components;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V + 1);
    int a, b;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int result = 0;
    visited.assign(adj.size(), 0);
    dfs(1, result, adj);
    cout << result << '\n';

    return 0;
}
