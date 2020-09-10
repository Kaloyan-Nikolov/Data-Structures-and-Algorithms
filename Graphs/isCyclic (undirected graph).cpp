#include <iostream>
#include <vector>

using namespace std;

bool isCyclicRec(vector<vector<int>>& adj, int v, int parent, vector<bool>& visited)
{
	visited[v] = true;
	for (auto child : adj[v])
	{
		if (visited[child] && child != parent)
			return true;
		else if (!visited[child] && isCyclicRec(adj, child, v, visited))
			return true;
	}

	return false;
}

bool isCyclic(vector<vector<int>>& adj)
{
	vector<bool> visited(adj.size());
	for (int i = 1; i < adj.size(); i++)
	{
		if (!visited[i] && isCyclicRec(adj, i, -1, visited))
			return true;
	}
	return false;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, w;
		cin >> u >> w;
		adj[u].push_back(w);
		adj[w].push_back(u);
	}

	bool hasCycles = isCyclic(adj);
	if (hasCycles)
		cout << "the graph is cyclic!\n";
	else
		cout << "not cyclic\n";

	return 0;
}

/*
4 4
1 2
2 4
1 3
3 4

4 3
3 4
2 4
1 2

6 6
1 2
2 3
3 4
1 5
3 6
5 6
*/
