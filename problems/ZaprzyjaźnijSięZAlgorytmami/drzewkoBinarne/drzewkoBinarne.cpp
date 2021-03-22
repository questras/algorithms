#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int arrSize = pow(2, k);

    long long int treeArr[arrSize];

    cin >> treeArr[1];

    for (int i = 2; i < arrSize; i++)
    {
        cin >> treeArr[i];
        treeArr[i] += treeArr[i / 2];
    }

    long long int result = LONG_LONG_MAX;

    for (int i = arrSize - pow(2, k - 1); i < arrSize; i++)
    {
        result = min(result, treeArr[i]);
    }

    cout << result << endl;
}
