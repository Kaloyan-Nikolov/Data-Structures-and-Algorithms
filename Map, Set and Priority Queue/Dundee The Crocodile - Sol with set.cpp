#include <bits/stdc++.h>
using namespace std;

vector<string> sent1;
vector<string> sent2;
void toVector(string& s, vector<string>& v)
{
    string word;
    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ')
            word.push_back(s[i]);
        else
        {
            if(word != "")
            {
                v.push_back(word);
                word = "";
            }
        }
    }
    
    if(word != "")
    {
        v.push_back(word);
        word = "";
    }
}

int main() {
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);
    
    toVector(s1, sent1);
    toVector(s2, sent2);
    
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    
    for(size_t i = 0; i < sent1.size(); i++)
    {
        m1[sent1[i]]++;
    }
    
    for(size_t i = 0; i < sent2.size(); i++)
    {
        m2[sent2[i]]++;
    }
    
    set<string> res;
    
    for(auto i : m1)
    {
        if(i.second == 1 && m2.count(i.first) == 0)
            res.insert(i.first);
    }
    
    for(auto i : m2)
    {
        if(i.second == 1 && m1.count(i.first) == 0)
            res.insert(i.first);
    }
    
    for(auto i : res)
    {
        cout << i << "\n";
    }    
    
    return 0;
}
