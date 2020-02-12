#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct cmp
{
    bool operator()(const vector<int>& a, const vector<int>& b) const
    {
        return a[0] < b[0];
    }
};

int find(int v, vector<int>& p)
{
    if(v == p[v])
        return v;
    return p[v] = find(p[v], p);
}

void Union(vector<int>& x, vector<int>& p, vector<int>& d, int& result)
{
    int r1 = find(x[1], p);
    int r2 = find(x[2], p);
    
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
        result += x[0];        
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> gr;
    gr.reserve(m);
    int u, v, t;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> t;
        gr.push_back({t, u, v});
    }
    
    vector<int> d(n+1, 0);
    vector<int> p(n+1);
    for(int i = 0; i < n+1; i++)
    {
        p[i] = i;
    }
    
    sort(gr.begin(), gr.end(), cmp());
    
    int result = 0;
    for(int i = 0; i < m; i++)
    {
        Union(gr[i], p, d, result);
    }   
    
    cout << result;    
    
    return 0;
}
