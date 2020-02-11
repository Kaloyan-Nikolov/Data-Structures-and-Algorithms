#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iterator>
using namespace std;

struct Node
{
    int counter = 0;
    unordered_map<char, Node*> childs;    
};

Node* addNode(Node* root,const string& word)
{
    int s = (int)word.size();
    root->counter++;
    Node* curr = root;
    for (int readLetters = 0; readLetters < s; ++readLetters)
    {
        auto it = curr->childs.find(word[readLetters]);
        if (it == curr->childs.end())
        {
            curr->childs[word[readLetters]] = new Node;
        }        
        curr = curr->childs[word[readLetters]];
        curr->counter++;
    }
    return root;
}

int possibleEndings(Node* root, string word)
{
    int s = (int)word.size();
    Node* curr = root;
    for (int checkedLetters = 0; checkedLetters < s; ++checkedLetters)
    {
        auto it = curr->childs.find(word[checkedLetters]);
        if (it == curr->childs.end())
        {
            return 0;
        }
        curr = curr->childs[word[checkedLetters]];
    }
    return curr->counter;
}

int main()
{
    int N; // number of words;
    int Q; // number of queries;
    cin >> N >> Q;
    Node* root = new Node;

    string tempWord;
    for(int i = 0; i < N; i++)
    {
        cin >> tempWord;
        root = addNode(root, tempWord);
    }

    string tempBeginning;
    int tempResult;
    for(int i = 0; i < Q; i++)
    {
        cin >> tempBeginning;
        tempResult = possibleEndings(root, tempBeginning);
        cout << tempResult << '\n';
    }

    return 0;
}
