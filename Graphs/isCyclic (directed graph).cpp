#include <iostream>
#include <vector>

using namespace std;

class DAG
{
public:
	vector<vector<int>> gr;
	vector<int> edges;

	DAG(int n)
	{
		gr.resize(n + 1);
		edges.resize(n + 1, 0);
	}

	void addEdge(int from, int to)
	{
		gr[from].push_back(to);
		edges[to]++;
	}

	bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack)
	{
		if (!visited[v])
		{
			visited[v] = true;
			recStack[v] = true;
			for (auto i : gr[v])
			{
				if (!visited[i] && isCyclicUtil(i, visited, recStack))
					return true;
				else if (recStack[i])
					return true;
			}
		}
		recStack[v] = false;
		return false;
	}

	bool isCyclic()
	{
		int n = gr.size();
		vector<bool> visited(n, false);
		vector<bool> recStack(n, false);
		for (int i = 0; i < n; i++)
			if (isCyclicUtil(i, visited, recStack))
				return true;
		return false;
	}
};

int main()
{
	int n; // number of vertexes;
	int m; // number of edges;
	cin >> n >> m;

	DAG dag(n);
	int p, t;
	for (int i = 0; i < m; i++)
	{
		cin >> p >> t;
		dag.addEdge(p, t);
	}

	if (dag.isCyclic())
		cout << "The graph is cyclic, it is NOT DAG!";
	else
		cout << "The graph is NOT cyclic, it is DAG!";

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
