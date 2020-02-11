#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

// find the index of the tree before which Zartan have to stay;
void findPosition(vector<int>& heights)
{
    int s = (int)heights.size();
    stack<int> seq;
    int maxFoundSize = 2;
    int startingInd = s - 1;
    int bestStartingInd = INT_MAX;
    seq.push(INT_MAX);
    seq.push(heights[s - 1]);

    /*
    idea: we have a stack and we interate heights from the end till the start;
    for every element in heights we do the following:
    1) we pop as many elements from the stack until we can push heights[i];
    2) we push it and update startingInd and if we can, we update
    maxFoundSize and bestStartingInd as well    
    */

    for(int i = s - 2; i >= 0; i--)
    {
        int j = i;
        while (seq.size() > 0 && heights[i] >= seq.top())
            {
                seq.pop();
                j--;
            }
        if (seq.size() == 0)
        {
            seq.push(INT_MAX);    // in order to have a last element        
        }

        if (heights[i] < seq.top())
        {
            seq.push(heights[i]);
            startingInd = i;
            if (seq.size() > maxFoundSize)
                maxFoundSize++;            
            if (startingInd < bestStartingInd && seq.size() == maxFoundSize)
                bestStartingInd = startingInd;
        }        
    }
    cout << bestStartingInd;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; i++)
        cin >> heights[i];

    findPosition(heights);

    return 0;
}
