#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the cookies function below.
 */
int cookies(int k, vector<int> A) 
{
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> myQ;
    int size = (int)A.size();
    for(int i = 0; i < size; i++)
    {
        myQ.push(A[i]);
    }

    while(myQ.size() > 0 && myQ.top() < k)
    {
        int first = myQ.top();
        myQ.pop();
        if(myQ.size() == 0)
            return -1;

        int second = myQ.top();
        myQ.pop();
        int result = first + second * 2;
        myQ.push(result);
        cnt++;
    }

    return cnt;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v;
    int temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    cout << cookies(k, v);
    return 0;
}
