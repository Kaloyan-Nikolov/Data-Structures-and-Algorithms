#include <iostream>
#include <string>
#include <vector>

using namespace std;

string gameOfThrones(const string& s) 
{
    unsigned letters[26] = { 0 };
    unsigned size = s.size();
    for (unsigned i = 0; i < size; i++)
    {
        letters[s[i] - 'a']++;
    }

    int cntOddNumLetters = 0;
    for (int i = 0; i < 26; i++)
    {
        if (letters[i] % 2 != 0)
            cntOddNumLetters++;

        if (cntOddNumLetters >= 2)
            return "NO";
    }

    return "YES";
}

int main()
{
    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    cout << result << "\n";    

    return 0;
}
