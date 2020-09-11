#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void bfs(int n, int m, vector<vector<int>> edges, int s) 
{
    vector<bool> visited(edges.size(), false);
    vector<int> result(edges.size(), -1);
    queue<pair<int, int>> q;
    q.push({ 0, s });
    visited[s] = true;

    while (!q.empty())
    {
        pair<int, int> topEl = q.front();
        q.pop();

        for (auto i : edges[topEl.second])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                result[i] = topEl.first + 6;
                q.push({ topEl.first + 6, i });
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i != s)
            cout << result[i] << " ";
    }
    cout << '\n';
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < m; i++)
        {
            int p, t;
            cin >> p >> t;
            edges[p].push_back(t);
            edges[t].push_back(p);
        }
        int start;
        cin >> start;
        bfs(n, m, edges, start);
    }

    return 0;
}
