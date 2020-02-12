#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find(int v, vector<int>& p)
{
    if(v == p[v])
        return v;
    return p[v] = find(p[v], p);
}

void Union(pair<int, int>& x, vector<int>& p, vector<int>& d)
{
    int r1 = find(x.first, p);
    int r2 = find(x.second, p);
    
    if(r1 == r2)
    {
        return;
    }
    else
    {
        if(d[r1] < d[r2])
            swap(r1, r2);
        if(d[r1] == d[r2])
            d[r1]++;
        p[r2] = r1;        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> gr;
    gr.reserve(m);
    int u, v, t;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        gr.push_back({u,v});        
    }
    
    vector<int> p(n+1);
    for(int i = 0; i < n+1; i++)
    {
        p[i] = i;
    }
    vector<int> d(n+1, 0);
    
    sort(gr.begin(), gr.end());    
    
    for(int i = 0; i < m; i++)
    {
        Union(gr[i], p, d);
    }
    
    int q;
    cin >> q;
    int code;
    for(int i = 0; i < q; i++)
    {
        cin >> code;
        int x, y;
        cin >> x >> y;
        if(code == 1) // question
        {
           cout << (find(x, p) == find(y, p));
        }
        else if(code == 2) // add
        {
            pair<int, int> newP = {x, y};
            Union(newP, p, d); 
        }
    }
    
    return 0;
}
