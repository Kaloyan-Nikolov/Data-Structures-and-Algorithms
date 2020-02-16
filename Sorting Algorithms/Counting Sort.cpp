#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& v) 
{
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

void countingSort(vector<int>& v)
{
	int s = v.size();
	int minEl = v[0];
	int maxEl = v[0];

	for (int i = 0; i < s; i++)
	{
		if (minEl > v[i])
			minEl = v[i];
		if (maxEl < v[i])
			maxEl = v[i];
	}

	int range = maxEl - minEl + 1;
	vector<int> count(range, 0);

	for (int i = 0; i < s; i++)
	{
		count[v[i] - minEl]++;
	}

	for (int i = 0; i < range - 1; i++)
	{
		count[i + 1] += count[i];
	}

	vector<int> sorted(s);

	for (int i = s - 1; i >= 0; i--)
	{
		sorted[count[v[i] - minEl] - 1] = v[i];
		count[v[i] - minEl]--;
	}

	for (int i = 0; i < s; i++)
	{
		v[i] = sorted[i];
	}
}

void countingSort2(vector<int>& v)
{
	int s = v.size();
	int minEl = v[0];
	int maxEl = v[0];

	for (int i = 0; i < s; i++)
	{
		if (minEl > v[i])
			minEl = v[i];
		if (maxEl < v[i])
			maxEl = v[i];
	}

	int range = maxEl - minEl + 1;
	vector<int> count(range, 0);

	for (int i = 0; i < s; i++)
	{
		count[v[i] - minEl]++;
	}

	int k = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i] > 0)
		{
			v[k++] = i + minEl;
			count[i]--;
		}
	}
}

int main()
{
	vector<int> test2 = { 5, 0, 8, 0, -4, 12, 13, -1, 6, 7 };
	vector<int> test = { 3, -1 };
	countingSort(test2);
	print(test2);

	return 0;
}
