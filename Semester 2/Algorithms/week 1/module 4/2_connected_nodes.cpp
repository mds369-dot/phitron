#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> node(n);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;

        if (node[x].empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            sort(node[x].begin(), node[x].end(), greater<int>());
            for (int next : node[x])
            {
                cout << next << " ";
            }
            cout << endl;
        }
    }
    return 0;
}