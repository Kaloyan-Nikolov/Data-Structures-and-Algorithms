#include <iostream>
#include <vector>

using namespace std;

int numSplits = 0;
int bs(vector<int>& v, int l, int r, int x)
{
	if (r < l)
		return -1;

	int m = (l + r) / 2;
	numSplits++;
	if (v[m] == x)
		return m;
	else if (v[m] > x)
		return bs(v, l, m - 1, x);
	else
		return bs(v, m + 1, r, x);
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int q;
	cin >> q;
	int temp;
	vector<int> ansIndexes(q);
	vector<int> ansSplits(q);
	for (int i = 0; i < q; i++)
	{
		cin >> temp;
		numSplits = 0;
		int res = bs(v, 0, n - 1, temp);
		ansIndexes[i] = res;
		ansSplits[i] = numSplits;
	}

	for (auto i : ansIndexes) cout << i << " ";
	cout << '\n';
	for (auto i : ansSplits) cout << i << " ";
	cout << '\n';

	return 0;
}
