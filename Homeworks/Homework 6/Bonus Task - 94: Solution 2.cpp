#include <iostream>
#include <set>

using namespace std;

struct busStop
{
    int pos;
    int time;
    int leftBorder;
    int rightBorder;
    
    busStop(int pos = 0, int time = 0) :
        pos(pos), time(time), leftBorder(pos - time), rightBorder(pos + time){}

    bool operator<(const busStop& bs) const
    {
        return rightBorder < bs.rightBorder;
    }
};

int findStudentsAttendLecture(multiset<int>& students, multiset<busStop>& stops94)
{
    int studentsCnt = 0;
    while (!students.empty() && !stops94.empty())
    {
        multiset<busStop>::iterator currStop = stops94.begin();
        multiset<int>::iterator bestStudent = students.lower_bound(currStop->leftBorder);        
        
        if (bestStudent != students.end() && *bestStudent <= currStop->rightBorder)
        {
            studentsCnt++;
            students.erase(bestStudent);
        }
        stops94.erase(currStop);
    }

    return studentsCnt;
}

int main()
{
    int n; // number of students
    int m; // number of bus stops;
    
    cin >> n >> m;

    multiset<int> students;
    int temp;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        students.emplace(temp);
    }

    multiset<busStop> stops94;
    int pos;
    int time;
    for (int i = 0; i < m; ++i)
    {
        cin >> pos >> time;
        stops94.emplace(pos, time);
    }

    int finalResult = findStudentsAttendLecture(students, stops94);
    cout << finalResult << endl;

    return 0;
}
