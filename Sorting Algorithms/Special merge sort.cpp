#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&v , int l, int m, int r)
{
    int s1 = m - l +1;
    int s2 = r - m;
    
    vector<int> L(s1), R(s2);
    
    for(int i = 0; i < s1; i++) L[i] = v[l+i];
    for(int i = 0; i < s2; i++) R[i] = v[m+1+i];
    
    int i = 0;
    int j = 0;
    int k = l;
    
    while(i < s1 && j < s2)
    {
        if(L[i] < R[j])
        {
            v[k++] = L[i++];
        }
        else
            v[k++] = R[j++];
    }
    
    while(i < s1)v[k++] = L[i++];
    while(j < s2)v[k++] = R[j++];
    
    for(int i = l; i <= r; i++)
        cout << v[i] << " ";

}

void ms(vector<int>&v ,int l, int r)
{
    if(l == r)
    {
        cout << v[l] << " ";
    }
    if(l < r)
    {
        int m = l + (r-l)/2;
        ms(v, l, m);
        ms(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    
    ms(v, 0, n-1);
    return 0;
}
