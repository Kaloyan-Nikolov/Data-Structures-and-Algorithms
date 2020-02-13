#include <vector>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& gr, int start)
{
    vector<bool> visited(gr.size());
    vector<int> paths(gr.size(), INT_MAX);
    paths[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});
    
    while(!q.empty())
    {        
        pair<int, int> topel = q.top();
        q.pop();
        
        if(!visited[topel.second])
        {
            visited[topel.second] = true;
            for(auto i : gr[topel.second])
            {
                if(!visited[i.second] && paths[topel.second] + i.first < paths[i.second])
                {
                    paths[i.second] = paths[topel.second] + i.first;
                    q.push({paths[i.second], i.second});
                }
            }
        }
    }
    
    for(int i = 1; i < paths.size(); i++)
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
    int u,v, t;
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
