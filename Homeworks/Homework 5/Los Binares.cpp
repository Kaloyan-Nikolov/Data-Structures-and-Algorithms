#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int address;
    int distance;
    Node* left;
    Node* right;

    Node(int address = 0, int distance = 0, Node* left = nullptr, Node* right = nullptr)
        : address(address), distance(distance), left(left), right(right){}
};

Node* insert(Node* root, int address, int distance = 0)
{
    if (root == nullptr)
    {
        root = new Node(address, distance);        
    }    
    else if (root->address > address) // go left
    {
        root->left = insert(root->left, address, distance + 1);
    }
    else if (root->address < address) // go right
    {
        root->right = insert(root->right, address, distance + 1);
    }
    return root;
}

int findDistance(Node* root, int address)
{
    if (root == nullptr)
        return -1;
    if (root->address == address)
        return root->distance;
    if (root->address > address) // go left
        return findDistance(root->left, address);    

    // go right
    return findDistance(root->right, address);
}

int main()
{
    int N; // number of addresses to receive
    int K; // number of requests from Maazon 

    cin >> N >> K;

    Node* root = nullptr;

    int ad;
    for (int i = 0; i < N; i++) // create city
    {
        cin >> ad;
        root = insert(root, ad);
    }

    int req;
    queue<int> requests;
    for (int i = 0; i < K; i++) // save requests
    {
        cin >> req;
        requests.push(findDistance(root, req));
    }

    // print final result;
    while (!requests.empty())
    {
        cout << requests.front() << endl;
        requests.pop();
    }

    return 0;
}
