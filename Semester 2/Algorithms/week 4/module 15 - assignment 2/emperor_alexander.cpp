// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int par[N];
// int grp_size[N];
// void dsu_inz(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         par[i] = -1;
//         grp_size[i] = 1;
//     }
// }
// int dsu_find(int node)
// {
//     if (par[node] == -1)
//     {
//         return node;
//     }
//     return par[node] = dsu_find(par[node]);
// }
// bool dsu_U(int a, int b)
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA == leaderB)
//     {
//         return false;
//     }
//     if (grp_size[leaderA] > grp_size[leaderB])
//     {
//         par[leaderB] = leaderA;
//         grp_size[leaderA] += grp_size[leaderB];
//     }
//     else
//     {
//         par[leaderA] = leaderB;
//         grp_size[leaderB] += grp_size[leaderA];
//     }
//     return true;
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     vector<tuple<int, int, int>> edges;
//     for (int i = 0; i < e; i++)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         edges.push_back({w, a, b});
//     }
//     sort(edges.begin(), edges.end());
//     dsu_inz(n);
//     int totalCost = 0;
//     int edgesUsed = 0;

//     for (auto &edge : edges)
//     {
//         int w = get<0>(edge);
//         int a = get<1>(edge);
//         int b = get<2>(edge);

//         if (dsu_U(a, b))
//         {
//             totalCost += w;
//             edgesUsed++;
//         }
//     }
//     if (edgesUsed != n - 1)
//     {
//         cout << "Not Possible" << endl;
//     }
//     else
//     {
//         int rRoads = e - edgesUsed;
//         cout << rRoads << " " << totalCost << endl;
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int findParent(int u, vector<int> &parent)
{
    if (parent[u] == u)
        return u;
    return parent[u] = findParent(parent[u], parent); // Path compression
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV)
    {
        if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<Edge> edges(E);

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by their weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });

    // Union-Find (Disjoint Set) structures
    vector<int> parent(N + 1), rank(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    int mstCost = 0;
    int mstEdges = 0;
    vector<Edge> mst;

    for (auto &edge : edges)
    {
        if (findParent(edge.u, parent) != findParent(edge.v, parent))
        {
            mstCost += edge.weight;
            mstEdges++;
            unionSets(edge.u, edge.v, parent, rank);
        }
        mst.push_back(edge);
    }
    if (mstEdges != N - 1)
    {
        cout << "Not Possible" << endl;
    }
    else
    {
        cout << (E - (N - 1)) << " " << mstCost << endl;
    }

    return 0;
}
