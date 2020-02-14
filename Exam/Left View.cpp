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

    void printLeftProfile() {
      leftView();
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
   
    void bfs(vector<vector<int>>& table){        
        queue<Node*> q;
        q.push(root);        
        
        int level = 0;
        int tempsize = 1;
        while(!q.empty())
        {
            Node* topEl = q.front();
            q.pop();
            tempsize--;
            
            table[level].push_back(topEl->value);
            
            if(topEl->left)
                q.push(topEl->left);
            if(topEl->right)
                q.push(topEl->right);
            
            if(tempsize == 0)
            {
                tempsize = q.size();
                level++;
            }
        }
    }
    
    void leftView(){
        vector<vector<int>> table(100002);
        bfs(table);
        for(int i = 0; i < 100002; i++)
        {
            if(table[i].size())
                cout << table[i][0] << " ";
            else
                break;
        }
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
    tree.printLeftProfile();
    return 0;
}
