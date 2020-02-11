#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int x;
    int y;

    Point(int x = -1, int y = -1) :
        x(x), y(y){}

    void setPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool isValid(const int row, const int col,
    vector<vector<int>>& diseased, const int N, const int M)
{
    if (row < 0 || row >= N || col < 0 || col >= M) // is outside matrix
        return false;
    if (diseased[row][col] != -1) // is already diseased
        return false;
    return true;
}

void bfs(queue<Point>& q, vector<vector<int>>& diseased, const int N, const int M)
{
    int directions1[] = {1, 0, 0, -1};
    int directions2[] = {0, 1, -1, 0};

    int counter = 0; // wave of disease;
    Point p;
    Point temp;
    int row, col;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (diseased[p.x][p.y] == counter)
            counter++;
        for (int i = 0; i < 4; i++)
        {
            row = p.x + directions1[i];
            col = p.y + directions2[i];
            if (isValid(row, col, diseased, N, M))
            {
                temp.setPoint(row, col);
                q.push(temp);
                diseased[row][col] = counter;
            }
        }
    }
}

int countGoodApples(const int N, const int M, const vector<vector<int>>& diseased, const int T)
{
    int numGoodApples = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(diseased[i][j] > T)
                numGoodApples++;
        }
    }

    return numGoodApples;
}

int main()
{
    int N; // rows
    int M; // columns
    int T; // after T days;
    cin >> N >> M >> T;

    int x; // row of the rotten apple;
    int y; // column of the rotten apple;

    // here we will save on which day an apple becomes diseased
    vector<vector<int>> diseased(N);

    for (int i = 0; i < N; i++)
    {
        diseased[i] = vector<int>(M, -1);
    }

    queue<Point> q;
    while (cin >> x >> y)
    {        
        Point rotApple(N - x,y - 1);
        diseased[N-x][y-1] = 0; // they are diseased from day 0;
        q.push(rotApple);
    }

    bfs(q, diseased, N, M);

    int result = countGoodApples(N, M, diseased, T);
    cout << result;

    return 0;
}
