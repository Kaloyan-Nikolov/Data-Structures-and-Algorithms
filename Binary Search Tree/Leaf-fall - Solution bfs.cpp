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

    void leaves(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        int sum = 0;
        queue<Node*> nodes;
        nodes.push(root);
        Node* temp;
        while (!nodes.empty())
        {
            temp = nodes.front();
            nodes.pop();
            bool isLeaf = temp->leftNode == nullptr && temp->rightNode == nullptr;

            if (isLeaf && temp->data % 2 == 1)
            {
                sum += temp->data;
            }

            if (temp->leftNode != nullptr)
            {
                nodes.push(temp->leftNode);
            }
            if (temp->rightNode != nullptr)
            {
                nodes.push(temp->rightNode);
            }
        }

        cout << sum;
    }
};

int main() {

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
