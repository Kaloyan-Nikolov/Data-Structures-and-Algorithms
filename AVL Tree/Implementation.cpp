#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node
{
	double value;
	int bf;
	int height;
	Node *left;
	Node *right;

	Node(double value, int balFactor = 0, int h = 0, Node *left = nullptr, Node *right = nullptr)
	{
		this->value = value;
		this->bf = balFactor;
		this->height = h;
		this->left = left;
		this->right = right;
	}
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void update(Node* curr)
	{
		if (curr == nullptr)
			return;

		int heightLeftSubTree;
		if (curr->left == nullptr)
			heightLeftSubTree = -1;
		else
			heightLeftSubTree = curr->left->height;

		int heightRightSubTree;
		if (curr->right == nullptr)
			heightRightSubTree = -1;
		else
			heightRightSubTree = curr->right->height;

		curr->height = 1 + max(heightLeftSubTree, heightRightSubTree);
		curr->bf = heightRightSubTree - heightLeftSubTree;
	}

	Node* balanceTree(Node* curr)
	{
		// left
		if (curr->bf == -2)
		{
			// left left
			if (curr->left->bf <= 0)
				return left_left_rotation(curr);
			else // left right
				return left_right_rotation(curr);
		}

		// right
		if (curr->bf == 2)
		{
			// right right
			if (curr->right->bf >= 0)
				return right_right_rotation(curr);
			else // right left
				return right_left_rotation(curr);
		}

		return curr;
	}

	Node* leftRotation(Node* curr)
	{
		Node * newNode = curr->right;
		curr->right = newNode->left;
		newNode->left = curr;

		update(curr);
		update(newNode);
		return newNode;
	}

	Node* rightRotation(Node* curr)
	{
		Node* newNode = curr->left;
		curr->left = newNode->right;
		newNode->right = curr;

		update(curr);
		update(newNode);
		return newNode;
	}

	Node* left_left_rotation(Node* curr)
	{
		return rightRotation(curr);
	}

	Node* left_right_rotation(Node* curr)
	{
		curr->left = leftRotation(curr->left);
		return rightRotation(curr);
	}

	Node* right_right_rotation(Node* curr)
	{
		return leftRotation(curr);
	}

	Node* right_left_rotation(Node* curr)
	{
		curr->right = rightRotation(curr->right);
		return leftRotation(curr);
	}

	Node* addRecursive(Node* curr, double value)
	{
		if (curr == nullptr)
			return new Node(value);
		if (curr->value > value)
			curr->left = addRecursive(curr->left, value);
		if (curr->value < value)
			curr->right = addRecursive(curr->right, value);

		update(curr);
		return balanceTree(curr);
	}

	Node* removeRecursive(Node* curr, double value)
	{
		if (curr == nullptr)
		{
			return nullptr;
		}
		if (curr->value > value)
		{
			curr->left = removeRecursive(curr->left, value);
		}
		else if (curr->value < value)
		{
			curr->right = removeRecursive(curr->right, value);
		}
		else
		{
			if (curr->left == nullptr)
			{
				Node* temp = curr->right;
				delete curr;
				return temp;
			}

			Node* maxInLeftSubTree = curr->left;
			while (maxInLeftSubTree->right != nullptr)
			{
				maxInLeftSubTree = maxInLeftSubTree->right;
			}

			curr->value = maxInLeftSubTree->value;
			curr->left = removeRecursive(curr->left, curr->value);
		}

		update(curr);
		return balanceTree(curr);
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	void add(double value)
	{
		if (!contains(value))
		{
			root = addRecursive(root, value);
		}
		else
		{
			cout << value << " already added" << endl;
		}
	}

	void remove(double value)
	{
		if (contains(value))
		{
			root = removeRecursive(root, value);
		}
		else
		{
			cout << value << " not found to remove" << endl;
		}
	}

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}
