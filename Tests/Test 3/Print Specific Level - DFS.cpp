#include <vector>
#include <iostream>
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
        printrec(root, k);
    }

private:
    Node* root;
    
    void printrec(Node* root, int k, int level = 0){
        if(!root)
            return;
        
        if(level == k) cout << root->value << " ";
        printrec(root->right, k, level + 1);
        printrec(root->left, k, level + 1);
    }

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
