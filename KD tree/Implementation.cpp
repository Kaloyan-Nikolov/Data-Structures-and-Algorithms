#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	vector<int> values;
	Node* left;
	Node* right;

	Node(vector<int>& p)
	{
		values = p;
		left = right = nullptr;
	}
};

class kdTree
{
	int dimentions;
	Node* root;
public:

	kdTree(int k = 2)
	{
		dimentions = k;
		root = nullptr;
	}

	//1
	Node* insertRec(Node* curr, vector<int>& p, int level)
	{
		if (curr == nullptr)
			return new Node(p);

		int coord = level % dimentions;

		if (curr->values[coord] > p[coord])
		{
			curr->left = insertRec(curr->left, p, level + 1);
		}
		else
		{
			curr->right = insertRec(curr->right, p, level + 1);
		}

		return curr;
	}

	void insert(vector<int> p)
	{
		root = insertRec(root, p, 0);
	}

	//2
	Node* findRec(Node* curr, vector<int>& p, int level = 0)
	{
		if (curr == nullptr)
			return nullptr;

		int coord = level % dimentions;

		if (curr->values[coord] == p[coord])
		{
			if (curr->values == p)
				return curr;
			else
				return nullptr;
		}
		else if (curr->values[coord] > p[coord])
		{
			return findRec(curr->left, p, level + 1);
		}

		return findRec(curr->right, p, level + 1);
	}

	Node* find(vector<int> p)
	{
		return findRec(root, p);
	}

	//3
	int findMinNumbRec(Node* curr, int dim, int level)
	{
		if (curr == nullptr)
			return 9999;

		int cd = level % dimentions;

		if (cd == dim)
		{
			if (curr->left == nullptr)
				return curr->values[dim];
			return min(curr->values[dim], findMinNumbRec(curr->left, dim, level + 1));
		}

		return min(curr->values[dim],
			min(findMinNumbRec(curr->left, dim, level + 1), findMinNumbRec(curr->right, dim, level + 1)));
	}

	int findMinNumb(int dim)
	{
		return findMinNumbRec(root, dim-1, 0);
	}	

	//4
	void rectangleDB_Rec(vector<int> D, vector<int> B, Node* root, int level) {
		if (root == nullptr) {
			return;
		}

		if (level % 2 == 0) {
			if (root->values[0] < D[0]) {
				rectangleDB_Rec(D, B, root->right, level + 1);
			}
			else if (root->values[0] > B[0]) {
				rectangleDB_Rec(D, B, root->left, level + 1);
			}
			else {
				if (root->values[1] <= D[1] && root->values[1] >= B[1]) {
					printf("%d %d\n", root->values[0], root->values[1]);
				}
				rectangleDB_Rec(D, B, root->left, level + 1);
				rectangleDB_Rec(D, B, root->right, level + 1);
			}
		}
		else {
			if (root->values[1] > D[1]) {
				rectangleDB_Rec(D, B, root->left, level + 1);
			}
			else if (root->values[1] < B[1]) {
				rectangleDB_Rec(D, B, root->right, level + 1);
			}
			else {
				if (root->values[0] >= D[0] && root->values[0] <= B[0]) {
					printf("%d %d\n", root->values[0], root->values[1]);
				}
				rectangleDB_Rec(D, B, root->left, level + 1);
				rectangleDB_Rec(D, B, root->right, level + 1);
			}
		}
	}

	void rectangleDB(vector<int> D, vector<int> B)
	{
		rectangleDB_Rec(D, B, root, 0);
	}

	//5
	void printRec(Node* curr)
	{
		if (curr == nullptr)
			return;

		printRec(curr->left);
		for (auto i : curr->values) printf("%d ", i);
		printf("\n");
		printRec(curr->right);
	}

	void print()
	{
		printRec(root);
	}
};

int main()
{
	kdTree kd;
	kd.insert({ 3,4 });
	kd.insert({ 1,2 });
	kd.insert({ 4,1 });
	kd.insert({ -1,2 });
	kd.insert({ 10,8 });
	kd.insert({ -2,1 });
	kd.insert({ 9,9 });
	kd.insert({ 2,3 });
	kd.insert({ 8,8 });
	kd.insert({ 2,6 });
	kd.insert({ 1,7 });
	kd.insert({ -1,-1 });
	kd.insert({ 3,-2 });
	kd.insert({ 8,-3 });

	printf("All points in the KD tree, in the following order: left, root, right:\n");
	kd.print();

	printf("\nFind all points in rectangle ABCD defined by the\nupper left point D(0,8) and lower right point B(3,5)\n");
	kd.rectangleDB({ 0,8 }, { 3,5 });

	printf("\nCheck if there is a point (10,9) in the tree:\n");
	kd.find({ 10,9 }) ? printf("The point is found!\n") : printf("The point is NOT found!\n");

	printf("\nFind min number for second dimension:\n");
	printf("%d", kd.findMinNumb(2));

	return 0;
}
