#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char grid[N][N];
bool vis[N][N];
int n, m;
bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y];
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (auto dir : directions)
    {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (valid(newX, newY))
        {
            dfs(newX, newY);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int apartmentCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                apartmentCount++;
                dfs(i, j);
            }
        }
    }

    cout << apartmentCount << endl;

    return 0;
}
