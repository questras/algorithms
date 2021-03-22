#include <iostream>
#include <vector>
using namespace std;

void dfs(int ids[], vector<int> neighbours[], int v, int currentID)
{
    if (ids[v] == -1)
    {
        ids[v] = currentID;
        for (int i = 0; i < neighbours[v].size(); i++)
        {
            dfs(ids, neighbours, neighbours[v].at(i), currentID);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int ids[n + 1];
    vector<int> neighbours[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        ids[i] = -1;
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }

    for (int i = 1; i < n + 1; i++)
    {
        dfs(ids, neighbours, i, i);
    }

    int z;
    cin >> z;
    for (int i = 0; i < z; i++)
    {
        int x, y;
        cin >> x >> y;

        if (ids[x] == ids[y])
        {
            cout << "TAK" << endl;
        }
        else
        {
            cout << "NIE" << endl;
        }
    }
}
