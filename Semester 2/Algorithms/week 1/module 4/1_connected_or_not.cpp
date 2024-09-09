#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<int>> conn(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        conn[u][v] = 1;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "YES" << endl;
        }
        else if (conn[a][b] == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}