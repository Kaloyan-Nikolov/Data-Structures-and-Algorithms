#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <string>

using namespace std;

list<string> result;
unordered_set<string> recStack;
unordered_set<string> visited;

void dfs(const string& s, const string& start, unordered_map<string, unordered_set<string>>& adj, bool& shouldStop)
{
    for (auto i : adj[s])
    {
        if (!recStack.count(i) && !visited.count(i))
        {
            result.push_back(i);
            recStack.insert(i);
            if (i == start)
            {
                shouldStop = true;
                return;
            }
            dfs(i, start, adj, shouldStop);
        }
    }
    if (!shouldStop)
    {
        result.pop_back();
        recStack.erase(s);
        visited.insert(s);
    }
}

int main()
{
    int N;
    int M;
    cin >> N >> M;
    unordered_map<string, unordered_set<string>> adj;
    string from, to;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to;
        adj[from].insert(to);
    }
    string start;
    cin >> start;

    result.push_back(start);    
    bool shouldStop = false;
    dfs(start, start, adj, shouldStop);
    if (result.empty())
    {
        cout << -1;
    }
    else
    {
        int cnt = 0;
        while (!result.empty() && cnt != 2)
        {
            cout << result.front() << " ";
            if (result.front() == start)
                cnt++;
            result.pop_front();
        }
    }
    return 0;
}
