#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Node
{
	int value;
	Node* leftNode;
	Node* rightNode;
	Node(int val) : value(val), leftNode(nullptr), rightNode(nullptr) {}
};

//1
Node* insert(Node* curr, int value)
{
	if (curr == nullptr)
	{
		return new Node(value);
	}
	if (curr->value == value)
	{
		return curr;
	}
	else if (curr->value > value)
	{
		curr->leftNode = insert(curr->leftNode, value);
	}
	else
	{
		curr->rightNode = insert(curr->rightNode, value);
	}

	return curr;
}

//2
Node* find(Node* curr, int value)
{
	if (curr == nullptr)
	{
		return nullptr;
	}
	if (curr->value == value)
	{
		return curr;
	}
	else if (curr->value > value)
	{
		return find(curr->leftNode, value);
	}
	else
	{
		return find(curr->rightNode, value);
	}
}

//3
Node* remove(Node* curr, int value)
{
	if (curr == nullptr)
	{
		return nullptr;
	}
	if (curr->value > value)
	{
		curr->leftNode = remove(curr->leftNode, value);
	}
	else if (curr->value < value)
	{
		curr->rightNode = remove(curr->rightNode, value);
	}
	else
	{
		if (curr->leftNode == nullptr)
		{
			Node* temp = curr->rightNode;
			delete curr;
			return temp;
		}

		Node* maxInLeftSubTree = curr->leftNode;
		while (maxInLeftSubTree->rightNode != nullptr)
		{
			maxInLeftSubTree = maxInLeftSubTree->rightNode;
		}
		curr->value = maxInLeftSubTree->value;
		curr->leftNode = remove(curr->leftNode, curr->value);

		/*if (curr->rightNode == nullptr)
		{
			Node* temp = curr->leftNode;
			delete curr;
			return temp;
		}

		Node* minInRightSubTree = curr->rightNode;
		while (minInRightSubTree->leftNode != nullptr)
		{
			minInRightSubTree = minInRightSubTree->leftNode;
		}
		curr->value = minInRightSubTree->value;
		curr->rightNode = remove(curr->rightNode, curr->value);*/
	}
	return curr;
}

//4
Node* findMin(Node* curr)
{
	if (curr == nullptr)
		return nullptr;

	if (curr->leftNode != nullptr)
	{
		return findMin(curr->leftNode);
	}
	return curr;
}

//5
Node* findMax(Node* curr)
{
	if (curr == nullptr)
		return nullptr;

	if (curr->rightNode != nullptr)
	{
		return findMax(curr->rightNode);
	}
	return curr;
}

//6
int findMinNumber(Node* curr)
{
	if (curr == nullptr)
		return -1;

	if (curr->leftNode != nullptr)
	{
		return findMinNumber(curr->leftNode);
	}

	return curr->value;
}

//7
int findMaxNumber(Node* curr)
{
	if (curr == nullptr)
		return -1;

	if (curr->rightNode != nullptr)
	{
		return  findMaxNumber(curr->rightNode);
	}

	return curr->value;
}

//8
void printSorted(Node* root)
{
	if (root == nullptr)
		return;

	printSorted(root->leftNode);
	cout << root->value << " ";
	printSorted(root->rightNode);
}

//9
void printSortedReversed(Node* root)
{
	if (root == nullptr)
		return;

	printSortedReversed(root->rightNode);
	cout << root->value << " ";
	printSortedReversed(root->leftNode);
}

//10
void printRightLeftRoot(Node* root)
{
	if (root == nullptr)
		return;

	printRightLeftRoot(root->rightNode);
	printRightLeftRoot(root->leftNode);
	cout << root->value << " ";
}

//11
void bfs(Node* root)
{
	if (root == nullptr)
		return;

	queue<Node*> nodes;
	nodes.push(root);
	Node* temp;
	while (!nodes.empty())
	{
		temp = nodes.front();
		nodes.pop();

		cout << temp->value << " ";

		if (temp->leftNode != nullptr)
			nodes.push(temp->leftNode);
		if (temp->rightNode != nullptr)
			nodes.push(temp->rightNode);
	}
}

//12
int level = 0;
int levelCount[10000];
void count(Node* root);

void printCount(Node* root)
{
	count(root);

	int i = 0;
	while (levelCount[i + 1] > 0)
	{
		cout << levelCount[i] << ";";
		i++;
	}
	cout << levelCount[i];
}

void count(Node* root)
{
	if (root == nullptr)
		return;

	levelCount[level]++;
	if (root->leftNode)
	{
		level++;
		count(root->leftNode);
		level--;
	}
	if (root->rightNode)
	{
		level++;
		count(root->rightNode);
		level--;
	}
}

//13
int i = 0;
int nodes[1000];
void isBST_DFS(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	isBST_DFS(root->leftNode);
	nodes[i] = root->value;
	i++;
	isBST_DFS(root->rightNode);
}

bool isReal_BST_DFS(Node* root)
{
	isBST_DFS(root);

	for (int k = 0; k < i; k++)
	{
		cout << nodes[k] << " ";
	}
	cout << endl;

	for (int j = 1; j < i; j++)
	{
		if (nodes[j] <= nodes[j - 1])
		{
			return false;
		}
	}

	return true;
}

//14
bool isBST_Intervals(Node* root, int minn = 0, int maxx = 10000000)
{
	if (root == nullptr)
		return true;
	if (root->value < minn || root->value > maxx)
		return false;

	return isBST_Intervals(root->leftNode, minn, root->value - 1) &&
		isBST_Intervals(root->rightNode, root->value + 1, maxx);
}

//15
int heightBST(Node* root)
{
	if (root == nullptr)
		return 0;

	int heightLeftSubTree = heightBST(root->leftNode);
	int heightRightSubTree = heightBST(root->rightNode);

	return max(heightLeftSubTree, heightRightSubTree) + 1;
}

//16

// finds min and max horizontal distance from root;
void findMinMax(Node* root, int& minn, int& maxx, int horizDist)
{
	if (root == nullptr)
		return;

	if (horizDist < minn)
		minn = horizDist;
	if (horizDist > maxx)
		maxx = horizDist;

	findMinMax(root->leftNode, minn, maxx, horizDist - 1);
	findMinMax(root->rightNode, minn, maxx, horizDist + 1);
}

void print_1_VertLine(Node* root, int numLine, int horizLine, bool& isFirst)
{
	if (root == nullptr)
		return;

	if (isFirst && horizLine == numLine)
	{
		cout << root->value;
		isFirst = false;
	}
	else if (horizLine == numLine)
	{
		cout << ";" << root->value;
	}

	print_1_VertLine(root->leftNode, numLine, horizLine - 1, isFirst);
	print_1_VertLine(root->rightNode, numLine, horizLine + 1, isFirst);
}

void verticalOrder(Node* root)
{
	int minn = 0;
	int maxx = 0;
	findMinMax(root, minn, maxx, 0);
	cout << "minn: " << minn << " maxx: " << maxx << endl;

	bool isFirst;
	for (int i = minn; i <= maxx; i++)
	{
		isFirst = true;
		print_1_VertLine(root, i, 0, isFirst);
		cout << endl;
	}
}

//17
// Lowest Common Ancestor in binary tree;
Node *lca(Node *root, int v1, int v2)
{
	if (root == nullptr)
		return nullptr;

	if (root->value > v1 && root->value > v2)
	{
		return lca(root->leftNode, v1, v2);
	}
	else if (root->value < v1 && root->value < v2)
	{
		return lca(root->rightNode, v1, v2);
	}

	return root;
}

//18
bool isMirror(Node* root1, Node* root2)
{
	if (root1 == nullptr && root2 == nullptr)
		return true;
	if (root1 && root2 && root1->value == root2->value)
	{
		return isMirror(root1->leftNode, root2->rightNode)
			&& isMirror(root1->rightNode, root2->leftNode);
	}

	return false;
}

bool isSymmetric(Node* root)
{
	return isMirror(root, root);
}

//19
void preOrder2(Node *root);

queue<int> nodess;
void preOrder(Node* root)
{
	preOrder2(root);

	while (nodess.size() > 1)
	{
		cout << nodess.front() << ";";
		nodess.pop();
	}
	cout << nodess.front();
}

void preOrder2(Node *root) {
	if (root == nullptr)
		return;

	nodess.push(root->value);
	preOrder2(root->leftNode);
	preOrder2(root->rightNode);
}

//20 - without struct
void topView(Node * root) {
	if (root == nullptr)
	{
		return;
	}

	queue<pair<int, Node*>> q;
	q.push({ 0, root });

	map<int, int> m;
	m[0] = root->value;

	while (!q.empty())
	{
		pair<int, Node*> topel = q.front();
		q.pop();

		Node* temp = topel.second;
		int hd = topel.first;
		int value = temp->value;
		if (temp->leftNode)
		{
			q.push({ hd - 1, temp->leftNode });
		}

		if (temp->rightNode)
		{
			q.push({ hd + 1, temp->rightNode });
		}

		if (m.count(hd) == 0)
		{
			m[hd] = value;
		}
	}

	for (auto i : m)
	{
		cout << i.second << " ";
	}
}

// second solution - with struct
struct Comb
{
	Node* node;
	int hd;

	void set(Node* node, int hd)
	{
		this->node = node;
		this->hd = hd;
	}
};

void topView2(Node* root)
{
	if (root == nullptr)
		return;

	queue<Comb> myQ;
	map<int, int> myM;

	Comb ctemp;
	Node* nodeTemp = root;
	int hd = 0;
	int value = nodeTemp->value;

	ctemp.set(nodeTemp, hd);
	myQ.push(ctemp);
	myM[hd] = value;

	while (!myQ.empty())
	{
		ctemp = myQ.front();
		myQ.pop();

		nodeTemp = ctemp.node;
		hd = ctemp.hd;
		value = nodeTemp->value;

		if (nodeTemp->leftNode)
		{
			ctemp.set(nodeTemp->leftNode, hd - 1);
			myQ.push(ctemp);
		}

		if (nodeTemp->rightNode)
		{
			ctemp.set(nodeTemp->rightNode, hd + 1);
			myQ.push(ctemp);
		}

		if (myM.count(hd) == 0)
		{
			myM[hd] = value;
		}
	}

	map<int, int>::iterator it;
	for (it = myM.begin(); it != myM.end(); it++)
	{
		cout << it->second << " ";
	}
}

//21
vector<int> myVec;
void utilKth(Node* root)
{
	if (root == nullptr)
		return;

	utilKth(root->rightNode);
	myVec.push_back(root->value);
	utilKth(root->leftNode);
}

void getK_thBiggest(Node* root, int number)
{
	utilKth(root);
	cout << myVec[number - 1];
}

//22
Node* upperBound(Node* root, int value)
{
	if (root == nullptr)
		return nullptr;

	if (root->value == value)
		return root;

	if (root->value < value)
		return upperBound(root->rightNode, value);
	else
	{
		Node* temp = upperBound(root->leftNode, value);
		if (temp)
			return temp;
		return root;
	}
}

//23
Node* lowerBound(Node* root, int value)
{
	if (root == nullptr)
		return nullptr;

	if (root->value == value)
		return root;

	if (root->value > value)
		return lowerBound(root->leftNode, value);
	else
	{
		Node* temp = lowerBound(root->rightNode, value);
		if (temp)
			return temp;
		return root;
	}
}

//24
Node* createBSTfromArr(int* arr, int n)
{
	if (n <= 0)
		return nullptr;

	Node * root = new Node(arr[n / 2]);
	root->leftNode = createBSTfromArr(arr, n / 2);
	root->rightNode = createBSTfromArr(arr + n / 2 + 1, n - n / 2 - 1);
	return root;
}

int main()
{
	Node* root = nullptr;
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 8);
	root = insert(root, 7);
	root = insert(root, 11);
	
	root = insert(root, 4);
	root = insert(root, 2);
	root = insert(root, 6);
	root = insert(root, 1);
	//root = insert(root, 3);
	//root = insert(root, 5);
	root = insert(root, 7);

	//root = remove(root, 5);
	//root = remove(root, 8);
	//root = remove(root, 6);
	//root = remove(root, 2);
	//root = remove(root, 4);

	printSorted(root);
	cout << endl;

	cout << "bsf: ";
	bfs(root);
	cout << endl;

	cout << "level count: ";
	printCount(root);
	cout << endl << endl;

	cout << "is bst(dfs): " << endl;
	cout << isReal_BST_DFS(root) << endl;

	cout << "is bst(intervals): " << isBST_Intervals(root) << endl << endl;

	cout << "height is: " << heightBST(root) << endl;

	cout << "vertical order: " << endl;
	verticalOrder(root);

	cout << endl << endl;
	cout << "isSymmetric: " << isSymmetric(root) << endl << endl;

	preOrder(root);
	cout << endl << endl;

	cout << "topView: ";
	topView(root);
	cout << endl << endl;

	cout << "get k-th biggest: ";
	getK_thBiggest(root, 1);
	cout << endl << endl;

	Node* lowBound = lowerBound(root, 5);
	Node* uppBound = upperBound(root, 5);
	if (lowBound)
		cout << "lowBound: " << lowBound->value << endl;
	else
		cout << "lowBound: " << -1 << endl;
	if (uppBound)
		cout << "uppBound: " << uppBound->value << endl;
	else
		cout << "uppBound: " << -1 << endl;

	cout << endl << "-----" << endl << endl;

	Node* foundMin = findMin(root);
	if (foundMin != nullptr)
		cout << "min: " << foundMin->value << " ";
	else
		cout << "min: " << -1 << " ";
	Node* foundMax = findMax(root);
	if (foundMax != nullptr)
		cout << "max: " << foundMax->value << " ";
	else
		cout << "max: " << -1 << " ";

	cout << endl << endl;

	int minNum = findMinNumber(root);
	cout << "minNum: " << minNum << endl;
	int maxNum = findMaxNumber(root);
	cout << "maxNum: " << maxNum << endl;

	cout << endl << endl;

	root = remove(root, 5);
	root = remove(root, 5);
	root = remove(root, 4);
	root = remove(root, 11);
	root = remove(root, 9);

	printSorted(root);
	cout << endl << endl;

	int arr[] = { 3, 5, 8, 15, 20, 30 };
	Node* root2 = createBSTfromArr(arr, sizeof(arr) / sizeof(arr[0]));

	printSorted(root2);
	cout << endl;

	printSortedReversed(root2);
	cout << endl;

	printRightLeftRoot(root2);
	cout << endl;

	return 0;
}
