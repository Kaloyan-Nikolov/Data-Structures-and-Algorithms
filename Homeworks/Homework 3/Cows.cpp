#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// for a given minDistance, we will check if there is a way to
// place the k cows so that they are at least minDistance away from one another
bool canBePlaced(vector<int>& differences, int k, int minDistance, vector<int>& posCows)
{
    for (int i = 0; i < k; i++) posCows[i] = 0;

    int s = (int)differences.size();
    int currDistance = 0;
    int i = 1;
    int j = 1;
    posCows[0] = 1; // the first cow is in the first hut
    while (i < k) // we have to place the k cows
    {
        while (currDistance < minDistance)
        {
            if (j >= s)
                return false;
            currDistance += differences[j];
            j++;
        }
        currDistance = 0;
        posCows[i] = j; // save where we have placed the i-th cow;
        i++;
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int N;
    int K;
    cin >> N >> K;

    vector<int> coordinates(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coordinates[i];
    }
    
    sort(coordinates.begin(), coordinates.end());

    // the i-th element of the vector will store the distance between the i-th and (i-1)-th hut
    vector<int> differences(N);
    differences[0] = 0;
    for (int i = 1; i < N; i++)
    {
        differences[i] = coordinates[i] - coordinates[i - 1];
    }    

    //if the cows are only 2 - we place them in the first and last huts;
    if (K == 2)
        cout << coordinates[N - 1] - coordinates[0];
    else
    {
        const int MAX_ANSWER = 2000000000;
        // the min theoretical answer;
        int left = 0; 
        // the max theoretical distance is the one between the first ans last cows;
        int right = MAX_ANSWER;

        // posCows will save the indexes of the huts where we have placed the cows;
        vector<int> posCows(K, 0);
        // bestAnswer will store the indexed of the huts where we have placed the cows
        // if the distance between the 2 nearest cows is the BIGGEST found so far;
        vector<int>bestAnswer(K, 0);        

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (canBePlaced(differences, K, middle, posCows))
            {
                bestAnswer = posCows;
                left = middle + 1;
            }
            else
                right = middle - 1;
        }        

        // now we know where the cows are placed and we have to 
        // calculate the distance between the 2 nearest cows;

        int minDist = MAX_ANSWER; // this will be the final result;
        int currDist = 0;
        int t = 1; // first cow is always in first hut
        for (int i = 1; i < N; i++)
        {
            currDist += differences[i];
            if (i + 1 == bestAnswer[t]) // if this is the index of a hut with a cow in it
            {
                t++;
                if (currDist < minDist)
                    minDist = currDist;
                currDist = 0;
            }
        }
        
        cout << minDist << endl;
    }
    
    return 0;
}
