#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int n, m;
char grid[1000][1000];
bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
bool bfs(pair<int, int> start, pair<int, int> end)
{
    queue<pair<int, int>> q;
    q.push(start);
    grid[start.first][start.second] = '#';

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;
        if (current == end)
        {
            return true;
        }
        for (const auto &direction : directions)
        {
            int nx = x + direction.first;
            int ny = y + direction.second;
            if (valid(nx, ny) && grid[nx][ny] != '#')
            {
                q.push({nx, ny});
                grid[nx][ny] = '#';
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;

    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }
    if (bfs(start, end))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
