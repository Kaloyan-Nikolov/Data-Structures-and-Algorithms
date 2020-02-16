#include <iostream>
#include <vector>
using namespace std;

int binarysearchIterative(vector<int>& v, int l, int r, int x)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (v[m] == x)
			return m; // we have found the index of x;
		if (v[m] > x) // search in left half
			r = m - 1;
		else // search in right half
			l = m + 1;
	}
	return -1; // if the element do NOT exist;
}

int binarySearchRecursive(vector<int>& v, int l, int r, int x)
{
	if (r < l) return -1; // base condition

	int m = l + (r - l) / 2;

	if (v[m] == x)
		return m;  // we have found the index of x;
	if (v[m] > x)  // search in left half
		return binarySearchRecursive(v, l, m - 1, x);
	else		   // search in right half
		return binarySearchRecursive(v, m + 1, r, x);
}

int binSearch_Leftmost_Rightmost_Iterative(vector<int>& v, int l, int r, int x)
{
	int result = -1;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (v[m] == x)
		{
			result = m;
			//r = m - 1;	// FOR LEFTMOST	 // search in left half for another answer;
			l = m + 1;	// FOR RIGHTMOST // search in right half for another answer;
		}
		else if (v[m] > x)      // search in left half for answer;
			r = m - 1;
		else			// search in right half for answer;
			l = m + 1;
	}
	return result;
}

int binSearch_Leftmost_Recursive(vector<int>& v, int l, int r, int x)
{
	if (r < l) return -1;
	int m = l + (r - l) / 2;
	if ((m == 0 || v[m - 1] < x) && v[m] == x)	// LEFTMOST	 // m is first index or previous element is smaller	
		return m;
	if (v[m] >= x)  // search in left half // !!! >=
		return binSearch_Leftmost_Recursive(v, l, m - 1, x);
	else		   // search in right half
		return binSearch_Leftmost_Recursive(v, m + 1, r, x);
}

int binSearch_Rightmost_Recursive(vector<int>& v, int l, int r, int x)
{
	if (r < l) return -1;
	int m = l + (r - l) / 2;
	if ((m == ((int)v.size() - 1) || x < v[m + 1]) && v[m] == x)	// RIGHTMOST // m is last index or next element is bigger
		return m;
	if (v[m] > x)  // search in left half
		return binSearch_Rightmost_Recursive(v, l, m - 1, x);
	else		   // search in right half
		return binSearch_Rightmost_Recursive(v, m + 1, r, x);
}

// if x is occurring multiple times - it returns its LEFTMOST index
// if x is missing it returns the smallest number BIGGER than x if such number exists;
int binSearch_upperBound(vector<int>& v, int l, int r, int x)
{
	while (l < r)
	{
		int m = l + (r - l) / 2;
		if (x > v[m])		// search in right half
			l = m + 1;
		else
			r = m;
	}
	if (v[l] >= x)
		return l;	// v[l] ако искаме самия елемент а не индекса
	else
		return -1;
}

// if x is occurring multiple times - it returns its RIGHTMOST index
// if x is missing it returns the biggest number SMALLER than x if such number exists;
int binSearch_lowerBound(vector<int>& v, int l, int r, int x)
{
	while (l < r)
	{
		int m = l + (r - l + 1) / 2;
		if (x >= v[m])
			l = m;
		else
			r = m - 1;
	}
	if (v[l] <= x)
		return l;
	else
		return -1;
}

int jumpSearch_Leftmost(vector<int>& v, int x)
{
	int s = (int)v.size();
	int step = sqrt(s);
	int curr = step;
	int prevStep = 0;

	// finds in which part of the vector is x;
	while (curr < s && v[curr] < x)
	{
		prevStep = curr;
		curr += step;
	}

	int i = prevStep;

	//find the exact LEFTMOST index (if x ocurrs in the vector)
	while (i < s && v[i] < x)
	{
		if (i + 1 >= s) break;
		else
			i++;
	}

	if (v[i] == x)
		return i;
	else
		return -1;
}

int jumpSearch_Rightmost(vector<int>& v, int x)
{
	int s = (int)v.size();
	int step = sqrt(s);
	int curr = step;
	int prevStep = 0;

	// finds in which part of the vector is x;
	while (curr < s && v[curr] <= x)
	{
		prevStep = curr;
		curr += step;
	}

	int i = prevStep;

	//find the exact RIGHTMOST index (if x ocurrs in the vector)
	while (i < s && v[i] <= x)
	{
		if (i + 1 >= s) break;
		if (i + 1 < s && v[i + 1] > x) break;
		else
			i++;
	}

	if (v[i] == x)
		return i;
	else
		return -1;
}

int ternarySearch(vector<int>& v, int l, int r, int x)
{
	if (r >= l)
	{
		int m1 = (2 * l + r) / 3;
		int m2 = (l + 2 * r) / 3;

		if (v[m1] == x) return m1;
		if (v[m2] == x) return m2;

		if (v[m1] > x)
			return ternarySearch(v, l, m1 - 1, x);
		else if (v[m2] > x)
			return ternarySearch(v, m1 + 1, m2 - 1, x);
		else
			return ternarySearch(v, m2 + 1, r, x);
	}
	return -1;
}

int partition(vector<int> &v, int l, int r)
{
	int middle = l + (r - l) / 2;
	swap(v[middle], v[r]);
	int pi = v[r];
	int piInd = l;
	for (int i = l; i < r; i++)
	{
		if (v[i] < pi) // if (v[i] > pi) we find k-th biggest number
		{
			swap(v[i], v[piInd++]);
		}
	}
	swap(v[piInd], v[r]);
	return piInd;
}

// finds the k-th smallest/biggest element - works for unsorted array as well;
void quickSelect(vector<int> &v, int l, int r, int k)
{
	int pivot = partition(v, l, r);
	if (pivot == k)
	{
		cout << "Answer: " << v[k] << endl;
		return;
	}
	else if (pivot > k)
	{
		quickSelect(v, l, pivot - 1, k);
	}
	else
	{
		quickSelect(v, pivot + 1, r, k);
	}
}

int main()
{
	vector<int> test = { -3, 2, 4, 4, 4, 4, 5, 9, 9, 9, 9, 12 };
	//vector<int> p = { 0, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10, 10, 11, 12 };
	//int result = binarysearchIterative(test, 0, test.size() - 1, 5);
	//int result2 = binSearch_lowerBound(test, 0, test.size() - 1, 9);
	//int result3 = jumpSearch_Leftmost(test, 9);
	//cout << result2 << endl;

	quickSelect(test, 0, test.size() - 1, 2);

	return 0;
}
