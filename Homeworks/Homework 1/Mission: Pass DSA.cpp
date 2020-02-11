#include <iostream>
#include <vector>
using namespace std;

bool canAllPass(int minGrade, const vector<long long>& grades)
{
    unsigned numStudents = grades.size();
    long long minElement = grades[0]; // Ivan's grade;
    for (unsigned i = 0; i < numStudents; i++)
    {
        if (minElement > grades[i])
        {
            minElement = grades[i];
        }
    }

    long long sumSpareGrades = 0; // accumulates the points which can be spared
    // neededSum + Ivan's grade = minGrade;
    long long neededSum = minGrade - minElement;
    for (unsigned i = 0; i < numStudents; i++)
    {
        if (grades[i] > minGrade)
        {
            sumSpareGrades += grades[i] - minGrade;
        }

        if (sumSpareGrades >= neededSum)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int minGrage;
    int numStudents;
    cin >> minGrage >> numStudents;    
    
    vector<long long> grades;
    long long tempGrade;
    for (int i = 0; i < numStudents; i++)
    {
        cin >> tempGrade;
        grades.push_back(tempGrade);
    }        

    if (canAllPass(minGrage, grades))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
   
    return 0;
}
