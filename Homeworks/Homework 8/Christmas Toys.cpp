#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <iterator>

using namespace std;

void dfs(int start, unordered_set<int>& visited, unordered_map<int, unordered_set<int>>& adj)
{
    visited.insert(start);
    for (auto i : adj[start])
    {
        if (!visited.count(i))
        {
            visited.insert(i);
            dfs(i, visited, adj);
        }
    }
}

int main()
{
    int N;
    int M;
    cin >> N >> M;
    unordered_map<int, unordered_set<int>> adj;
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    int result = N;
    int dfsCnt = 0;
    unordered_set<int> visited;
    auto it = adj.begin();
    while(it != adj.end())
    {
        if (!visited.count(it->first))
        {
            dfs(it->first, visited, adj);
            dfsCnt++;
        }
        it++;
    }

    result = N - (adj.size() - dfsCnt);    
    cout << result;

    return 0;
}
