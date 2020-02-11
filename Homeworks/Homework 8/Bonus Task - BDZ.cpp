#include <stdio.h>
#include <vector>
#include <list>

#define MAX 1000000007

using namespace std;

void topoSortRec(vector<vector<int>>& gr, int v, vector<bool>& visited,
    vector<bool>& recStack, list<int>& l, bool& isCycle)
{
    visited[v] = true;
    recStack[v] = true;
    for (auto i : gr[v])
    {
        if (recStack[i])
        {
            isCycle = true;
            return;
        }
        else if (!visited[i])
            topoSortRec(gr, i, visited, recStack, l, isCycle);
    }
    l.push_back(v);
    recStack[v] = false;
}

void topoSort(vector<vector<int>>& adj, list<int>& l)
{
    int n = adj.size();
    vector<bool> recStack(n, 0);
    vector<bool> visited(n, 0);
    bool isCycle = false;

    for (int i = 1; i < n; i++)
    {
        if (!visited[i])
        {
            topoSortRec(adj, i, visited, recStack, l, isCycle);
            if (isCycle)
            {
                l = list<int>();
                return;
            }
        }
    }
}

int findNumberWays(int start, int end, vector<vector<int>>& adj)
{
    list<int> l;
    topoSort(adj, l);

    vector<int> res(adj.size());
    res[end] = 1;
    while(!l.empty())
    {
        for (int i = 0; i < adj[l.front()].size(); i++)
        {
            res[l.front()] += res[adj[l.front()][i]];
            if(res[l.front()] >= MAX)
                res[l.front()] %= MAX;
        }
        l.pop_front();
    }
    
    return res[start];
}

int main()
{
    int N;
    int M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> adj(N + 1);
    int u, v;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }
    int start, end;
    scanf("%d %d", &start, &end);

    int answer = findNumberWays(start, end, adj);
    printf("%d", answer);

    return 0;
}
