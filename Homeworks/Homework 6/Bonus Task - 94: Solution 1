#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct busStop
{
    int pos;
    int time;
    int leftBorder;
    int rightBorder;

    busStop(int pos = 0, int time = 0) :
        pos(pos), time(time), leftBorder(pos - time), rightBorder(pos + time) {}

    void set(int pos = 0, int time = 0)
    {
        this->pos = pos;
        this->time = time;
        this->leftBorder = pos - time;
        this->rightBorder = pos + time;
    }

    bool operator<(const busStop& bs) const
    {
        return rightBorder < bs.rightBorder;
    }
};

int binSearch_upperBound(vector<int>& v, int l, int r, int x)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (x > v[m])        
            l = m + 1;
        else
            r = m;
    }
    if (v[l] >= x)
        return l;    
    else
        return -1;
}

int findStudentsAttendLecture(vector<int>& students, vector<busStop>& stops94)
{
    int studentsCnt = 0;   
    vector<busStop>::iterator currStop = stops94.begin();
    while (!students.empty() && currStop != stops94.end())
    {        
        int posBestStudent = binSearch_upperBound(students, 0, students.size() - 1, currStop->leftBorder);

        if (posBestStudent != -1 && students[posBestStudent] <= currStop->rightBorder)
        {
            studentsCnt++;
            students.erase(students.begin() + posBestStudent);
        }        
        currStop++;
    }

    return studentsCnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    
    int n; // number of students
    int m; // number of bus stops;

    cin >> n >> m;

    vector<int> students(n);    
    for (int i = 0; i < n; ++i)
    {
        cin >> students[i];
    }

    vector<busStop> stops94(m);
    int pos;
    int time;
    busStop bs;
    for (int i = 0; i < m; ++i)
    {
        cin >> pos >> time;
        bs.set(pos, time);
        stops94[i] = bs;
    }

    sort(students.begin(), students.end());
    sort(stops94.begin(), stops94.end());
    int finalResult = findStudentsAttendLecture(students, stops94);
    cout << finalResult << endl;

    return 0;
}
