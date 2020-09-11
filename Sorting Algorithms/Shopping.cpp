#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int l, int m, int r)
{
    int s1 = m - l + 1;
    int s2 = r - m;

    vector<int> L(s1);
    vector<int> R(s2);

    for (int i = 0; i < s1; i++) L[i] = v[i + l];
    for (int i = 0; i < s2; i++) R[i] = v[i + m + 1];

    int i = 0; int j = 0; int k = l;

    while (i < s1 && j < s2)
    {
        if (L[i] > R[j])
        {
            v[k++] = L[i++];
        }
        else
        {
            v[k++] = R[j++];
        }
    }

    while (i < s1) v[k++] = L[i++];
    while (j < s2) v[k++] = R[j++];
}

void mergeSort(vector<int>& v, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}

int main() {
    int n; int k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    mergeSort(v, 0, n - 1);

    int minSum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % k != 0)
        {
            minSum += v[i];
        }
    }

    cout << minSum;

    return 0;
}
