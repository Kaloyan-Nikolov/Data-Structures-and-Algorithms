#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& gr, int start)
{
    vector<bool> visited(gr.size(), 0);
    vector<int> paths(gr.size(), INT_MAX);
    paths[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while(!pq.empty())
    {
        pair<int, int> topel = pq.top();
        pq.pop();
        
        if(!visited[topel.second])
        {
            visited[topel.second] = true;
            for(auto i : gr[topel.second])
            {
                if(!visited[i.second] && paths[topel.second] + i.first < paths[i.second])
                {
                    paths[i.second] = paths[topel.second] + i.first;
                    pq.push({paths[i.second], i.second});                    
                }
            }
         }
    }
    
    for(int i = 1; i < (int)paths.size(); i++)
    {
        if(i != start)
        {
            if(paths[i] != INT_MAX)
                cout << paths[i] << " ";
            else
                cout << -1 << " ";
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> gr(n+1);
    int u, v, t;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> t;
        gr[u].push_back({t, v});
        gr[v].push_back({t, u});
    }
    int start;
    cin >> start;
    
    dijkstra(gr, start);
    return 0;
}
