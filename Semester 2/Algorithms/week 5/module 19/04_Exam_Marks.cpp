#include <bits/stdc++.h>
using namespace std;
bool canAchieveTarget(int target, const vector<int> &marks)
{
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int mark : marks)
    {
        for (int j = target; j >= mark; --j)
        {
            dp[j] = dp[j] || dp[j - mark];
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
        int N, M;
        cin >> N >> M;
        vector<int> marks(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> marks[i];
        }

        int target = 1000 - M;

        if (target <= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            if (canAchieveTarget(target, marks))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}