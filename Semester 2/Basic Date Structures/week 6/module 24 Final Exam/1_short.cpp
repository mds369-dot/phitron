#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        set<int> uniqueValues;

        for (int i = 0; i < n; ++i)
        {
            int value;
            cin >> value;
            uniqueValues.insert(value);
        }
        vector<int> sortedValues(uniqueValues.begin(), uniqueValues.end());
        for (size_t i = 0; i < sortedValues.size(); ++i)
        {
            if (i > 0)
                cout << " ";
            cout << sortedValues[i];
        }
        cout << endl;
    }

    return 0;
}
