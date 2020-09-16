#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

vector<int> findPosPeople(vector<int> scores) {
    int sizeScores = scores.size();
    vector<int> allPositions(sizeScores, 0);

    int position = 1;
    allPositions[0] = 1;
    for (int i = 1; i < sizeScores; i++) {
        if (scores[i] == scores[i - 1])
            allPositions[i] = position;
        else
            allPositions[i] = ++position;
    }    

    return allPositions;
}

// Complete the climbingLeaderboard function below.
void climbingLeaderboard(vector<int> scores, vector<int> alice) {
    unsigned scoresLen = scores.size();
    unsigned aliceLen = alice.size();    

    vector<int> allPositions = findPosPeople(scores);

    int l;
    int r;
    int middle;    

    for (int i = 0; i < aliceLen; i++) {
        l = 0;
        r = scoresLen - 1;
        while (l < r) {
            middle = (l + r) / 2;
            if (scores[middle] <= alice[i])
                r = middle;
            else
                l = middle + 1;
        }

        if (scores[r] <= alice[i])
            cout << allPositions[r] << endl;
        else
            cout << allPositions[r] + 1 << endl;
    }
}

int main(){    
    std::ios::sync_with_stdio(false);
    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    climbingLeaderboard(scores, alice);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
