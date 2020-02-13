#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    while(n--)
    {
        cin >> x;
        if(x != -1)
            q.push(x);
        else
        {
            if(!q.empty())
            {
                cout << q.top() << " ";
                q.pop();
            }
        }
    }
    return 0;
}
