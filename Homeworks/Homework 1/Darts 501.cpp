#include <iostream>
#include <vector>
using namespace std;

int findWaysCleanPoints(int N)
{
    int combinations = 0;
    vector<int> points = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
        16, 17, 18, 19, 20, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45,
        48,    51, 54, 57, 60, 25, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,22, 24, 26, 28,
        30, 32, 34, 36, 38, 40, 50 };
    unsigned pointsSize = points.size();    

    /*
    to be able to finish in one hit the players must have points:
    2, 4, ..., 40 or 50 i.e. 50 or an even number between 2 and 40
    */

    //for 1 hit
    bool numPoint = (N >= 2 && N <= 40 && (N & 1) == 0) || N == 50;
    if (numPoint)
    {
        combinations++;
    }    

    //for 2 hits
    int temp;
    for (unsigned i = 0; i < pointsSize; i++)
    {
        temp = N - points[i];
        numPoint = (temp >= 2 && temp <= 40 && (temp & 1) == 0) || temp == 50;
        if(numPoint)
        {
            combinations++;
        }
    }

    //for 3 hits
    int pointsHit = 0;
    for (unsigned i = 0; i < pointsSize; i++)
    {
        for (unsigned j = 0; j < pointsSize; j++)
        {
            temp = N - points[i] - points[j];
            numPoint = (temp >= 2 && temp <= 40 && (temp & 1) == 0) || temp == 50;
            if (numPoint)
            {
                combinations++;
            }
        }
    }

    return combinations;
}

int main()
{
    int N;
    cin >> N;
    
    int result = findWaysCleanPoints(N);    
    cout << result << endl;
    
    return 0;
}
