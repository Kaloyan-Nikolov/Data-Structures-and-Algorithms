#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

struct Point{
    int val;
    int type;  
    
    Point(int val = 0, int type = 0) :
    val(val), type(type){}
    
    void set(int vall, int type)
    {
        this->val = vall;
        this->type = type;
    }
    
    bool operator<(const Point& p) const
    {
        if(val == p.val)
        {
            return type > p.type;
        }
        return val < p.val;
    }
};

int main() {
    int numInt;
    int q;
    cin >> numInt >> q;
    numInt *= 2;
    
    multiset<Point> ms;
    int temp;
    int type;
    int cnt = 0;
    while(numInt--)
    {
        cin >> temp;
        cnt++;        
        if(cnt % 2 == 1)
        {
            type = 1;
        }
        else
            type = -1;
        
        Point p(temp, type);
        ms.insert(p);        
    }
    
    vector<int> quiries(q);
    int tempQuiy;
    
    for(int i = 0; i < q; i++)
    {
        cin >> tempQuiy;
        quiries[i] = tempQuiy;
        ms.insert(tempQuiy);
    }
        
    unordered_map<int, int> holder;
    auto it = ms.begin();
    int numActiveInt = 0;
    while(it != ms.end())
    {
        numActiveInt += it->type;
        if(it->type == 0)
        {
            holder[it->val] = numActiveInt;
        }       
        it++;
    }
    
    for(int i = 0; i < q; i++)
    {       
        cout << holder[quiries[i]] << " ";
    }
    
    return 0;
}
