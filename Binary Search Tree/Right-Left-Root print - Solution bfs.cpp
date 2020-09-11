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
  
	queue<int> myQ;
	void realPrint(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		realPrint(root->rightNode);
		realPrint(root->leftNode);
		myQ.push(root->data);
	}
  
	void print(Node *root)
	{
		realPrint(root);
		while (myQ.size() > 1)
		{
			cout << myQ.front() << ";";
			myQ.pop();
		}
		cout << myQ.front();
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
