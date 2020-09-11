#include <iostream>
#include <queue>
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

node* remove(node* curr, int val)
{
    if(curr == nullptr)
        return nullptr;
    if(curr->value > val)
        curr->left = remove(curr->left, val);
    else if(curr->value < val)
        curr->right = remove(curr->right, val);
    else
    {
        if(curr->right == nullptr)
        {
            node* temp = curr;
            curr = curr->left;
            delete temp;
            return curr;
        }
        else if(curr->left == nullptr)
        {
            node* temp = curr->right;
            delete curr;
            return temp;
        }
        
        node* sw = curr->right;
        while(sw->left)
            sw = sw->left;
        
        curr->value = sw->value;
        curr->right = remove(curr->right, curr->value);
        return curr;
    }
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

// FIRST SOLUTION
void print_odd_layers(node* curr, int level = 1)
{
    if(curr == nullptr)
        return;
    
    if(level % 2 == 1) cout << curr->value << " ";
    print_odd_layers(curr->left, level + 1);
    print_odd_layers(curr->right, level + 1);
}

// SECOND SOLUTION
void print_odd_layers2(node* curr)
{
    if(curr== nullptr)
        return;
    
    queue<node*> q;
    q.push(curr);
    
    int currLevel = 1;
    int tempSize = 1;
    while(!q.empty())
    {
        node* topEl = q.front();
        q.pop();
        tempSize--;
        
        if(currLevel & 1)
            cout << topEl->value << " ";
        
        if(topEl->left)
            q.push(topEl->left);
        if(topEl->right)
            q.push(topEl->right);
        
        if(!tempSize)
        {
            currLevel++;
            tempSize = q.size();
        }
    }
}

int main() {
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
        else if(s == "print_odd_layers")
        {
            print_odd_layers(root);
        }
        else if(s == "remove")
        {
            cin >> number;
            root = remove(root, number);
        }
    }   
    
    return 0;
}
