#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int N; int temp;
        priority_queue<int> positive;
        priority_queue<int, vector<int>, greater<int>> negative;
        int sum = 0;
        cin >> N;
        while(N--)
        {
            cin >> temp;
            if(temp > 0)
            {
                positive.push(temp);                
            }
            else
            {
                negative.push(temp);
            }  
        }        
        while(positive.size() > 1)
        {
            int first = positive.top(); positive.pop();
            int second = positive.top(); positive.pop();
            sum += max(first + second, first * second);            
        }        
        if(positive.size() == 1)
        {
            sum += positive.top();
        } 
        
        while(negative.size() > 1)
        {
            int first = negative.top(); negative.pop();
            int second = negative.top(); negative.pop();
            sum += max(first + second, first * second);            
        }        
        if(negative.size() == 1)
        {
            sum += negative.top();
        } 
        cout << sum << endl;       
    }    
    return 0;
}
