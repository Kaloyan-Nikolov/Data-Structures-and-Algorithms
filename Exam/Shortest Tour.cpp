#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int counterPath = 0;
bool isfound = false;
void bfs(vector<vector<int>>& gr, vector<bool>& visited, vector<bool>& inaccessible, int start, int end)
{
    visited.assign(gr.size(), false);
    visited[start] = true;
    queue<int> q;
    q.push(start);    
    
    int tempSize = 1;
    while(!q.empty())
    {
        int topEl = q.front();
        q.pop();
        tempSize--;
        
        if(topEl != end && tempSize == 0)
        {
            counterPath++;           
        }
        else if (topEl == end)
        {            
            isfound = true;
            return;
        }        
        
        for(auto i : gr[topEl])
        {            
            if(!visited[i] && !inaccessible[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }  
        
        if(!tempSize)
        {
            tempSize = q.size();
        }        
    }    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n+1);
    int a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        gr[a].push_back(b);
    }    
    
    int q;
    cin >> q;
    vector<int> way(q);
    vector<bool> visited(gr.size());
    vector<bool> inaccessible(gr.size());
    int c;
    for(int i = 0; i < q; i++)
    {
        cin >> c;
        way[i] = c;
        inaccessible[c] = true;
    }    
    
    inaccessible[way[0]] = false;
    inaccessible[way[1]] = false;
    for(int i = 0; i < way.size() - 1; i++)
    {
        isfound = false;
        bfs(gr, visited, inaccessible, way[i], way[i+1]);
        if(!isfound)
        {
            cout << -1;
            return 0;
        }
        inaccessible[way[i+2]] = false;
    }
    
    cout << counterPath; 
    
    return 0;
}
