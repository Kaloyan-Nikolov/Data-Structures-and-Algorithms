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

	void count(Node* root, int& left, int& right)
	{
		if (root == nullptr)
			return;

		if (root->leftNode)
			count(root->leftNode, ++left, right);
		if (root->rightNode)
			count(root->rightNode, left, ++right);
	}

	void leftRight(Node *root) 
	{
		int left = 0;
		int right = 0;
		count(root, left, right);
		cout << "[" << left << "," << right << "]";
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

	myTree.leftRight(root);
	return 0;
}
