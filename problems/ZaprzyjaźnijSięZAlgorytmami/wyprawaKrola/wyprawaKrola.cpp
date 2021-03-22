#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> citiesFromMe[k + 1][n + 1];

    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        for (int j = 0; j < k + 1; j++)
        {
            citiesFromMe[j][from].push_back(pair<int, int>(j, to));
        }
        for (int j = 1; j < k + 1; j++)
        {
            citiesFromMe[j - 1][to].push_back(pair<int, int>(j, from));
        }
    }

    int howManyRoadsWithChanges[k + 1][n + 1];

    for (int i = 0; i < k + 1; i++)
    {
        for (int l = 0; l < n + 1; l++)
        {
            howManyRoadsWithChanges[i][l] = -1;
        }
    }

    for (int i = 0; i < k + 1; i++)
    {
        howManyRoadsWithChanges[i][1] = 0;
    }

    queue<pair<int, int>> q;
    q.push(pair<int, int>(0, 1));

    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();

        for (int i = 0; i < citiesFromMe[top.first][top.second].size(); i++)
        {
            pair<int, int> neighbour = citiesFromMe[top.first][top.second].at(i);
            int neighbourK = neighbour.first;
            int neighbourN = neighbour.second;
            if (howManyRoadsWithChanges[neighbourK][neighbourN] == -1)
            {
                q.push(neighbour);
                howManyRoadsWithChanges[neighbourK][neighbourN] = howManyRoadsWithChanges[top.first][top.second] + 1;
            }
        }
    }

    int result = howManyRoadsWithChanges[0][n];
    for (int i = 1; i < k + 1; i++)
    {
        if (howManyRoadsWithChanges[i][n] > 0)
            result = min(result, howManyRoadsWithChanges[i][n]);
    }

    cout << result << endl;
}
