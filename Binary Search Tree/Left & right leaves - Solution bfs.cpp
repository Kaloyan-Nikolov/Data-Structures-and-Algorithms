#include <bits/stdc++.h>

using namespace std;

class Node {
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

class Solution {
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

	void leftRight(Node *root) 
	{
		if (root == nullptr)
		{
			return;
		}

		int leftLeaves = 0;
		int rightLeaves = 0;

		queue<Node*> nodes;
		nodes.push(root);
		Node* temp;
		while (!nodes.empty())
		{
			temp = nodes.front();
			nodes.pop();

			if (temp->leftNode != nullptr)
			{
				nodes.push(temp->leftNode);
				leftLeaves++;
			}
			if (temp->rightNode != nullptr)
			{
				nodes.push(temp->rightNode);
				rightLeaves++;
			}
		}

		cout << "[" << leftLeaves << "," << rightLeaves << "]";
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
