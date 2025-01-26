#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char grid[N][N];
bool vis[N][N];
int n, m;
bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !vis[x][y];
}

int dfs(int x, int y)
{
    vis[x][y] = true;
    int roomCount = 1;

    for (auto dir : directions)
    {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (isValid(newX, newY))
        {
            roomCount += dfs(newX, newY);
        }
    }

    return roomCount;
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

    vector<int> apartmentRooms;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int rooms = dfs(i, j);
                apartmentRooms.push_back(rooms);
            }
        }
    }
    sort(apartmentRooms.begin(), apartmentRooms.end());
    if (apartmentRooms.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        for (int count : apartmentRooms)
        {
            cout << count << " ";
        }
        cout << endl;
    }

    return 0;
}
