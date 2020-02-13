#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>>& gr, int k)
{
    int start = gr.size() - 1;
    vector<bool> visited(gr.size());
    visited[start] = true;
    
    queue<pair<int, int>> q;
    q.push({0, start});
    
    vector<int> ans;
    while(!q.empty())
    {
        pair<int, int> topEl = q.front();
        q.pop();
        
        if(topEl.first == k)
            ans.push_back(topEl.second);
        else if(topEl.first > k)                   
            break;          
        
        for(auto i : gr[topEl.second])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push({topEl.first +1 , i});
            }
        }
    }
    
    if(!ans.empty())
    {
        sort(ans.begin(), ans.end());
        for(auto i : ans)        
           cout << i << " ";        
    }
    else
    {
        cout << -1;
    }    
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> gr(n+1);
    int u, v;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    
    bfs(gr, k);
    
    return 0;
}
