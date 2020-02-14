#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> gr(n+1, vector<int>(n+1, -1));
    int a, b, t;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        gr[a][b] = t;
        gr[b][a] = t;        
    }
    
    int k;
    cin >> k;
    long long lenPath = 0;
    
    vector<int> searchedPath;
    int u;
    for(int i = 0; i < k; i++)
    {
        cin >> u;
        searchedPath.push_back(u);
    }
    
    if(searchedPath.size() < 2)
    {
        cout << -1;
        return 0;
    }

    int x = searchedPath[0];
    int y = searchedPath[1];
    
    for(int i = 0; i < k-1; i++)
    {        
        if(gr[x][y] != -1)
            lenPath += gr[x][y];
        else
        {
            cout << -1;
            return 0;
        }
        x = y;
        y = searchedPath[i+2];        
    }
    cout << lenPath; 
    
    return 0;
}
