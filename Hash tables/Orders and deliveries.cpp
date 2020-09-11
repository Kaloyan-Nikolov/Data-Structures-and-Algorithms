#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    int temp;
    while(n--)
    {
        cin >> temp;
        m[temp]++;
    }
    
    int users = 0;
    int products = 0;
    
    for(auto i : m)
    {
        if(i.second % 10)
        {
            users++;
            products += i.second % 10;
        }
    }
    
    cout << users << " " << products;
    
    return 0;
}
