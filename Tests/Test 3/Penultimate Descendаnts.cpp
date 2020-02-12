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

    void deletePenultimateAndPrint() {
      verySpecialPrint(root);
    }    

private:
    Node* root;
  	
    void verySpecialPrint(Node* root)
    {
        if(!root)
            return;
        
        verySpecialPrint(root->left);
        
        bool areChildsLeafAndLeaf = root->left && root->right && !root->left->left && !root->left->right
                                    && !root->right->left && !root->right->right;
        bool areChildsLeafAndNull = root->left && !root->right && !root->left->left && !root->left->right;
        bool areChildsNullAndLeaf = root->right && !root->left && !root->right->left && !root->right->right;        
        
        bool shouldNotPrint = areChildsLeafAndLeaf || areChildsLeafAndNull || areChildsNullAndLeaf;       
      
        if(!shouldNotPrint) cout << root->value << " ";
        
        verySpecialPrint(root->right);
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
    tree.deletePenultimateAndPrint();
    return 0;
}
