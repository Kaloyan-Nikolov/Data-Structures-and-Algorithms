#include <vector>
#include <iostream>
using namespace std;

int partition(vector<int> &v, int l, int r)
{
	int mid = l + (r - l) / 2;
	swap(v[mid], v[r]);
	int pi = v[r];
	int piInd = l;
	for (int i = l; i < r; i++)
	{
		if (v[i] < pi)
			swap(v[piInd++], v[i]);
	}
	swap(v[piInd], v[r]);
	return piInd;
}

void quickSort(vector<int>& v, int l, int r)
{
	if (l < r)
	{
		int pivot = partition(v, l, r);
		quickSort(v, l, pivot - 1);
		quickSort(v, pivot + 1, r);
	}
}

void doExist(vector<int>&v)
{
	int s = (int)v.size();
	int r = s - 1;
	int l = 0;
	for (int i = 0; i < s; i++)
	{
		r = s - 1;
		l = 0;
		while (l < r)
		{
			if (v[l] + v[r] == v[i])
			{
				cout << "true" << endl;
				return;
			}
			else if (v[l] + v[r] > v[i])
				r--;
			else
				l++;
		}
	}

	cout << "false" << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> prod(n);
	for (int i = 0; i < n; i++)
	{
		cin >> prod[i];
	}

	quickSort(prod, 0, n - 1);
	doExist(prod);

	return 0;
}
