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

	void realPrint(Node* curr, bool isRoot)
	{
		if (curr == nullptr)
			return;

		realPrint(curr->rightNode, 0);
		realPrint(curr->leftNode, 0);
		cout << curr->data;
		if (!isRoot)
			cout << ";";
	}

	void print(Node *root)
	{
		realPrint(root, 1);
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

	myTree.print(root);
	return 0;
}
