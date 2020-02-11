#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, vector<int>& paths, vector<int>& discos)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < discos.size(); i++)
    {
        paths[discos[i]] = 0;
        q.push({ 0, discos[i] });
    }

    while (!q.empty())
    {
        int topEl = q.top().second;
        q.pop();

        if (!visited[topEl])
        {
            visited[topEl] = true;
            for (auto child : adj[topEl])
            {
                if (!visited[child.second])
                {
                    if (paths[topEl] + child.first < paths[child.second])
                    {
                        paths[child.second] = paths[topEl] + child.first;
                        q.push({ paths[child.second], child.second });
                    }
                }
            }
        }
    }
}

int main()
{
    int N;
    int M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N);
    int u, v, t;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> t;
        adj[u].push_back({ t, v });
        adj[v].push_back({ t, u });
    }

    int K;
    cin >> K;
    vector<int> discos(K);
    for (int i = 0; i < K; i++)
    {
        cin >> u;
        discos[i] = u;
    }

    vector<bool> visited(N);
    vector<int> paths(N, 1200000000);

    dijkstra(adj, visited, paths, discos);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> u;
        cout << paths[u] << '\n';
    }

    return 0;
}
