#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string tempWord;   
    map<string, int> m;
    while(cin >> tempWord)    
        m[tempWord]++;    
    
    for(const auto& i : m)
        if(i.second == 1)
            cout << i.first << "\n";

    return 0;
}
