#include <bits/stdc++.h>

using namespace std;

int main(){
    int q, n;
    cin >> q;
    for(int k = 0; k < q; k++)
    {
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n;++i){
            for (int j = 0;j < n;++j)
            {
                int x;
                cin >> x;
                a[i] += x; //number balls from container
                b[j] += x; //number balls from type
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a==b)
            cout<<"Possible\n";
        else 
            cout<<"Impossible\n";        
    }
    return 0;
}
