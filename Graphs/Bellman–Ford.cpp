#include <iostream>
#include <vector>

using namespace std;

#define inf 100000

void bellman(vector<vector<int>>& gr, int numV, int start)
{
	vector<int> paths(numV + 1, inf);
	paths[start] = 0;
	bool updated;

	int i;
	for (i = 0; i < numV; i++)
	{
		updated = false;
		for (int j = 0; j < gr.size(); j++)
		{
			if (paths[gr[j][0]] != inf && paths[gr[j][0]] + gr[j][2] < paths[gr[j][1]])
			{
				paths[gr[j][1]] = paths[gr[j][0]] + gr[j][2];
				updated = true;
			}
		}
		if (!updated)
			break;
	}

	if (updated && i == numV)
	{
		cout << "no min path\n";
	}
	else
	{
		for (int i = 1; i < paths.size(); i++)
		{
			if (i != start)
			{
				if (paths[i] == inf)
					cout << i << ": " << -1 << "\n";
				else
					cout << i << ": " << paths[i] << "\n";
			}
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(m);
	int v, w, t;
	for (int i = 0; i < m; i++)
	{
		cin >> v >> w >> t;
		edges[i] = { v, w, t };
	}
	int start;
	cin >> start;

	bellman(edges, n, start);

	return 0;
}

/*
7 10
3 1 2
3 4 2
4 1 -1
1 5 3
5 4 4
5 6 100
5 7 2
2 5 1
2 1 4
4 5 1
3
*/

/*
7 10
3 1 2
3 4 2
4 1 -1
1 5 -10
5 4 4
5 6 100
5 7 2
2 5 1
2 1 4
4 5 1
3
*/
