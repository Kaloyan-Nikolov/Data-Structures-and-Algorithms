#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define inf 100000

void dijkstra(vector<vector<pair<int, int>>>& gr, int start)
{
	vector<bool> visited(gr.size());
	vector<int> paths(gr.size(), inf);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, start });
	paths[start] = 0;

	while (!q.empty())
	{
		pair<int, int> topEl = q.top();
		q.pop();

		if (!visited[topEl.second])
		{
			visited[topEl.second] = true;
			for (auto i : gr[topEl.second])
			{
				if (!visited[i.second])
				{
					if (paths[topEl.second] + i.first < paths[i.second])
					{
						paths[i.second] = paths[topEl.second] + i.first;
						q.push({ paths[i.second], i.second });
					}
				}
			}
		}
	}

	for (int i = 1; i < paths.size(); i++)
	{
		if (i != start)
		{
			if (paths[i] == inf)
				cout << -1 << " ";
			else
				cout << paths[i] << " ";
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> gr(n + 1);
	int v, w, t;
	for (int i = 0; i < m; i++)
	{
		cin >> v >> w >> t;
		gr[v].push_back({ t, w });
		gr[w].push_back({ t, v });
	}
	int start;
	cin >> start;

	dijkstra(gr, start);

	return 0;
}

/* start is 3
9 9
3 8 7
3 6 2
1 3 1
8 7 1
2 7 10
6 7 1
5 7 2
4 8 4
4 5 1
3
*/

