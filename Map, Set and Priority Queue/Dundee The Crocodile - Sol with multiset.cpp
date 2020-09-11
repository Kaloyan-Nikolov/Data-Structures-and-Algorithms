#include <string>
#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() 
{
    multiset<string> mySet;
    string temp;
    while(cin >> temp)
    {
        mySet.insert(temp);
    }
    
    auto it = mySet.begin();
    while(it != mySet.end())
    {
        int cnt = mySet.count(*it);
        if(cnt == 1)
            cout << *it << endl;
        it++;
    }
    
    return 0;
}
