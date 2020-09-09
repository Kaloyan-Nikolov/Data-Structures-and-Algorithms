#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
	vector<int> arr;
public:

	MaxHeap()
	{
		arr.reserve(100);
	}

	int parent(int ind)
	{
		return (ind - 1) / 2;
	}

	int left(int ind)
	{
		return ind * 2 + 1;
	}

	int right(int ind)
	{
		return ind * 2 + 2;
	}

	bool hasLeft(int ind)
	{
		return left(ind) < (int)arr.size();
	}

	bool hasRight(int ind)
	{
		return right(ind) < (int)arr.size();
	}

	void siftUp(int ind)
	{
		if (ind == 0)
		{
			return;
		}

		if (arr[parent(ind)] < arr[ind]) // > for minHeap
		{
			swap(arr[parent(ind)], arr[ind]);
			siftUp(parent(ind));
		}
	}

	void siftDown(int ind)
	{
		if (!hasLeft(ind))
		{
			return;
		}

		int indMaxValueChild = left(ind);
		if (hasRight(ind) && arr[right(ind)] > arr[left(ind)]) // < for minHeap
		{
			indMaxValueChild = right(ind);
		}

		if (arr[ind] < arr[indMaxValueChild]) // > for minHeap
		{
			swap(arr[ind], arr[indMaxValueChild]);
			siftDown(indMaxValueChild);
		}
	}

	void push(int val)
	{
		arr.push_back(val);
		siftUp(arr.size() - 1);
	}

	void pop()
	{
		int size = arr.size();
		if (size == 0)
		{
			return;
		}
		swap(arr[0], arr[size - 1]);
		arr.pop_back();
		siftDown(0);
	}

	int top()
	{
		if (arr.size() == 0)
		{
			return -1;
		}
		return arr[0];
	}

	void makeHeap(vector<int>& input)
	{
		int size = (int)input.size();
		for (int i = 0; i < size; i++)
		{
			arr.push_back(input[i]);
		}
		for (int i = size / 2 - 1; i >= 0; i--)
		{
			siftDown(i);
		}
	}

	void print()
	{
		for (auto const &i : arr)
		{
			cout << i << " ";
		}
		cout << endl;
	}
};

int main()
{
	MaxHeap h;
	/*h.push(5);
	h.push(10);
	h.push(2);
	h.push(8);*/

	vector<int> v = { 6, 10, 65, 20, 1, 5, 5, 11 };
	h.makeHeap(v);

	h.print();

	h.pop();
	h.print();

	h.pop();
	h.print();

	h.pop();
	h.print();

	return 0;
}
