#include <bits/stdc++.h>
using namespace std;
int knapsack(int N, int W, vector<int> &weights, vector<int> &values)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][W];
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, W;
        cin >> N >> W;

        vector<int> weights(N);
        vector<int> values(N);

        for (int i = 0; i < N; i++)
        {
            cin >> weights[i];
        }

        for (int i = 0; i < N; i++)
        {
            cin >> values[i];
        }
        cout << knapsack(N, W, weights, values) << endl;
    }
    return 0;
}