#include <bits/stdc++.h>

using namespace std;

class Node 
{
public:
	int data;
	Node *leftNode;
	Node *rightNode;
	Node(int d)
	{
		data = d;
		leftNode = NULL;
		rightNode = NULL;
	}
};

class Solution
{
public:
	Node* insert(Node* root, int data)
	{
		if (root == NULL)
		{
			return new Node(data);
		}
		else
		{
			Node* cur;
			if (data <= root->data)
			{
				cur = insert(root->leftNode, data);
				root->leftNode = cur;
			}
			else
			{
				cur = insert(root->rightNode, data);
				root->rightNode = cur;
			}

			return root;
		}
	}

	void findSum(Node* root, int& sum)
	{
		if (root == nullptr)
			return;

		if (!root->leftNode && !root->rightNode)
			if (root->data & 1)
				sum += root->data;
		findSum(root->leftNode, sum);
		findSum(root->rightNode, sum);
	}

	void leaves(Node *root) 
	{
		int sum = 0;
		findSum(root, sum);
		cout << sum;
	}
};

int main()
{
	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0)
	{
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.leaves(root);
	return 0;
}
