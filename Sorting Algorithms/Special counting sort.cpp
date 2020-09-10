#include <iostream>
#include <vector>
using namespace std;

void myCountingSort(vector<int>& v)
{
	int s = v.size();
	int range = 10005;
	vector<int> count(range, 0);

	for (int i = 0; i < s; i++)
	{
		count[v[i]]++;
	}

	vector<int> sorted;
	for (int i = 0; i < range; i++)
	{
		if (count[i] > 0)
			sorted.push_back(i);
	}

	for (auto i : sorted) cout << i << " ";
	cout << '\n';
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

	myCountingSort(v);

	return 0;
}
