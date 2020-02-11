#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class SpecialQueue
{
    queue<int> Queue;
    list<int> currMin;
    list<int> currMax;

public:    

    // adds element in Queue, updates currMin, currMax;
    void push_back(int data)
    {
        
        while (currMin.size() > 0 && currMin.back() > data)
        {
            currMin.pop_back();
        }
        currMin.push_back(data);

        while (currMax.size() > 0 && currMax.back() < data)
        {
            currMax.pop_back();
        }
        currMax.push_back(data);

        Queue.push(data);        
    }

    // pops element from Queue, updates currMin, currMax;
    void pop_front()
    {
        // if we are going to pop the current min element
        if (Queue.front() == currMin.front()) 
        {
            currMin.pop_front();
        }

        // if we are going to pop the current max element
        if (Queue.front() == currMax.front())
        {
            currMax.pop_front();
        }
        
        Queue.pop();
    }

    int getSizeSpecialQueue()
    {
        return Queue.size();
    }

    // return the difference between current max and min elements;
    int getDiff()
    {
        if (Queue.size() > 0)
            return currMax.front() - currMin.front();
        return -1; // error code;
    }

};

int main()
{
    std::ios::sync_with_stdio(false);

    int N; // number of elements of array;
    int K; // max difference;

    cin >> N >> K;

    vector<int> input(N);    
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    
    SpecialQueue Utility;
    unsigned long long numAllInvervals = 0;    
    vector<int>::iterator it = input.begin();
    while (it != input.end())
    {
        Utility.push_back(*it);
        it++;

        while (Utility.getDiff() > K) // we make the difference ok;
        {
            Utility.pop_front();
        }

        // now we know the difference is ok and we add the new intervals;
        numAllInvervals += Utility.getSizeSpecialQueue();        
    }    

    // we print the final result;
    cout << numAllInvervals << endl;

    return 0;
}
