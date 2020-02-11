#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define x topEl.first
#define y topEl.second

using namespace std;

vector<int> dx = { 1, -1, 0, 0 };
vector<int> dy = { 0, 0, 1, -1 };

bool isValid(int i, int j, vector<vector<bool>>& matrix)
{
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
        return false;
    return matrix[i][j];
}

int bfs(int sx, int sy, int ex, int ey, vector<vector<bool>>& matrix)
{
    vector<vector<bool>> used(matrix.size(), vector<bool>(matrix[0].size()));
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    used[sx][sy] = true;
    int res = 0;

    int tempSize = 1;
    while (!q.empty())
    {
        pair<int, int> topEl = q.front();
        q.pop();
        tempSize--;

        if (x == ex && y == ey)
            return res;

        for (int i = 0; i < 4; i++)
        {
            if (isValid(x + dx[i], y + dy[i], matrix) && !used[x + dx[i]][y + dy[i]])
            {
                used[x + dx[i]][y + dy[i]] = true;
                q.push({ x + dx[i], y + dy[i] });
            }
        }

        int tempX, tempY;
        for (int i = 0; i < 4; i++)
        {
            tempX = x + dx[i];
            tempY = y + dy[i];
            while (isValid(tempX, tempY, matrix))
            {
                tempX += dx[i];
                tempY += dy[i];
            }

            tempX -= dx[i];
            tempY -= dy[i];
            if (!used[tempX][tempY])
            {
                used[tempX][tempY] = true;
                q.push({ tempX, tempY });
            }
        }

        if (!tempSize)
        {
            tempSize = q.size();
            res++;
        }
    }
    return -1;
}

int main()
{
    int N;
    int M;
    cin >> N >> M;
    int sX, sY, eX, eY; // start and end points;
    char temp;
    vector<vector<bool>> matrix(N, vector<bool>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> temp;
            if (temp == '.')            
                matrix[i][j] = true;            
            else if (temp == '#')
                matrix[i][j] = false;
            else if (temp == 'S')
            {
                matrix[i][j] = true;
                sX = i;
                sY = j;
            }
            if (temp == 'F')
            {
                matrix[i][j] = true;
                eX = i;
                eY = j;
            }            
        }
    }

    int result = bfs(sX, sY, eX, eY, matrix);
    cout << result;

    return 0;
}
