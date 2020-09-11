#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

Node * insertt(Node* curr, int val)
{
    if(curr == nullptr)
        return new Node(val);

    if(curr->data > val)
        curr->left = insertt(curr->left, val);
    else
        curr->right = insertt(curr->right, val);
    
    return curr;
}

void bfs(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    
    queue<Node*> nodes;
    nodes.push(root);
    Node* temp;
    int tempSize = 1;    
    double currSum = 0;
    int cnt = 0;
    while(!nodes.empty())
    {
        temp = nodes.front();
        nodes.pop();
        
        if(temp->left)
            nodes.push(temp->left);
        if(temp->right)
            nodes.push(temp->right);
        
        currSum += temp->data;
        cnt++;
        if(cnt == tempSize)
        {
            currSum /= tempSize;            
            cout << currSum << endl;
            currSum = 0;
            cnt = 0;
            tempSize = nodes.size();
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    int N;
    cin >> N;
    Node* root = nullptr;
    int temp;
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        root = insertt(root, temp);
    }
    
    bfs(root);
    
    return 0;
}
