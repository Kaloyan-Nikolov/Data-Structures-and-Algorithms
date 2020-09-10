#include <iostream>
#include <vector>

using namespace std;

void countPathsUtil(vector<vector<int>>& gr, int v, int end, vector<bool>& visited, int &pathCount)
{
	visited[v] = true;

	if (v == end)
		pathCount++;
	else
	{
		for (auto i : gr[v])
			if (!visited[i])
				countPathsUtil(gr, i, end, visited, pathCount);
	}

	visited[v] = false;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> gr(n + 1);
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		gr[a].push_back(b);
	}
	int start, end;
	cin >> start >> end;

	vector<bool> visited(gr.size());

	int pathCount = 0;
	countPathsUtil(gr, start, end, visited, pathCount);
	cout << pathCount << '\n';

	return 0;
}

/*
4 6
0 1
0 2
0 3
2 0
2 1
1 3
2 3

5 7
1 2
1 3
1 5
2 4
2 5
3 5
4 3
1 5

5 7
1 2
1 3
1 5
2 4
2 5
3 5
4 3
5 1
*/
