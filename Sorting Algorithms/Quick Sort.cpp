#include <iostream>
#include <vector>
//#include <ctime>

using namespace std;

int partition(vector<int>& v, int l, int r)
{
	int middle = l + (r - l) / 2;
	swap(v[middle], v[r]);
	//int randIndex = start + rand() % ((end - start) + 1);
	//swap(v[randIndex], v[r]);
	int pi = v[r];
	int piIndex = l;

	for (int i = l; i < r; i++)
	{
		if (v[i] < pi) // place all elements smaller than the pivot on the left;
		{
			swap(v[piIndex++], v[i]);
		}
	}

	swap(v[piIndex], v[r]); // place pi (pivot element) on the correct place;
	return piIndex;
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

int main()
{
	// srand((size_t)time(0));
	vector<int> vec = { 52, 31, 48, 0, -29, 8, 18, -14, 5, 4, 3 ,3 , 19, 9, 33, 14, 49, 27 };
	quickSort(vec, 0, vec.size() - 1);

	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
