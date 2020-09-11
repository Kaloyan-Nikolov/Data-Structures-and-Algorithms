#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

typedef long long ll;

#define MOD 8888888897888888899 // last prime number in long long
#define BASE 257 // first prime number after 256

void getPowers(vector<ll>& basePowers, int to)
{
    basePowers[0] = 1;
    for (int i = 1; i <= to; i++)
    {
        basePowers[i] = (basePowers[i - 1] * BASE) % MOD;
    }
}

ll getHash(vector<ll>& basePowers, const string& word, int K)
{
    ll result = 0;

    for (int i = 0; i < K; i++)
    {
        result = (result + word[i] * basePowers[i]) % MOD;
    }

    return result;
}

void rollingHash(const string& input, int N, int K)
{
    vector<ll> basePowers(K+1);
    getPowers(basePowers, K);

    ll cur_hash = getHash(basePowers, input.substr(0, K), K);

    unordered_map<ll, int> myHash;
    myHash[cur_hash]++;

    int numMaxOccurences = 1;
    int startingIndexOfCurrResult = 0;

    for (int i = K; i < N; i++)
    {
        cur_hash -= (input[i - K] * basePowers[K - 1]) % MOD;
        cur_hash = ((cur_hash * BASE) % MOD + input[i]) % MOD;

        myHash[cur_hash]++;
        if (numMaxOccurences <= myHash[cur_hash])
        {
            numMaxOccurences = myHash[cur_hash];
            startingIndexOfCurrResult = i - K + 1;
        }
    }

    for (int i = startingIndexOfCurrResult; i < (startingIndexOfCurrResult + K); i++)
    {
        cout << input[i];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; // length of text
    int K; // lenght of searched substring
    cin >> N >> K;
    cin.ignore();
    string input;
    getline(cin, input);

    rollingHash(input, N, K);

    return 0;
}
