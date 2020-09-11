#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<vector<int>>& gb, int i, vector<bool>& visited, int& counter)
{
    visited[i] = true;
    counter++;
    for (auto i : gb[i])
    {
        if (!visited[i])
        {
            dfs(gb, i, visited, counter);
        }
    }
    return counter;
}

void componentsInGraph(vector<vector<int>> gb) {
    vector<bool> visited(gb.size(), false);
    int minn = 10000000;
    int maxx = 0;
    for (size_t i = 0; i < gb.size(); i++)
    {
        for (size_t j = 0; j < gb[i].size(); j++)
        {
            if (!visited[i])
            {
                int result = 0;
                dfs(gb, i, visited, result);
                if(result != 1)
                {
                    minn = min(minn, result);
                    maxx = max(maxx, result);
                }
            }
        }
    }
    cout << minn << " " << maxx << '\n';
}

int main()
{
    int n;
    cin >> n;
    int u, w;
    vector<vector<int>> gb(35000);
    for (int i = 0; i < n; i++)
    {
        cin >> u >> w;
        gb[u].push_back(w);
        gb[w].push_back(u);
    }
    componentsInGraph(gb);

    return 0;
}
