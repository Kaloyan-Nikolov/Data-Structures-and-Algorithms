#include <iostream>
#include <vector>
using namespace std;

unsigned long long inversions = 0;

void merge(vector<int>& v, vector<int>& L, vector<int>& R)
{
	int sizeLeft = (int)L.size();
	int sizeRight = (int)R.size();

	int i = 0; // index of L
	int j = 0; // index of R
	int k = 0; // index of v

	while (i < sizeLeft && j < sizeRight)
	{
		if (L[i] < R[j])
		{
			v[k++] = L[i++];
			inversions += sizeLeft - i;
		}
		else
		{
			v[k++] = R[j++];
		}
	}
	while (i < sizeLeft) v[k++] = L[i++];
	while (j < sizeRight) v[k++] = R[j++];
}

void mergeSort(vector<int>& v)
{
	int s = (int)v.size();

	if (s < 2)
		return;

	int mid = s / 2;

	vector<int> L(mid); // L[0,1...mid-1]
	vector<int> R(s - mid); //R[mid,mid+1,...s-1];
	int i;
	for (i = 0; i < mid; i++) L[i] = v[i];
	for (i = mid; i < s; i++) R[i - mid] = v[i];

	mergeSort(L);  // sort left subarray
	mergeSort(R);  // sort right subarray
	merge(v, L, R);  // merging L and R into one vector - v;
}

int main()
{
	vector<int> test = { 5, 0, 4, -2, 17, 8, 3, 4, -6, 5, 9 };
	mergeSort(test);
	for (auto i : test) cout << i << " ";
	cout << '\n' << inversions;

	return 0;
}
