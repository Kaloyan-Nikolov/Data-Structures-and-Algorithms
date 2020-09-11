#include <iostream>
#include <vector>
using namespace std;

int inversions = 0;
void merge(vector<int>& v, int l, int m, int r)
{
	int s1 = m - l + 1;
	int s2 = r - m;

	vector<int> L(s1);
	vector<int> R(s2);

	for (int i = 0; i < s1; i++) L[i] = v[i + l];
	for (int i = 0; i < s2; i++) R[i] = v[i + m + 1];

	int i = 0; int j = 0; int k = l;

	while (i < s1 && j < s2)
	{
		if (L[i] < R[j])
		{
			v[k++] = L[i++];
		}
		else
		{
			v[k++] = R[j++];
			inversions += s1 - i;
		}
	}

	while (i < s1) v[k++] = L[i++];
	while (j < s2) v[k++] = R[j++];
}

void ms(vector<int>& v, int l, int r)
{
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		ms(v, l, mid);
		ms(v, mid + 1, r);
		merge(v, l, mid, r);
	}
}

int main()
{
	vector<int> test = { 5, 8, -3, 0, 2, 4, 1 };
	//vector<int> test2 = { 2, 4, 0, -1 };
	ms(test, 0, test.size() - 1);
	for (auto i : test) cout << i << " ";
	cout << endl << inversions << endl;

	return 0;
}
