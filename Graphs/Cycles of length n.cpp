#include <iostream>
#include <vector>
using namespace std;

// Number of vertices 
const int V = 5;

void DFS(vector<vector<bool>>& gr, vector<bool>& visited, int n,
	int vert, int start, int &count) {

	visited[vert] = true;

	// if the path of length (n-1) is found 
	if (n == 0)
	{
		visited[vert] = false;
		if (gr[vert][start])
			count++;

		return;
	}

	for (int i = 0; i < V; i++)
		if (!visited[i] && gr[vert][i])
			DFS(gr, visited, n - 1, i, start, count);

	visited[vert] = false;
}

int countCycles(vector<vector<bool>>& gr, int n)
{
	vector<bool> visited(V + 1);

	// Searching for cycle by using v-n+1 vertices // the graph is UNDIRECTED 
	int count = 0;
	for (int i = 0; i < V - (n - 1); i++)
	{
		DFS(gr, visited, n - 1, i, i, count);
		visited[i] = true;
	}

	return count / 2;
}

int main()
{
	vector<vector<bool>> gr = { {0, 1, 0, 1, 0},
				    {1, 0, 1, 0, 1},
				    {0, 1, 0, 1, 0},
				    {1, 0, 1, 0, 1},
				    {0, 1, 0, 1, 0} };

	int n = 4;
	cout << "Total cycles of length " << n << " are "
		<< countCycles(gr, n) << "\n";

	return 0;
}
