// #include <bits/stdc++.h>
// using namespace std;

// class Edge
// {
// public:
//     int u, v, c;
//     Edge(int u, int v, int c)
//     {
//         this->u = u;
//         this->v = v;
//         this->c = c;
//     }
// };

// const int N = 1005 * 1005; // 1e3+5
// int dis[N];
// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};
// int n, m;

// bool isValid(int x, int y, vector<vector<char>> &grid)
// {
//     return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.');
// }

// int getNodeIndex(int x, int y)
// {
//     return x * m + y;
// }

// int main()
// {
//     cin >> n >> m;

//     vector<vector<char>> grid(n, vector<char>(m));
//     vector<Edge> EdgeList;

//     // Input grid
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     int Si, Sj, Di, Dj;
//     cin >> Si >> Sj >> Di >> Dj;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (grid[i][j] == '.')
//             {
//                 int u = getNodeIndex(i, j);
//                 for (int k = 0; k < 4; k++)
//                 {
//                     int ni = i + dx[k];
//                     int nj = j + dy[k];
//                     if (isValid(ni, nj, grid))
//                     {
//                         int v = getNodeIndex(ni, nj);
//                         EdgeList.push_back(Edge(u, v, 1));
//                     }
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < N; i++)
//     {
//         dis[i] = INT_MAX;
//     }
//     int start = getNodeIndex(Si, Sj);
//     dis[start] = 0;

//     for (int i = 1; i <= n * m - 1; i++)
//     {
//         for (Edge ed : EdgeList)
//         {
//             int u = ed.u;
//             int v = ed.v;
//             int c = ed.c;
//             if (dis[u] < INT_MAX && dis[u] + c < dis[v])
//             {
//                 dis[v] = dis[u] + c;
//             }
//         }
//     }
//     int dest = getNodeIndex(Di, Dj);
//     if (dis[dest] == INT_MAX)
//     {
//         cout << "NO" << endl;
//     }
//     else
//     {
//         cout << "YES" << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Edge
// {
// public:
//     int u, v, c;
//     Edge(int u, int v, int c)
//     {
//         this->u = u;
//         this->v = v;
//         this->c = c;
//     }
// };

// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};
// int n, m;

// bool isValid(int x, int y, vector<vector<char>> &grid)
// {
//     return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.');
// }

// int getNodeIndex(int x, int y)
// {
//     return x * m + y;
// }

// int main()
// {
//     cin >> n >> m;

//     vector<vector<char>> grid(n, vector<char>(m));
//     vector<Edge> EdgeList;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     int Si, Sj, Di, Dj;
//     cin >> Si >> Sj >> Di >> Dj;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (grid[i][j] == '.')
//             {
//                 int u = getNodeIndex(i, j);
//                 for (int k = 0; k < 4; k++)
//                 {
//                     int ni = i + dx[k];
//                     int nj = j + dy[k];
//                     if (isValid(ni, nj, grid))
//                     {
//                         int v = getNodeIndex(ni, nj);
//                         EdgeList.push_back(Edge(u, v, 1));
//                     }
//                 }
//             }
//         }
//     }
//     vector<int> dis(n * m, INT_MAX);

//     int start = getNodeIndex(Si, Sj);
//     dis[start] = 0;
//     for (int i = 1; i <= n * m - 1; i++)
//     {
//         for (Edge ed : EdgeList)
//         {
//             int u = ed.u;
//             int v = ed.v;
//             int c = ed.c;
//             if (dis[u] < INT_MAX && dis[u] + c < dis[v])
//             {
//                 dis[v] = dis[u] + c;
//             }
//         }
//     }

//     int dest = getNodeIndex(Di, Dj);
//     if (dis[dest] == INT_MAX)
//     {
//         cout << "NO" << endl;
//     }
//     else
//     {
//         cout << "YES" << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int dx[] = {-1, 1, 0, 0}; // direction
int dy[] = {0, 0, -1, 1};
int n, m;

bool isValid(int x, int y, const vector<vector<char>> &grid)
{

    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.');
}

int getNodeIndex(int x, int y)
{
    return x * m + y;
}

int main()
{
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<Edge> EdgeList;

    // Input grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int Si, Sj, Di, Dj;
    cin >> Si >> Sj >> Di >> Dj;

    if (grid[Si][Sj] == '-' || grid[Di][Dj] == '-')
    {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                int u = getNodeIndex(i, j);
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (isValid(ni, nj, grid))
                    {
                        int v = getNodeIndex(ni, nj);
                        EdgeList.push_back(Edge(u, v, 1));
                    }
                }
            }
        }
    }

    vector<int> dis(n * m, INT_MAX);

    int start = getNodeIndex(Si, Sj);
    dis[start] = 0;

    int totalNodes = n * m;
    for (int i = 1; i <= totalNodes - 1; i++)
    {
        bool updated = false;
        for (Edge &ed : EdgeList)
        {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
                updated = true;
            }
        }

        if (!updated)
            break;
    }

    int dest = getNodeIndex(Di, Dj);
    if (dis[dest] == INT_MAX)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}
