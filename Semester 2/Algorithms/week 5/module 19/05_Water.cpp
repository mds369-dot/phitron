#include <bits/stdc++.h>
using namespace std;

void findContainerWithMostWater(int N, const vector<int> &heights)
{
    int left = 0, right = N - 1;
    int maxArea = 0;
    int bestLeft = 0, bestRight = 0;

    while (left < right)
    {
        int height = min(heights[left], heights[right]);
        int width = right - left;
        int currentArea = height * width;

        if (currentArea > maxArea)
        {
            maxArea = currentArea;
            bestLeft = left;
            bestRight = right;
        }
        if (heights[left] < heights[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << bestLeft << " " << bestRight << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> heights(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> heights[i];
        }
        findContainerWithMostWater(N, heights);
    }
    return 0;
}
