#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int> &chocolates, int N)
{
    int total_sum = 0;
    for (int i = 0; i < N; ++i)
    {
        total_sum += chocolates[i];
    }
    if (total_sum % 2 != 0)
    {
        return false;
    }

    int target = total_sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < N; ++i)
    {
        for (int j = target; j >= chocolates[i]; --j)
        {
            dp[j] = dp[j] || dp[j - chocolates[i]];
        }
    }

    return dp[target];
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> chocolates(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> chocolates[i];
        }

        if (canPartition(chocolates, N))
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