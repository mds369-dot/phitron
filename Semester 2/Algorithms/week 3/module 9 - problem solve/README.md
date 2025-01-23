# Module 9 (leetcode)

## 463. Island Perimeter

[Problem Set 1](https://leetcode.com/problems/island-perimeter/description/)

### Island Perimeter

```
class Solution
{
public:
    bool vis[105][105];
    int ans;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    int n, m;
    bool valid(int ci, int cj)
    {
        if (ci >= 0 && ci < n && cj >= 0 && cj < m)
            return true;
        else
            return false;
    }
    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj))
            {
                if (grid[ci][cj] == 0)
                    ans++;
            }
            else
            {
                ans++;
            }
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        memset(vis, false, sizeof(vis));
        ans = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
```

## 1971. Find if Path Exists in Graph

[Problem Set 2](https://leetcode.com/problems/find-if-path-exists-in-graph/description/)

### Find if Path Exist in Graph

```
class Solution
{
public:
    vector<int> v[200005];
    bool vis[200005];
    void dfs(int s)
    {
        vis[s] = true;
        for (int child : v[s])
        {
            if (!vis[child])
            {
                dfs(child);
            }
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int d)
    {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(source);
        return vis[d];
    }
};
```

## 695. Max Area of Island

[Problem Set 3](https://leetcode.com/problems/max-area-of-island/)

### Max Area of Island

```
class Solution
{
public:
    bool vis[55][55];
    int ans;
    int n, m;
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int ci, int cj)
    {
        if (ci >= 0 && ci < n && cj >= 0 && cj < m)
            return true;
        else
            return false;
    }
    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;
        ans++;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    ans = 0;
                    dfs(i, j, grid);
                    mx = max(mx, ans);
                }
            }
        }
        return mx;
    }
};
```

## 200. Number of Islands

[Problem Set 4](https://leetcode.com/problems/number-of-islands/)

### Number of Islands

```
class Solution
{
public:
    int n, m;
    bool vis[305][305];
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int ci, int cj)
    {
        if (ci >= 0 && ci < n && cj >= 0 && cj < m)
            return true;
        else
            return false;
    }
    void dfs(int si, int sj, vector<vector<char>> &grid)
    {
        vis[si][sj] = true;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '1')
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(vis, false, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

## 1905. Count Sub Islands

[Problem Set 5](https://leetcode.com/problems/count-sub-islands/description/)

### Count Sub Islands

```
class Solution
{
public:
    int n, m;
    bool vis[505][505];
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool valid(int ci, int cj)
    {
        if (ci >= 0 && ci < n && cj >= 0 && cj < m)
            return true;
        else
            return false;
    }
    bool flag;
    void dfs(int si, int sj, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        vis[si][sj] = true;
        if (grid1[si][sj] == 0)
            flag = false;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid2[ci][cj] == 1)
            {
                dfs(ci, cj, grid1, grid2);
            }
        }
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        memset(vis, false, sizeof(vis));
        n = grid2.size();
        m = grid2[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid2[i][j] == 1)
                {
                    flag = true;
                    dfs(i, j, grid1, grid2);
                    if (flag == true)
                        ans++;
                }
            }
        }
        return ans;
    }
};
```

## 1254. Number of Closed Islands

[Problem Set 6](https://leetcode.com/problems/number-of-closed-islands/)

### Number of Closed Islands

```
class Solution {
public:
    bool check(vector<vector<int>>&grid,vector<vector<int>>&visted,int i,int j)
    {
        if(grid[i][j]==1)
        {
            return false;
        }
        visted[i][j]=true;
        int left=true;
        int right=true;
        int down=true;
        int up=true;
        if(j-1>=0&&grid[i][j-1]!=0&&visted[i][j-1]==false)
        {
            left=check(grid,visted,i,j-1);
        }
        if(j+1<grid[0].size()&&grid[i][j+1]!=0&&visted[i][j+1]==false)
        {
            right=check(grid,visted,i,j+1);
        }
        if(i+1<grid.size()&&grid[i+1][j]!=0&&visted[i+1][j]==false)
        {
            down=check(grid,visted,i+1,j);
        }
        if(i-1>=0&&grid[i-1][j]!=0&&visted[i-1][j]==false)
        {
            up=check(grid,visted,i-1,j);
        }
        return up&&down&&right&&left;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        for(int i=0;i<grid1.size();i++)
        {
            for(int j=0;j<grid2[0].size();j++)
            {
                if(grid1[i][j]==grid2[i][j]&&grid1[i][j]==1)
                {
                    grid2[i][j]=5;
                }
            }
        }
        int rows = grid1.size();
        int cols = grid1[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, false));
        int count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid2[i][j] == 5 && !visited[i][j]) {

                    if (check(grid2, visited, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
```
