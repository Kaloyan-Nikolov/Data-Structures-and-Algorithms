#include <iostream>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    int temp;
    int x;
    string str;
    map<string, int> mym;
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        if(temp == 1)
        {
            cin >> str >> x;
            map<string, int>::iterator it = mym.find(str);
            if(it != mym.end())
            {
                it->second += x;
            }
            else
            {
                mym[str] = x;
            }
        }
        else if(temp == 2)
        {
            cin >> str;
            map<string, int>::iterator it = mym.find(str);
            if(it != mym.end())
            {
                it->second = 0;
            }
        }
        else if(temp == 3)
        {
            cin >> str;           
            map<string, int>::iterator it = mym.find(str);
            if(it != mym.end())
            {
                cout << it->second << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }   

    return 0;
}
