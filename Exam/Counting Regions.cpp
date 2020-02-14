#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& gr, vector<bool>& visited, int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    
    while(!q.empty())
    {
        int topEl = q.front();
        q.pop();
        
        for(auto i : gr[topEl])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() 
{    
    int t, n, m;
    cin >> t;
    for(int k = 0; k < t; k++)
    {    
        cin >> n >> m;
        vector<vector<int>> gr(n+1);
        int a, b;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
    
        int cnt = 0;
        vector<bool> visited(gr.size());
        for(int i = 0; i < gr.size() - 1; i++)
        {
            if(!visited[i])
            {
                bfs(gr, visited, i);
                cnt++;
            }            
        }
        cout << cnt << " ";
    }
    
    return 0;
}
