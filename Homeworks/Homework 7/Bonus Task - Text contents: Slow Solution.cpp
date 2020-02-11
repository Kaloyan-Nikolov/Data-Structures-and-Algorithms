#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    int N; // length of text
    int K; // lenght of searched substring
    cin >> N >> K;
    cin.ignore();
    string input;
    getline(cin, input);  

    unordered_map<string, int> myHesh;
    string tempStr(input, 0, K);
    myHesh[tempStr]++;
    int currMaxOccuringStringNumb = 0;
    string currMaxOccuringString;
    
    for (int endStr = K; endStr < N; ++endStr)
    {
        tempStr.erase(tempStr.begin());
        tempStr.push_back(input[endStr]);
        myHesh[tempStr]++;
        
        if (currMaxOccuringStringNumb <= myHesh[tempStr])
        {
            currMaxOccuringStringNumb = myHesh[tempStr];
            currMaxOccuringString = tempStr;
        }
    }

    cout << currMaxOccuringString << '\n';

    return 0;
}
