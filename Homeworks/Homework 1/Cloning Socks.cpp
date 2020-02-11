#include <iostream>
#include <vector>
using namespace std;

void canReceive(int N, int M)
{
    int copies = 0;
    int originals = 1;

    //first, we want to receive the correct number originals;
    while (originals < M)
    {
        originals++;
        copies++;        
        if (copies >= N)
        {
            break;
        }
    }

    bool areCopiesAchievable;
    if (copies > 0)
    {
        // N and copies must be both odd or even: note: (n & 1) == (n % 2);
        areCopiesAchievable = ((N - copies) & 1) == 0;
    }
    else
    {
        //if copies == 0, we cannot make more copies without making originals as well;
        areCopiesAchievable = copies == N;
    }

    if (originals == M && areCopiesAchievable)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int N; // copy pairs
    int M; // original pairs
    vector<int>copies;
    vector<int>originals;    

    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        copies.push_back(N);
        originals.push_back(M);
    }    

    for (int i = 0; i < T; i++)
    {        
        canReceive(copies[i], originals[i]);
    }
    
    return 0;
}
