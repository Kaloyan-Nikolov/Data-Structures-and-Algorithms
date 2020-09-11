#include <iostream>
#include <vector>
using namespace std;

void toposortRec(vector<vector<int>>& gr, int start, vector<bool>& visited, vector<bool>& recStack, bool& isCyclic)
{
    visited[start] = true;
    recStack[start] = true;    
    for(auto i : gr[start])
    {
        if(recStack[i])
        {
            isCyclic = true;
            return;
        }
        else if(!visited[i])
        {
            toposortRec(gr, i, visited, recStack, isCyclic);
        }
    }    
    recStack[start] = false;
}

void toposort(vector<vector<int>>& gr)
{
    int n = gr.size();
    vector<bool> visited(n, 0);
    vector<bool> recStack(n, 0);
    bool isCyclic = false;
    // no stack to store toposort needed
    
    for(int i = 1; i < n; i++)
    {
        if(!visited[i])
        {
            toposortRec(gr, i, visited, recStack, isCyclic);
            if(isCyclic)
            {
                cout << "true ";
                return;
            }
                
        }
    }
    cout << "false ";
}

int main() {
    int q;
    cin >> q;
    while(q--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> gr(n+1);
        int u, v, t;
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> t;
            gr[u].push_back(v);
        }
        
        toposort(gr);
    }
    return 0;
}
