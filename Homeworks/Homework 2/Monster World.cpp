#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& v, int l, int r)
{
    int middle = l + (r - l) / 2;
    swap(v[middle], v[r]);
    int pi = v[r];
    int piIndex = l;

    for (int i = l; i < r; i++)
    {
        if (v[i] <= pi) // place all elements smaller than pivot on the left;
        {
            swap(v[piIndex++], v[i]);
        }
    }

    swap(v[piIndex], v[r]); // place pi (pivot element) on the correct place;
    return piIndex;
}

void quickSort(vector<int>& v, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(v, l, r);
        quickSort(v, l, pivot - 1);
        quickSort(v, pivot + 1, r);
    }
}


void minBlasts(vector<int> uniqueMonsters, int x)
{
    int result = 0;
    int s = uniqueMonsters.size(); 
    int minPosToBeAlive = 0;
    while (s - result > 0 && uniqueMonsters[s - 1 - result] > minPosToBeAlive)
    {
        result++;
        minPosToBeAlive += x; 
        // in order the monster not to have fallen into the trap, it must be at least on this position                  
    }

    cout << result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n; // number of monsters
    int x; // move with x positions  
    cin >> n >> x;

    vector<int> monstersPositions(n);
    for (int i = 0; i < n; i++)
    {
        cin >> monstersPositions[i];        
    }

    quickSort(monstersPositions, 0, n - 1);  
    
    vector<int> uniqueMonsters; // we will save only the monsters which have unique positions
    uniqueMonsters.reserve(n); // in order not to resize the vector multiple times
    uniqueMonsters.push_back(monstersPositions[0]);
    for(int i = 0; i < n - 1; i++)
    {
        if(monstersPositions[i] != monstersPositions[i+1])
        {
             uniqueMonsters.push_back(monstersPositions[i+1]);
        }        
    }
    
    minBlasts(uniqueMonsters, x);    
  
    return 0;
}
