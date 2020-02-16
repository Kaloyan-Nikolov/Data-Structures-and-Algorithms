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

void bubbleSort(vector<int>& v)
{
	int s = (int)v.size();
	for (int i = 0; i < s - 1; i++)
	{
		for (int j = 0; j < s - i - 1; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

void bubbleSortOpt(vector<int>& v)
{
	int s = v.size();
	for (int i = 0; i < s; i++) {
		bool swapped = false;

		for (int j = 0; j < s - 1 - i; j++)
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				swapped = true;
			}

		if (!swapped)
			break;
	}
}

void selectionSort(vector<int>& v)
{
	int s = (int)v.size();
	int min;
	for (int i = 0; i < s; i++)
	{
		min = i;
		for (int j = i + 1; j < s; j++)
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		swap(v[min], v[i]);
	}
}

void insertionSort(vector<int>& v)
{
	int s = (int)v.size();
	for (int i = 1; i < s; i++)
		for (int k = i; k > 0 && v[k] < v[k - 1]; k--)
			swap(v[k], v[k - 1]);
}

int main()
{
	vector<int> test = { 5, 12, 0, -1, 4, 3, -3, 7, -1, 8 };
	vector<int> test2 = { 8, 2, 6, 7, 3 };
	//bubbleSort(test);
	bubbleSortOpt(test2);
	//selectionSort(test);
	//insertionSort(test);
	print(test2);

	return 0;
}
