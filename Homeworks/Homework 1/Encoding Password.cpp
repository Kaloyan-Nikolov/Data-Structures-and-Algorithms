#include <iostream>
#include <string>
using namespace std;

void encodePassword(const string &password)
{
    unsigned passSize = password.size();
    int counter = 1;    
    for (unsigned i = 1; i < passSize; i++)
    {
        if (password[i] == password[i-1])
        {
            counter++;
        }
        else
        {
            cout << counter << password[i - 1];
            counter = 1;
        }
    }
    cout << counter << password[passSize - 1] << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    string password;
    cin >> password;
    encodePassword(password);
  
    return 0;
}
