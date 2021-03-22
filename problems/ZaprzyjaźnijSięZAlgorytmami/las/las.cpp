#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector<vector<int>> fieldsUsedTemplate;

    for (int i = 0; i < n; i++)
    {
        vector<int> zeros;
        for (int k = 0; k < n; k++)
        {
            zeros.push_back(0);
        }
        fieldsUsedTemplate.push_back(zeros);
    }

    vector<vector<int>> trees;
    int minTree = 1000000000;
    int maxTree = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int k = 0; k < n; k++)
        {
            int a;
            cin >> a;
            minTree = min(minTree, a);
            maxTree = max(maxTree, a);
            row.push_back(a);
        }
        trees.push_back(row);
    }

    int bestTree = maxTree;
    int beg = minTree;
    int end = maxTree;
    int treeSize;
    while (beg <= end)
    {
        treeSize = (beg + end) / 2;

        // Start working for given size
        vector<vector<int>> fieldsUsed(fieldsUsedTemplate);
        bool result = false;
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (fieldsUsed.at(i).at(k) == 0 && trees.at(i).at(k) <= treeSize)
                {
                    // conduct bfs
                    int propertySize = 0;
                    queue<pair<int, int>> q;
                    q.push(pair<int, int>(i, k));
                    while (!q.empty())
                    {
                        pair<int, int> top = q.front();
                        q.pop();

                        if (fieldsUsed.at(top.first).at(top.second) == 1)
                        {
                            continue;
                        }

                        propertySize++;
                        if (propertySize >= d)
                        {
                            result = true;
                            break;
                        }

                        fieldsUsed.at(top.first).at(top.second) = 1;

                        // Get right neighbour
                        if (top.second + 1 < n && fieldsUsed.at(top.first).at(top.second + 1) == 0 && trees.at(top.first).at(top.second + 1) <= treeSize)
                        {
                            q.push(pair<int, int>(top.first, top.second + 1));
                        }
                        // Get left neighbour
                        if (top.second - 1 >= 0 && fieldsUsed.at(top.first).at(top.second - 1) == 0 && trees.at(top.first).at(top.second - 1) <= treeSize)
                        {
                            q.push(pair<int, int>(top.first, top.second - 1));
                        }
                        // Get down neighbour
                        if (top.first + 1 < n && fieldsUsed.at(top.first + 1).at(top.second) == 0 && trees.at(top.first + 1).at(top.second) <= treeSize)
                        {
                            q.push(pair<int, int>(top.first + 1, top.second));
                        }
                        // Get top neighbour
                        if (top.first - 1 >= 0 && fieldsUsed.at(top.first - 1).at(top.second) == 0 && trees.at(top.first - 1).at(top.second) <= treeSize)
                        {
                            q.push(pair<int, int>(top.first - 1, top.second));
                        }
                    }
                }
            }
        }
        // Stop working for given size

        if (result)
        {
            bestTree = treeSize;
            end = treeSize - 1;
        }
        else
        {
            beg = treeSize + 1;
        }
    }

    cout << bestTree << endl;
}
