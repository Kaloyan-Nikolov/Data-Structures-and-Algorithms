#include <iostream>
#include <string>
#include <vector>
using namespace std;

void isPermutation(string& word1, string& word2, int N)
{  
    int s1 = word1.size();
    int s2 = word2.size();
    if(s1 != s2 || s1 > N || s2 > N)
    {
        cout << "no";
        return;
    }    
    
    const int NUM_LETTERS = 256;
  
    int arr1[NUM_LETTERS] = { 0 };
    int arr2[NUM_LETTERS] = { 0 };

    for (int i = 0; i < N; i++)
    {
        arr1[word1[i]]++;
        arr2[word2[i]]++;
    }

    // In order to be permutation, both words must contain the same letters.
    // If the number of any of the letters is different, the answer is no.
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (arr1[i] != arr2[i])
        {
            cout << "no";
            return;
        }        
    }

    cout << "yes";
}

int main()
{
    int N;
    string word1;
    string word2;

    std::ios::sync_with_stdio(false);
    cin >> N;    
    cin.ignore();
    getline(cin, word1); // the input can be an empty string
    getline(cin, word2);

    isPermutation(word1, word2, N);
 
    return 0;
}
