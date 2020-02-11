#include <iostream>
#include <stack>
using namespace std;

void canBeOrdered(stack<int>& trucks)
{
    int expectedTruck = 1;
    stack<int>smallStreet;
    while (!trucks.empty())
    {
        if (trucks.top() == expectedTruck)
        {
            expectedTruck++;
        }
        else
        {
            smallStreet.push(trucks.top());
        }
        trucks.pop();
    }

    while (!smallStreet.empty())
    {
        if (smallStreet.top() == expectedTruck)
        {
            expectedTruck++;
            smallStreet.pop();
        }
        else
        {
            cout << "no" << endl;
            return;
        }
    }

    cout << "yes" << endl;
}

int main()
{
    int T; // number of requests; 
    cin >> T;
    int N; // number of trucks;
    for (int j = 0; j < T; j++)
    {
        cin >> N;
        stack<int> inputTrucks;
        int temp;
        for (int i = 0; i < N; i++)
        {
            cin >> temp;
            inputTrucks.push(temp);
        }

        // now we will reverse the stack
        // in order NOT to use queue;

        stack<int> trucksOrdered;
        for (int i = 0; i < N; i++)
        {
            trucksOrdered.push(inputTrucks.top());
            inputTrucks.pop();
        }        

        canBeOrdered(trucksOrdered);
    }
    
    return 0;
}
