#include <vector>
#include <iostream>

using namespace std;

int dfs(int v, int& result, vector<bool>& visited, vector<vector<int>>& gr)
{
    visited[v] = 1;
    int comp = 1;
    for (auto i : gr[v])
    {
        if (!visited[i])
        {
            int nodes = dfs(i, result, visited, gr);
            if (nodes % 2 == 0)
                result++;
            comp += nodes;
        }
    }
    return comp;
}

int main() {
    int V, E; 
    cin >> V >> E;
    
    vector<vector<int>> gr(V+1);
    int u, v;
    for(int i = 0; i < E; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    int result = 0;
    vector<bool> visited(gr.size());   
    dfs(1, result, visited, gr);
    
    cout << result << '\n';
    
    return 0;
}
