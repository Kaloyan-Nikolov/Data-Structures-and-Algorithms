#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

struct Truck
{
    int K; // position of the truck
    int M; // number of monsters needed to move the truck 1 cm

    void setK(int K)
    {
        this->K = K;
    }

    void setM(int M)
    {
        this->M = M;
    }

    int numMonstersToArrange(int line)
    {
        int cmToMove = abs(K - line);
        return cmToMove * M;
    }
};

ull neededMonstersAllTrucks(vector<Truck>& trucks, int line)
{
    int s = (int)trucks.size();
    ull result = 0;
    for (int i = 0; i < s; i++)
    {
        result += trucks[i].numMonstersToArrange(line);
    }

    return result;
}

int main()
{
    int N; // number of trucks
    cin >> N;

    vector<Truck> input(N);
    int tempK, tempM;
    for (int i = 0; i < N; i++)
    {
        cin >> tempK >> tempM;
        input[i].setK(tempK);
        input[i].setM(tempM);
    }  

    const ull MAX_MONSTERS = 2500000000000; // = 50000 * 10000 * 5000
    int l = -10000; // min line
    int r = 10000; // max line;
    ull bestResult = MAX_MONSTERS;

    while (l <= r)
    {
        int m1 = (2 * l + r) / 3;
        int m2 = (l + 2 * r) / 3;
        ull f1 = neededMonstersAllTrucks(input, m1);
        ull f2 = neededMonstersAllTrucks(input, m2);            
        // we are searching the minimum possible number of monsters i.e.
        // the minumum of neededMonstersAllTrucks

        ull minF = min(f1, f2);
        if (bestResult > minF)
            bestResult = minF;

        if (f1 > f2)
            l = m1 + 1;
        else if (f2 > f1)
            r = m2 - 1;
        else
        {
            l = m1 + 1;
            r = m2 - 1;
        }
    }

    cout << bestResult << endl;

    return 0;
}
