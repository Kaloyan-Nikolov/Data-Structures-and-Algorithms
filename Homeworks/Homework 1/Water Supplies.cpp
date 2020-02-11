#include <iostream>
#include <vector>
using namespace std;

int findMaxWater(const vector<int>& wallsHeight)
{    
    int SMax = 0;
    int tempS = 0;
    unsigned wallsNum = wallsHeight.size();
    for (unsigned i = 0; i < wallsNum; i++)
    {        
        for (unsigned j = i + 1; j < wallsNum; j++)
        {
            // we find the distance between the 2 walls: j - i (always j > i) and 
            // then multiply it by the height of the lower wall i.e. the smaller 
            // number from wallsHeight[j] and wallsHeight[i];
            if (wallsHeight[i] >= wallsHeight[j])
            {
                tempS = (j - i)*wallsHeight[j];
            }
            else
            {
                tempS = (j - i)*wallsHeight[i];
            }

            if (tempS > SMax)
            {
                SMax = tempS;
            }
        }
    }

    return SMax;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N;
    vector<int> wallsHeight;    
    cin >> N;

    int tempHeight;
    for (int i = 0; i < N; i++)
    {
        cin >> tempHeight;
        wallsHeight.push_back(tempHeight);
    }
    
    int S = findMaxWater(wallsHeight);
    cout << S << endl;
    
    return 0;
}
