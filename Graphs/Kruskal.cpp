#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<pair<int, pair<int, int>>> vpp;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int find(int v, vector<int>& parent)
{
	if (v == parent[v])
		return v;
	return parent[v] = find(parent[v], parent);
}

void Union(pair<int, pair<int, int>>& x, vector<int>& parent, vector<int>& depth, int& ans)
{
	int r1 = find(x.second.first, parent);
	int r2 = find(x.second.second, parent);

	if (r1 == r2)
	{
		return;
	}
	else
	{
		if (depth[r1] < depth[r2])
			swap(r1, r2);
		if (depth[r1] == depth[r2])
			depth[r1]++;
		parent[r2] = r1;
		ans += x.first;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	vpp gr;
	gr.reserve(m);
	vector<int> parent(n + 1);
	for (int i = 0; i < n + 1; i++)
		parent[i] = i;

	vector<int> depth(n + 1, 0);

	int v1, v2, w;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> w;
		gr.push_back({ w, {v1, v2} });
	}

	sort(gr.begin(), gr.end());

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		Union(gr[i], parent, depth, ans);
	}
	cout << ans << "\n";

	return 0;
}

/*
7 10
3 1 2
3 4 2
4 1 1
1 5 3
5 4 4
5 6 100
5 7 2
2 5 1
2 1 4
4 5 1
*/
