#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool myCompare(string& s1, string& s2)
{
    string res1 = s1;
    res1 += s2;
    string res2 = s2;
    res2 += s1;

    return res2 > res1;
}

int main()
{
    int N;
    cin >> N;

    vector<string> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (myCompare(v[j], v[j + 1]))
                swap(v[j], v[j + 1]);

    // first zeros should not be printed;
    
    int i = 0;
    while(i < N && v[i] == "0")
    {
        i++;
    }
    
    if(i == N)
    {
        cout << 0;
    }
    
    while(i < N)
    {    
       cout << v[i++];    
    }
    
    return 0;
}
