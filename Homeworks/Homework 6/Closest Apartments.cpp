#include <stdio.h>
#include <stack>
#include <queue>

using namespace std;

struct Apartment
{
    float X;
    float Y;
    double distanceSQRT;

    Apartment(float X = 1, float Y = 1, double distance = -1) : X(X), Y(Y), distanceSQRT(distance) {}
};

struct cmp
{
    // maxHeap;
    bool operator()(const Apartment& ap1, const Apartment& ap2)
    {
        if (ap1.distanceSQRT == ap2.distanceSQRT)
        {
            return ap1.X <= ap2.X;
        }
        else
        {
            return ap1.distanceSQRT < ap2.distanceSQRT;
        }
    }
};

int main()
{    
    int N; // number of apartments
    int K; // number closet apartments searched
    scanf("%d %d", &N, &K);    

    double X, Y;    
    priority_queue<Apartment, vector<Apartment>, cmp> prQ;
    for (int i = 0; i < K; ++i)
    {        
        scanf("%lf %lf", &X, &Y);
        prQ.emplace(X, Y, X * X + Y * Y);
    }

    double dist;  
    for (int i = K; i < N; ++i)
    {        
        scanf("%lf %lf", &X, &Y);
        dist = X * X + Y * Y;
        bool apCanBeAnswer;
        if (dist == prQ.top().distanceSQRT)
        {
            apCanBeAnswer = X <= prQ.top().X;
        }
        else
        {
            apCanBeAnswer = dist < prQ.top().distanceSQRT;
        }

        if (apCanBeAnswer)
        {
            prQ.pop();
            prQ.emplace(X, Y, X * X + Y * Y);
        }
    }

    stack<Apartment> result; 
    
    while (!prQ.empty())
    {
        result.push(prQ.top());
        prQ.pop();
    }

    while (!result.empty())
    {
        printf("%.0f %.0f\n", result.top().X, result.top().Y);        
        result.pop();
    }

    return 0;
}
