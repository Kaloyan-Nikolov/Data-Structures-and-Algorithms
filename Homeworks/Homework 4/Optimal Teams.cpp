#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Students
{
    int skills;
    int index;
    int team;
};

void markTeams(vector<Students>& participants, int ind, int teamToChoose, int k)
{
    int s = (int)participants.size();    

    participants[ind].team = teamToChoose; // mark the student
    int i = 0, j = 0;
    // find the participants before him;        
    for (int t = ind - 1; t >= 0; t--)
    {
        if (participants[t].team == 0)
        {
            i++;
            participants[t].team = teamToChoose;
            if (i >= k)
                break;
        }        
    }

    // find the participants after him;        
    for (int t = ind + 1; t < s; t++)
    {
        if (participants[t].team == 0)
        {
            j++;
            participants[t].team = teamToChoose;
            if (j >= k)
                break;
        }        
    }
}

void arangeTeams(vector<Students>& participants, int k, const vector<Students*>& locations){

    int s = (int)participants.size();

    int tempSize = s;
    int teamToChoose = 1;
    while(tempSize > 0)
    {        
        bool hasTeam = locations[tempSize - 1]->team != 0;
        if (!hasTeam)    
        {            
            int ind = locations[tempSize - 1]->index;
            markTeams(participants, ind, teamToChoose, k);

            if (teamToChoose == 1)
                teamToChoose = 2;
            else
                teamToChoose = 1;
        }
        tempSize--;        
    }    

    // now we only have to print the final result;

    for (int i = 0; i < s; i++)
    {
        cout << participants[i].team;
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // number of students
    cin >> n;
    int k; // range in which a student is being chosen;
    cin >> k;
    vector<int> skillsStudents(n);
    for (int i = 0; i < n; i++)
        cin >> skillsStudents[i];

    vector<Students*> locations(n); // here we will have a pointer to a student
    // showing the skills he has. The pointer to student with p skills will be
    // in position p-1;
    vector<Students> participants(n);
    for (int i = 0; i < n; i++)
    {
        participants[i].skills = skillsStudents[i];
        participants[i].index = i;
        participants[i].team = 0;        
        locations[participants[i].skills - 1] = &participants[i];
    }

    arangeTeams(participants, k, locations);

    return 0;
}
