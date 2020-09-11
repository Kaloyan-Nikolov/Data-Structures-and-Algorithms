#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& gr, int start)
{
    vector<int> visited(gr.size(), false);
    queue<pair<int, int>> q;
    q.push({0, start});
    visited[start] = true;
    int sum = 0;
    
    while(!q.empty())
    {
        pair<int, int> topEl = q.front();
        q.pop();
        
        for(auto i : gr[topEl.second])
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push({topEl.first + 1, i});
                sum += topEl.first + 1;
            }
        }
    }
    cout << sum << '\n';
}


int main() 
{
    int n, u, v;
    cin >> n;
    vector<vector<int>> gr(n+1);
    for(int i = 0; i < n; i++)
    {
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    bfs(gr, 0);
    
    return 0;
}
