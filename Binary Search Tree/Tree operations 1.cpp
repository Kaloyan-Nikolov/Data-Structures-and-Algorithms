#include <iostream>

using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
    node(int value = 0) : value(value), left(nullptr), right(nullptr){}
};

node* add(node* curr, int val)
{
    if(curr == nullptr)
        return new node(val);
    else if (curr->value == val)
        return curr;
    else if(curr->value > val)
        curr->left = add(curr->left, val);
    else
        curr->right = add(curr->right, val);
    
    return curr;
}

void print(node* curr)
{
    if(!curr)
        return;
    
    cout << curr->value << " ";
    print(curr->left);
    print(curr->right);
}

int main() 
{
    int n;
    cin >> n;
    string s;
    int number;
    node* root = nullptr;
    while(n--)
    {
        cin >> s;
        if( s == "add")
        {
            cin >> number;
            root = add(root, number);
        }
        else if(s == "print")
        {
            print(root);
        }
    }   
    
    return 0;
}
