#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int highways[n];
    for (int i = 0; i < n; i++)
    {
        cin >> highways[i];
    }

    int bestRoadPerHighwayLast[n];
    int bestRoadPerHighway[n];

    // Without highways, you can only travel from previous city.
    for (int i = 0; i < n; i++)
    {
        bestRoadPerHighway[i] = i;
        bestRoadPerHighwayLast[i] = i;
    }

    vector<int> highwayBeginning[n];
    for (int i = 0; i < n; i++)
    {
        if (highways[i] != -1)
        {
            highwayBeginning[highways[i]].push_back(i);
        }
    }

    for (int i = 1; i < k + 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            bestRoadPerHighway[j] = bestRoadPerHighwayLast[j];

            for (int l = 0; l < highwayBeginning[j].size(); l++)
            {
                bestRoadPerHighway[j] = min(bestRoadPerHighway[j], bestRoadPerHighwayLast[highwayBeginning[j].at(l)] + 1);
            }
        }

        for (int j = 1; j < n; j++)
        {
            bestRoadPerHighway[j] = min(bestRoadPerHighway[j], bestRoadPerHighway[j - 1] + 1);
            bestRoadPerHighwayLast[j] = bestRoadPerHighway[j];
        }
    }

    cout << bestRoadPerHighway[n - 1] << endl;
}
