#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

#define inf 1200000

using namespace std;

int maxKilosInInput = 0;
int minKilosInInput = inf;
vector<bool> visited;
vector<int> paths;

struct cmp
{
    bool operator()(const vector<int>& a, const vector<int>& b) const
    {
        return a[2] > b[2];
    }
};

void dijkstra(vector<vector<vector<int>>>& adj, int K, int kilosToLose)
{
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    paths[1] = 0;
    q.push({ 1, 0, 0 });

    vector<int> topEl;
    int currKilosToLose;
    int currTime;
    while (!q.empty())
    {
        topEl = q.top();
        q.pop();

        if (!visited[topEl[0]])
        {
            visited[topEl[0]] = true;
            for (auto child : adj[topEl[0]])
            {
                currKilosToLose = max(topEl[1], child[1]);
                currTime = paths[topEl[0]] + child[2];
                if (!visited[child[0]] && currKilosToLose <= kilosToLose && currTime <= K)
                {
                    if (paths[topEl[0]] + child[2] < paths[child[0]])
                    {
                        paths[child[0]] = paths[topEl[0]] + child[2];
                        q.push({ child[0], currKilosToLose, paths[child[0]] });
                    }
                }
            }
        }
    }
}

void findMinKilos(vector<vector<vector<int>>>& adj, int K, int N)
{
    int left = minKilosInInput;
    int right = maxKilosInInput;

    int mid;
    int bestRes = maxKilosInInput;

    bool hasAnswer = false;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        visited.assign(N + 1, false);
        paths.assign(N + 1, inf);
        dijkstra(adj, K, mid);
        if (paths[N] != inf)         
        {
            right = mid - 1;
            hasAnswer = true;
            if (bestRes > mid)
                bestRes = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (!hasAnswer)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", bestRes);
    }
}

int main()
{
    int N, M, K; // K - battery life;
    scanf("%d %d %d", &N, &M, &K);

    vector<vector<vector<int>>> adj(N + 1);
    int u, v, c, t; // c - excessive kilos, t - time;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &u, &v, &c, &t);
        if (maxKilosInInput < c)
            maxKilosInInput = c;
        if (minKilosInInput > c)
            minKilosInInput = c;
        adj[u].push_back({ v, c, t });
    }

    findMinKilos(adj, K, N);

    return 0;
}
