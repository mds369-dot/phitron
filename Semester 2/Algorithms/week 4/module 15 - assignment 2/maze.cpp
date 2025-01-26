#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> maze;
vector<int> parent;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    q.push({startX, startY});
    visited[startX][startY] = true;
    parent[startX * M + startY] = -1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (maze[x][y] == 'D')
        {
            return true;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                parent[nx * M + ny] = x * M + y;
            }
        }
    }
    return false;
}
void markPath(int exitX, int exitY, int startX, int startY)
{
    int cur = exitX * M + exitY;
    while (cur != -1)
    {
        int x = cur / M;
        int y = cur % M;
        if (maze[x][y] != 'D' && maze[x][y] != 'R')
        {
            maze[x][y] = 'X';
        }
        cur = parent[cur];
    }
}

int main()
{
    cin >> N >> M;
    maze.resize(N);
    parent.resize(N * M, -1);

    int startX = -1, startY = -1;

    for (int i = 0; i < N; i++)
    {
        cin >> maze[i];
        for (int j = 0; j < M; j++)
        {
            if (maze[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
        }
    }

    if (bfs(startX, startY))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (maze[i][j] == 'D')
                {
                    markPath(i, j, startX, startY);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << maze[i] << endl;
    }

    return 0;
}
