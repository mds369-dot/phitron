#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<vector<int>> &grid, vector<vector<int>> &visted, int i, int j)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
        visted[i][j] = true;
        int left = true;
        int right = true;
        int down = true;
        int up = true;
        if (j - 1 >= 0 && grid[i][j - 1] != 0 && visted[i][j - 1] == false)
        {
            left = check(grid, visted, i, j - 1);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] != 0 && visted[i][j + 1] == false)
        {
            right = check(grid, visted, i, j + 1);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] != 0 && visted[i + 1][j] == false)
        {
            down = check(grid, visted, i + 1, j);
        }
        if (i - 1 >= 0 && grid[i - 1][j] != 0 && visted[i - 1][j] == false)
        {
            up = check(grid, visted, i - 1, j);
        }
        return up && down && right && left;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {

        for (int i = 0; i < grid1.size(); i++)
        {
            for (int j = 0; j < grid2[0].size(); j++)
            {
                if (grid1[i][j] == grid2[i][j] && grid1[i][j] == 1)
                {
                    grid2[i][j] = 5;
                }
            }
        }
        int rows = grid1.size();
        int cols = grid1[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, false));
        int count = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid2[i][j] == 5 && !visited[i][j])
                {

                    if (check(grid2, visited, i, j))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};