#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printKDistant(int k) {
        if(!root)
            return;          
        
        queue<Node*> nodes;
        nodes.push(root);
        
        int currLevel = 0;
        int tempSize = 1;
        int cnt = 0;
        while(!nodes.empty())
        {
            auto topEl = nodes.front();
            nodes.pop();
            cnt++;
            
            if(currLevel == k)
                cout << topEl->value << " ";
            
            if(topEl->right)
                nodes.push(topEl->right);
            if(topEl->left)
                nodes.push(topEl->left);
            
            if(cnt == tempSize)
            {
                tempSize = nodes.size();
                cnt = 0;
                currLevel++;
            }    
        }
    }

private:  	
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    int k;
    cin >> k;
    tree.printKDistant(k);
    return 0;
}
