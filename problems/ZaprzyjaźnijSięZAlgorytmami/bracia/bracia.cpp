#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool vectorSortFunc(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;

    pair<int, int> begsAndEnds[1000001];
    for (int i = 0; i < 1000001; i++)
    {
        begsAndEnds[i].first = -1;
        begsAndEnds[i].second = -1;
    }

    int brothers[n];
    for (int i = 0; i < n; i++)
    {
        cin >> brothers[i];

        if (begsAndEnds[brothers[i]].first == -1)
        {
            begsAndEnds[brothers[i]].first = i;
            begsAndEnds[brothers[i]].second = i;
        }
        else
        {
            begsAndEnds[brothers[i]].second = i;
        }
    }

    vector<pair<int, int>> begsAndEndsVec;
    for (int i = 0; i < 1000001; i++)
    {
        if (begsAndEnds[i].first != -1)
        {
            begsAndEndsVec.push_back(begsAndEnds[i]);
        }
    }

    sort(begsAndEndsVec.begin(), begsAndEndsVec.end(), vectorSortFunc);

    if (begsAndEndsVec.size() == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        int result = 1;
        int lastSiblings = 0;
        for (int i = 1; i < begsAndEndsVec.size(); i++)
        {
            if (begsAndEndsVec.at(lastSiblings).second < begsAndEndsVec.at(i).first)
            {
                result++;
                lastSiblings = i;
            }
        }

        cout << result << endl;
    }
}
