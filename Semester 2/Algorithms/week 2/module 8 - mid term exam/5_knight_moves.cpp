#include <bits/stdc++.h>
using namespace std;
const int knightMoves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
bool isValid(int x, int y, int N, int M)
{
    return (x >= 0 && x < N && y >= 0 && y < M);
}
int minKnightMoves(int N, int M, int Ki, int Kj, int Qi, int Qj)
{
    if (Ki == Qi && Kj == Qj)
    {
        return 0;
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<pair<pair<int, int>, int>> q;
    q.push({{Ki, Kj}, 0});
    visited[Ki][Kj] = true;

    while (!q.empty())
    {
        auto current = q.front();
        int x = current.first.first;
        int y = current.first.second;
        int dist = current.second;
        q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int newX = x + knightMoves[i][0];
            int newY = y + knightMoves[i][1];
            if (isValid(newX, newY, N, M) && !visited[newX][newY])
            {
                if (newX == Qi && newY == Qj)
                {
                    return dist + 1;
                }
                visited[newX][newY] = true;
                q.push({{newX, newY}, dist + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        int Ki, Kj;
        cin >> Ki >> Kj;

        int Qi, Qj;
        cin >> Qi >> Qj;

        cout << minKnightMoves(N, M, Ki, Kj, Qi, Qj) << endl;
    }

    return 0;
}
