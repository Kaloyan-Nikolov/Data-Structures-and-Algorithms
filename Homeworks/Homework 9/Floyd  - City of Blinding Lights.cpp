#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

void dijkstra(vector<unordered_map<int, int>>& gr, int start, int end, vector<vector<pair<int, bool>>>& table)
{
    if(table[start][end].second)
    {        
        cout << table[start][end].first << "\n";       
    }
    else
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
        
            visited[topel.second] = true;
            for(auto i : gr[topel.second])
            {
                if(!visited[i.first] && paths[topel.second] + i.second < paths[i.first])
                {
                    paths[i.first] = i.second + paths[topel.second];
                    q.push({paths[i.first], i.first});
                }
            }        
        }
    
        for(int i = 1; i < paths.size(); i++)
        {
            if(paths[i] != INT_MAX)
                table[start][i] = {paths[i], true};  
            else
                table[start][i] = {-1, true};
        }
    
        if(paths[end] != INT_MAX)
            cout << paths[end] << "\n";
        else
            cout << -1 << "\n";        
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<unordered_map<int, int>> gr(n+1);
    int u, v, t;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> t;
        if(gr[u].count(v) == 0)
            gr[u][v] = t;
        else
        {
            gr[u].erase(v);
            gr[u][v] = t;
        }
    }
    
    vector<vector<pair<int, bool>>> table(n+1, vector<pair<int, bool>>(n+1, {-1, false}));
    
    int q;
    cin >> q;
    int start, end;
    for(int i = 0; i < q; i++)
    {
        cin >> start >> end;
        dijkstra(gr, start, end, table);
    }
    
    return 0;
}
