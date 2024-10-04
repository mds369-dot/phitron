#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int grp_size[N];
void dsu_inz(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        grp_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    return par[node] = dsu_find(par[node]);
}
bool dsu_U_by_size(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA == leaderB)
    {
        return false;
    }
    if (grp_size[leaderA] > grp_size[leaderB])
    {
        par[leaderB] = leaderA;
        grp_size[leaderA] += grp_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        grp_size[leaderB] += grp_size[leaderA];
    }
    return true;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    dsu_inz(n);

    int totalCosts = 0;
    int edgesUsed = 0;
    for (auto &edge : edges)
    {
        int c = edge.first;
        int a = edge.second.first;
        int b = edge.second.second;

        if (dsu_U_by_size(a, b))
        {
            totalCosts += c;
            edgesUsed++;
        }
    }
    if (edgesUsed == n - 1)
    {
        cout << totalCosts << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}