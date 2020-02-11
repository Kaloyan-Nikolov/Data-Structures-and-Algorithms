#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

struct Days
{
    int neededBallons; // number of ballons we have to give;
    int bonbons; // number of bonbons we have to give to replace 1 ballon;
    // how many bonbons we have to give if we do not have any ballons;
    ull onlyBonbons;    

    void setNeededBallons(const int& ballons)
    {
        this->neededBallons = ballons;
    }

    void setBonbons(const int& bonbons)
    {
        this->bonbons = bonbons;
    }

    void setOnlyBonbons()
    {
        // in order not to overflow the int on the right side;
        this->onlyBonbons = this->neededBallons;
        this->onlyBonbons *= this->bonbons;
    }    
};

// we will try to make sure that we have to pay at most
//  "result" bonbons every day
bool isPossibleAnswer(vector<Days>& v, ull result, ull M)
{
    int s = (int)v.size();
    ull givenBallons = 0;
    for (int i = 0; i < s; i++)
    {
        if (v[i].onlyBonbons > result)
        {
            givenBallons += ceil((v[i].onlyBonbons - result) / (double)v[i].bonbons);
            if (givenBallons > M)
                return false;
        }
    }

    return true;
}

int partition(vector<Days> &v, int& l, int& r)
{
    int middle = l + (r - l) / 2;
    swap(v[middle], v[r]);    
    int piInd = l;
    for (int i = l; i < r; i++)
    {
        if (v[i].onlyBonbons > v[r].onlyBonbons)
        {
            swap(v[i], v[piInd++]);
        }
    }
    swap(v[piInd], v[r]);
    return piInd;
}

// finds the k-th biggest element
void quickSearch(vector<Days> &v, int l, int r, int k = 0) // we will have to find the biggest element
{
    int pivot = partition(v, l, r);
    if (pivot == k)
    {
        return;
    }
    else if (pivot > k)
    {
        quickSearch(v, l, pivot - 1, k);
    }
    else
    {
        quickSearch(v, pivot + 1, r, k);
    }
}

void giveAllBallons(vector<Days>& v, ull result, ull M)
{
    int s = (int)v.size();
    ull givenBallons = 0;
    for (int i = 0; i < s; i++)
    {
        if (v[i].onlyBonbons > result)
        {
            givenBallons = ceil((v[i].onlyBonbons - result) / (double)v[i].bonbons);
            ull toBeRemoved = ull(givenBallons * v[i].bonbons);
            if (v[i].onlyBonbons >= toBeRemoved)
                v[i].onlyBonbons -= givenBallons * v[i].bonbons;
            else
                v[i].onlyBonbons = 0;
            if (givenBallons > M)
                return;            
        }        
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    int N; // number of days;
    ull M; // number of ballons available

    cin >> N >> M;

    vector<int> ballonsForDay(N);
    for (int i = 0; i < N; i++)
    {
        cin >> ballonsForDay[i];
    }

    vector<int> bonbonsForBallon(N);
    for (int i = 0; i < N; i++)
    {
        cin >> bonbonsForBallon[i];
    }

    vector<Days> allDays(N);
    for (int i = 0; i < N; i++)
    {
        allDays[i].setNeededBallons(ballonsForDay[i]);
        allDays[i].setBonbons(bonbonsForBallon[i]);
        allDays[i].setOnlyBonbons();
    }

    quickSearch(allDays, 0, N - 1); // place the day in which we have to give
    // the most bonbons first (if we have 0 ballons);
    ull left = 0; // you can have enough ballons for all days;
    ull right = allDays[0].onlyBonbons; // the biggest possible answer;

    ull bestAnswer = -1;
    while (left < right)
    {
        ull middle = left + (right - left) / 2;
        if (isPossibleAnswer(allDays, middle, M))
        {
            right = middle - 1;
            bestAnswer = middle;
        }
        else
        {
            left = middle + 1;
        }
    }

    giveAllBallons(allDays, bestAnswer, M);
    quickSearch(allDays, 0, N - 1);
    cout << allDays[0].onlyBonbons << endl;
   
    return 0;
}
