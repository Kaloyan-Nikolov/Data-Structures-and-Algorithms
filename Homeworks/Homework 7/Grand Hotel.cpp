#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct Room
{
    int keyToOpenNextDoor;
    int keyInIt;
    
    Room(int nextkey = 0, int key = 0): keyToOpenNextDoor(nextkey), keyInIt(key){}
};

int main() {
    std::ios::sync_with_stdio(false);
    int numRooms;
    cin >> numRooms;
    --numRooms;
    
    vector<Room> input(numRooms);
    for(int i = 0; i < numRooms ; i++)
    {
        cin >> input[i].keyInIt;
    }
    
    for(int i = 0; i < numRooms; i++)
    {
        cin >> input[i].keyToOpenNextDoor;
    }
    
    unordered_multiset<int> availableKeys;    
    int minNeededKeys = 0;
    
    /*
    idea:
    for every room:
    1) -get the key in the room
    2) -unlock the next door
    */
    
    for(int i = 0; i < numRooms; i++)
    {
        //1)
        availableKeys.insert(input[i].keyInIt);
        //2)        
        auto it = availableKeys.find(input[i].keyToOpenNextDoor);
        if(it != availableKeys.end())
        {
            availableKeys.erase(it);
        }
        else
        {
            minNeededKeys++;
        }
    }
    
    cout << minNeededKeys << "\n";
    
    return 0;
}
