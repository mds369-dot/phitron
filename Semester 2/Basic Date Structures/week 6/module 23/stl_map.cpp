#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    // mp.insert({"Sakib Al Hasan", 75});
    // mp.insert({"Tamim Iqbal", 19});
    // mp.insert({"Rahat", 100});
    // mp.insert({"Shamim", 75});
    mp["Sakib al hasan"] = 79; // O(logN)
    mp["akib"] = 100;
    mp["tamim"] = 79;

    // if (mp.count("Shamim"))
    // {
    //     cout << "Ase" << endl;
    // }
    // else
    // {
    //     cout << "Nai" << endl;
    // }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl; // O(logN)
    }
    cout << mp["akib"] << endl;
    return 0;
}