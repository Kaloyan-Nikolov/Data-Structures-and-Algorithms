#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int y;
    int temp;
    set<int> mySet;
    for(int i = 0; i < N; i++)
    {
        cin >> y >> temp;
        if(y == 1)
        {
            mySet.insert(temp);
        }
        if(y == 2)
        {
            mySet.erase(temp);
        }
        if(y == 3)
        {
            set<int>::iterator it = mySet.find(temp);
            if(it != mySet.end())            
            cout << "Yes" << endl;
            else 
            {
                cout << "No" << endl;
            }       
        }
    }

    return 0;
}
