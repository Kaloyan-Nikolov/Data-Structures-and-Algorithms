#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

struct Node
{
    string name;
    Node* parent;
    map<string, Node*> childs;

    Node(string name = "", Node* parent = nullptr, map<string, Node*> childs = map<string, Node*>()) :
        name(name), parent(parent), childs(childs) {}
};

struct SpecialTree
{
    Node* root;
    Node* currentDirectory;

    SpecialTree()
    {
        root = new Node();
        currentDirectory = root;
    }

    void mkdir_func(string& name)
    {
        if (currentDirectory->childs.find(name) != currentDirectory->childs.end())
        {
            cout << "Directory already exists\n";
        }
        else
        {
            Node* temp = new Node(name, currentDirectory);
            currentDirectory->childs[name] = temp;
        }
    }

    void ls_func()
    {
        for(auto i : currentDirectory->childs)
        {
            cout << i.first << " ";
        }
        cout << "\n";
    }

    void pwd_func()
    {
        stack<string> st;
        Node* temp = currentDirectory;
        
        while (temp != root)
        {

            st.push(temp->name);
            temp = temp->parent;
        }        

        int size = (int)st.size();
        cout << "/";
        for (int i = 0; i < size; ++i)
        {
            cout << st.top() << "/";
            st.pop();
        }
        cout << "\n";
    }

    void cd_func(string& name)
    {
        if (name == "..")
        {
            if (currentDirectory == root)
            {
                cout << "No such directory\n";
                return;
            }
            currentDirectory = currentDirectory->parent;
            return;
        }

        if(currentDirectory->childs.count(name) == 0)
        {
            cout << "No such directory\n";
        }
        else
        {
            currentDirectory = currentDirectory->childs[name];
        }
    }
};

int main() {
    int N; // number of query
    cin >> N;

    SpecialTree st;
    string command;
    string temp;
    while (N--)
    {
        cin >> command;
        if (command == "mkdir")
        {
            cin >> temp;
            st.mkdir_func(temp);
        }
        else if (command == "ls")
        {
            st.ls_func();
        }
        else if (command == "pwd")
        {
            st.pwd_func();
        }
        else if (command == "cd")
        {
            cin >> temp;
            st.cd_func(temp);
        }
    }
    return 0;
}
