#include <iostream>
#include <vector>
using namespace std;

struct Events
{
    int start;
    int end;

    void setStart(int start)
    {
        this->start = start;
    }

    void setEnd(int duration)
    {
        this->end = start + duration;
    }    
};

void merge(vector<Events>& v, vector<Events>& L, vector<Events>& R) {
    int sizeLeft = (int)L.size();
    int sizeRight = (int)R.size();

    int i = 0; // index of L
    int j = 0; // index of R
    int k = 0; // index of v

    while (i < sizeLeft && j < sizeRight) {
        if (L[i].end <= R[j].end)
        {
            v[k++] = L[i++];            
        }
        else
        {
            v[k++] = R[j++];
        }
    }
    while (i < sizeLeft) v[k++] = L[i++];
    while (j < sizeRight) v[k++] = R[j++];
}

void mergeSort(vector<Events>& v) {
    int s = (int)v.size();

    if (s < 2)
        return; // base condition

    int mid = s / 2;

    vector<Events> L(mid); // L[0,1...mid-1]
    vector<Events> R(s - mid); //R[mid,mid+1,...s-1];
    int i;
    for (i = 0; i < mid; i++) L[i] = v[i];
    for (i = mid; i < s; i++) R[i - mid] = v[i];

    mergeSort(L);  // sort left subarray
    mergeSort(R);  // sort right subarray
    merge(v, L, R);  // merging L and R into one vector - v;
}


int main()
{
    std::ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int tempStart;
    int tempDuration;
    vector<Events> allEvents(N);
    for (int i = 0; i < N; i++)
    {
        cin >> tempStart >> tempDuration;
        allEvents[i].setStart(tempStart);
        allEvents[i].setEnd(tempDuration);
    }

    /*
    The idea is to attend the event which is going to finish first.
    We sort the events depending on the time, the event finishes. We sort in decreasing order.
    */

    mergeSort(allEvents);   
    
    int attendedEvents = 0;
    int currTme = 0;
    for (int i = 0; i < N; i++)
    {
        if (allEvents[i].start >= currTme) // we can attend the event
        {
            attendedEvents++;
            currTme = allEvents[i].end;
        }
    }
    
    cout << attendedEvents;
    
    return 0;
}
