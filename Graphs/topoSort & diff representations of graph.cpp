#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topoSortRec(vector<vector<int>>& gr, int v, vector<bool>& visited,
	vector<bool>& recStack, stack<int>& s, bool& isCycle)
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
			topoSortRec(gr, i, visited, recStack, s, isCycle);
	}
	s.push(v);
	recStack[v] = false;
}

stack<int> topoSort(vector<vector<int>>& adj)
{
	int n = adj.size();
	//vector<int> result;
	stack<int> s;
	vector<bool> recStack(n, 0);
	vector<bool> visited(n, 0);
	bool isCycle = false;

	for (int i = 1; i < n; i++)
	{
		if (!visited[i])
		{
			topoSortRec(adj, i, visited, recStack, s, isCycle);
			if (isCycle)
			{
				return stack<int>();
			}
		}
	}

	/*while (!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	}*/
	return s;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;

	//adjacency matrix
	vector<vector<bool>> matrix(n + 1, vector<bool>(n + 1, false));
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		matrix[a][b] = 1;
	}
	
	//from adjacency matrix to adjacency list
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++)
		{
			if (matrix[i][j])
			{
				adj[i].push_back(j);
			}
		}
	}

	//// list of edges;
	//vector<vector<int>> edgeList;
	//int u, w;
	//for (int i = 0; i < m; i++)
	//{
	//	cin >> u >> w;
	//	edgeList.push_back({ u,w });
	//}
	//
	//// from list of edges to adjacency list
	//vector<vector<int>> adj(n + 1);
	//int p, t;
	//for (int i = 0; i < edgeList.size(); i++)
	//{
	//	p = edgeList[i][0];
	//	t = edgeList[i][1];
	//	adj[p].push_back(t);
	//}

	stack<int> result = topoSort(adj);

	if (result.empty())
		cout << "graph is cyclic!\n";

	while (!result.empty())
	{
		cout << result.top() << " ";
		result.pop();
	}
	cout << '\n';

	return 0;
}

/*
8 6
2 3
1 2
3 6
1 4
5 3
7 8

4 5
1 2
2 1
2 4
3 4
1 3

4 4
2 1
2 3
3 4
4 2
*/
