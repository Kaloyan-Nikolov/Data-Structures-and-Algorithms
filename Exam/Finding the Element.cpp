#include <vector>
#include <iostream>
using namespace std;

int lowerb(vector<int>& v, int x)
{
    int l = 0;
    int r = v.size() - 1;
    while(l < r)
    {
        int m = l + (r-l+1)/2;
        if(v[m] <= x)
            l = m;
        else
            r = m-1;
    }
    
    if(v[l] <= x)
        return l;
    else
        return -1;
}

int find_leftmost(vector<int>& v, int x)
{
    int l = 0;
    int r = v.size() - 1;
    int ans = -1;
    while(l <= r)
    {
        int m = l + (r-l)/2;
        if(v[m] == x)
        {
            ans = m;
            r = m -1;
        }
        else if(v[m] > x)
            r = m - 1;
        else        
            l = m + 1;       
    }    
    return ans;
}

int find_rightmost(vector<int>& v, int x)
{
    int l = 0;
    int r = v.size() - 1;
    int ans = -1;
    while(l <= r)
    {
        int m = l + (r-l)/2;
        if(v[m] == x)
        {
            ans = m;
            l = m + 1;
        }
        else if(v[m] > x)
            r = m - 1;
        else        
            l = m + 1;      
    }    
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);    
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];        
    }
    
    int q;
    cin >> q;
    int left, right, temp;    
    for(int i = 0; i < q; i++)
    {
        cin >> temp;    
        left = find_leftmost(v , temp);        
        
        if(left == -1)
        {
            left = lowerb(v , temp);
            if(left == -1)
                cout << 0 << '\n';
            else
                cout << left + 1 << '\n';
        }
        else  
        {
            right = find_rightmost(v , temp);
            cout << left << " " << right << '\n';
        }
    }   
    return 0;
}
