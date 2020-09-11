#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

void bfs(unordered_map<int, unordered_set<int>>& gr, int start = 0)
{
    unordered_set<int> visited;
    visited.insert(start);
    
    int sum = 0;
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty())
    {
        pair<int, int> topel = q.front();
        q.pop();
        
        for(auto i : gr[topel.second])
        {
            if(visited.count(i) == 0)
            {
                visited.insert(i);
                sum += topel.first + 1;
                q.push({topel.first + 1, i});
            }
        }
    }
    
    cout << sum;
}

int main() {
    int m;
    cin >> m;
    
    int a, b;
    unordered_map<int, unordered_set<int>> gr;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        gr[a].insert(b);
        gr[b].insert(a);
    }
    
    bfs(gr);
    
    return 0;
}
