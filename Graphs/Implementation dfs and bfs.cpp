#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
public:
	vector<vector<int>> gr;
	vector<bool> visited;
	//int numEdges;

	//vector<vector<pair<int, int>>> G; // first - distance, second - number of node;

	Graph(int numberVertexes)
	{
		gr.resize(numberVertexes + 1);
		visited.assign(numberVertexes + 1, false);
		//G.resize(numberVertexes + 1);
		//numEdges = 0;
	}

	void addEdge(int u, int v)
	{
		gr[u].push_back(v);
		gr[v].push_back(u);
		//numEdges++;
	}

	void clearVisited()
	{
		visited.assign(gr.size(), false);
	}

	void dfs(int v)
	{
		cout << "visited: " << v << '\n';
		visited[v] = true;

		for (auto child : gr[v])
		{
			if (!visited[child])
			{
				dfs(child);
			}
		}
	}

	void bfs(int v)
	{
		queue<int> Q;
		Q.push(v);
		visited[v] = true;

		while (!Q.empty())
		{
			int topEl = Q.front();
			Q.pop();

			cout << "visited: " << topEl << '\n';

			for (auto child : gr[topEl])
			{
				if (!visited[child])
				{
					Q.push(child);
					visited[child] = true;
				}
			}
		}
	}

	void bfsLevel(int v, int level)
	{
		queue<int> Q;
		Q.push(v);
		visited[v] = true;

		int currLevel = 0;
		int tempSize = 1;
		while (!Q.empty())
		{
			int topEl = Q.front();
			Q.pop();
			tempSize--;

			if (currLevel == level)
				cout << "visited: " << topEl << '\n';

			for (auto child : gr[topEl])
			{
				if (!visited[child])
				{
					Q.push(child);
					visited[child] = true;
				}
			}

			if (tempSize == 0)
			{
				tempSize = Q.size();
				currLevel++;
			}
		}
	}
};

int main()
{
	int n; // number of vertexes;
	int m; // number of edges;
	cin >> n >> m;

	Graph G(n);
	int u, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> w;
		G.addEdge(u, w);
	}

	cout << "Depth First Search:\n";
	G.dfs(4);
	G.clearVisited();

	cout << "\nBreadth First Search:\n";
	G.bfs(4);
	G.clearVisited();

	cout << "\nBreadth First Search - print only nodes at level 2:\n";
	G.bfsLevel(4, 2);
	G.clearVisited();

	return 0;
}


/*
8 8
1 2
3 6
2 3
1 4
5 3
4 3
7 8
6 5

4 3
1 2
2 4
3 4
*/
