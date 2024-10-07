#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char grid[N][N];
bool visited[N][N];
int n, m;
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y]);
}
int dfs(int x, int y)
{
    visited[x][y] = true;
    int area = 1;

    for (int i = 0; i < 4; i++)
    {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        if (is_valid(newX, newY))
        {
            area += dfs(newX, newY);
        }
    }

    return area;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    int min_area = INT_MAX;
    bool found_component = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {

                int area = dfs(i, j);
                min_area = min(min_area, area);
                found_component = true;
            }
        }
    }

    if (found_component)
    {
        cout << min_area << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}