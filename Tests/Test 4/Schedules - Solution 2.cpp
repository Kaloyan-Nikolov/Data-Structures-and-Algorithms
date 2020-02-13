#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<pair<int, int>> input(n*2 + q);
    int temp;
    for(int i = 0; i < 2*n; i++)
    {
        cin >> temp;
        if(i % 2 == 0) // start
        {
            input[i] = {temp, -1};  // -1 for beginning, 0 for queury, 1 for end;
        }
        else
        {
            input[i] = {temp, 1};
        }
    }
    vector<int> origialQ;
    origialQ.reserve(q);
    for(int i = 2*n; i < 2*n + q; i++)
    {
        cin >> temp;
        input[i] = {temp, 0};
        origialQ.push_back(temp);
    }
    
    sort(input.begin(), input.end());
    
    int started = 0;
    unordered_map<int, int> m;
    for(int i = 0; i < input.size(); i++)
    {        
        if(input[i].second == -1)
            started++;
        else if(input[i].second == 0)
        {  
            m[input[i].first] = started;            
        }
        else if(input[i].second == 1)
            if(started > 0)
                started--;
    }   
    
    for(auto i : origialQ)
    {
        cout << m[i] << " ";
    }
    
    return 0;
}
