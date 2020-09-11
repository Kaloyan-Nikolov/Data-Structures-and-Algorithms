#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> order(n);
    unordered_map<int, int> table;
    
    for(int i = 0; i < n; i++)
    {
        cin >> order[i];
        table[order[i]]++;
    }   
    
    unordered_set<int> numbers;
    vector<int> notUniq;
    
    for(int i = 0; i < (int)order.size(); i++)
    {
        if(numbers.count(order[i]) == 0)
        {
            numbers.insert(order[i]);
            if(table[order[i]] == 1)
                cout << order[i] << " ";
            else
                notUniq.push_back(order[i]);
        }
    }
    
    for(auto i : notUniq)
        cout << i << " ";
    cout << '\n';
    
    return 0;
}
