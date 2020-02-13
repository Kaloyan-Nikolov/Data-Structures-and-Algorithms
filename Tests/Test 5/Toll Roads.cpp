#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> mym;
    string city;
    int tax;
    while(n--)
    {
        cin >> city >> tax;
        mym[city] = tax;
    }
    long long sum = 0;
    string searched;
    while(m--)
    {
        cin >> searched;
        sum += mym[searched];
    }
    
    cout << sum << '\n';
   
    return 0;
}
