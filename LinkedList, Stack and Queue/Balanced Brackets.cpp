#include <bits/stdc++.h>

using namespace std;

void areBalanced(string& s)
{
    stack<char> stak;   

    for(auto i : s)
    {
        if( i == '[' || i == '{' || i == '(')
            stak.push(i);
        else if (i == ')')
        {            
            if(!stak.size() || stak.top() != '(')
            {
                cout << "NO\n";
                return;
            }
            else
                stak.pop();                     
        }
        else if (i == ']')
        {
            if(!stak.size() || stak.top() != '[')
            {
                cout << "NO\n";
                return;
            }
            else
                stak.pop();  
        }
        else if(i == '}')
        {
            if(!stak.size() || stak.top() != '{')
            {
                cout << "NO\n";
                return;
            }
            else
                stak.pop();
        }
    }

    if(stak.size())
    {
         cout << "NO\n";
        return;
    }

    cout << "YES\n";
    return;
}

int main()
{
    int n;
    cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        areBalanced(s);
    }

    return 0;
}
