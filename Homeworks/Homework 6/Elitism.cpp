#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int main()
{
    int N; // number of citizens;
    scanf("%d", &N);

    cout << fixed << setprecision(1);
    priority_queue<int> minHeap; // keeps biggest element on top;
    minHeap.push(0);
    priority_queue<int, vector<int>, greater<int>> maxHeap; // keeps smallest element on top;
    maxHeap.push(17000000); // 17 000 000 > 2^24;    
    int cnt = 0;
    int temp;
    double median = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%ld", &temp);
        int diff = minHeap.size() - maxHeap.size();

        if (diff == 1) // minHeap has 1 element more
        {
            if (temp <= median)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(temp);
            }
            else
            {
                maxHeap.push(temp);
            }
            
            median = (maxHeap.top() + minHeap.top()) / double(2);
            printf("%.1f\n", median);
        }
        else if (diff == 0) // both heaps have equal number of elements;
        {
            if (temp >= median)
            {
                maxHeap.push(temp);
                median = maxHeap.top();
            }
            else
            {
                minHeap.push(temp);
                median = minHeap.top();
            }

           printf("%.1f\n", median);
        }
        else        // maxHeap has 1 element more
        {
            if (temp < median)
            {
                minHeap.push(temp);
            }
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(temp);
            }
            
            median = (maxHeap.top() + minHeap.top()) / double(2);
            printf("%.1f\n", median);
        }
    }
    return 0;
}
