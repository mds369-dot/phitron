#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string S;
        getline(cin, S);

        map<string, int> wordCount;
        stringstream ss(S);
        string word;
        string maxWord;
        int maxCount = 0;

        while (ss >> word)
        {
            wordCount[word]++;
            if (wordCount[word] > maxCount)
            {
                maxCount = wordCount[word];
                maxWord = word;
            }
        }

        cout << maxWord << " " << maxCount << endl;
    }

    return 0;
}
