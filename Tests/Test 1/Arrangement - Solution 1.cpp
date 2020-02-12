#include <vector>
#include <iostream>
using namespace std;

void countingSort(vector<int>& v)
{
    int s = (int)v.size();
    // find smallest and biggest element
    int min = v[0];
    int max = v[0];
    
    for(int i = 0; i < s; i++)
    {
        if(min > v[i])
            min = v[i];
        if(max < v[i])
            max = v[i];        
    }
    
    int range = max - min + 1;
    vector<int> count(range, 0);
    
    for(int i = 0; i < s; i++)
    {
        count[v[i] - min]++;
    }  
    
    int k = s - 1;
    for(int i = 0; i < range; i++)
    {
        while(count[i] > 0)
        {
            v[k] = i + min;
            count[i]--;
            k--;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];    
    }
    
    countingSort(v);
    for(auto i : v) cout << i << " ";
    cout << endl;
    
    return 0;
}
