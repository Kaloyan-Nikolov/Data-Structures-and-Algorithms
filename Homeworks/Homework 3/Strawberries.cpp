#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int binSearch_upperBound(vector<ull>& v, int l, int r, ull x)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (x > v[m])
            l = m + 1;
        else
            r = m;
    }
    if (v[l] >= x)
        return l;    
    else
        return -1;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n; // number bowls
    cin >> n;

    vector<ull> numStrawberriesInBowls(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numStrawberriesInBowls[i];
    }

    int m; // number delicious strawberries;
    cin >> m;

    vector<ull> numDeliciousStrawberries(m);
    for (int i = 0; i < m; i++)
    {
        cin >> numDeliciousStrawberries[i];
    }

    // we will find the strawberry with biggest number in each bowl;
    vector<ull> lastStrawberryInBowl(n);
    lastStrawberryInBowl[0] = numStrawberriesInBowls[0];
    for (int i = 1; i < n; i++)
    {
        lastStrawberryInBowl[i] = lastStrawberryInBowl[i - 1] + numStrawberriesInBowls[i];
    }    

    /*
    Now we have to do binary search for every number from numDeliciousStrawberries;
    If we find the number we return its index (which will happen only if the delicious strawberry
    is the one with biggest number from the bowl). 
    If we do not find the number, we have to return the index of the first (smallest) element
    which is bigger than the one we search, if of course such element exists;
    */

    ull bolwIndex;
    for (int i = 0; i < m; i++)
    {
        bolwIndex = binSearch_upperBound(lastStrawberryInBowl, 0, n - 1, numDeliciousStrawberries[i]);
        cout << bolwIndex + 1 << endl;
    }

    return 0;
}
