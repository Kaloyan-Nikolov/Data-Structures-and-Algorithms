#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Student
{
    string name;
    int group;
    int enteredQueue;

    void setInfo(const string& n, int gr, int timeEnter)
    {
        this->name = n;
        this->group = gr;
        this->enteredQueue = timeEnter;
    }
};

void arrangeQueue(queue<Student>& input, int M)
{
    int N = (int)input.size();

    queue<int> queueCanteenGroups;
    vector<queue<Student>> table(M+1);    
    // we place first student in the table;
    Student tempStudent = input.front();
    input.pop();
    table[tempStudent.group].push(tempStudent); // happens at min 1;
    queueCanteenGroups.push(tempStudent.group);
    int tempGroup;
    int passedMins = 1;   
    while (!queueCanteenGroups.empty())
    {
        if (!input.empty())
        {
            tempStudent = input.front();
            input.pop();
            table[tempStudent.group].push(tempStudent);
            if(table[tempStudent.group].size() == 1) // first of his gtoup
                queueCanteenGroups.push(tempStudent.group);
        }

        if (passedMins % 2 == 0)
        {
            tempGroup = queueCanteenGroups.front();
            tempStudent = table[tempGroup].front();
            table[tempStudent.group].pop();
            if(table[tempStudent.group].size() == 0)
                queueCanteenGroups.pop(); // last of his group;
            cout << tempStudent.name << " " << tempStudent.enteredQueue
                << " " << passedMins << endl;
        }

        passedMins++;
    }

}

int main()
{
    std::ios::sync_with_stdio(false);

    int N; // number of students;
    int M; // number of groups;

    cin >> N >> M;

    queue<Student> input;
    string tempName;
    int tempGroup;
    Student tempStudent;
    for (int i = 0; i < N; i++)
    {
        cin >> tempName >> tempGroup;
        tempStudent.setInfo(tempName, tempGroup, i);
        input.push(tempStudent);
    }
    
    arrangeQueue(input, M);

    return 0;
}
