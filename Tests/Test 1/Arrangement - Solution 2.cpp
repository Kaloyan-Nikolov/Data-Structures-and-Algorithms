#include <cstdio>
#include <vector>
using namespace std;

void countingSort(vector<int>& v)
{
    int s = v.size();
    int minEl = v[0];
    int maxEl = v[0];
    
    for(int i = 0; i < s; i++)
    {
        if(minEl > v[i])
            minEl = v[i];
        if(maxEl < v[i])
            maxEl = v[i];
    }    
    
    int range = maxEl - minEl + 1;
    vector<int> count(range, 0);
    
    for(int i = 0; i < s; i++)
    {
        count[v[i] - minEl]++;
    }
    
    for(int i = 0; i < range - 1; i++)
    {
        count[i+1] += count[i];
    }
    
    vector<int> sorted(s);
    
    for(int i = s - 1; i >= 0; i--)
    {
        sorted[count[v[i] - minEl] - 1] = v[i];
        count[v[i] - minEl]--;
    }
    
    for(int i = 0; i < s; i++)
    {
        v[s-i-1] = sorted[i];
    }
    
    for(auto i : v)
    {
        printf("%d ", i);        
    }
    printf("\n");    
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);       
    }
    
    countingSort(v);
    
    return 0;
}
