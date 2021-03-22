#include <iostream>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;

    int result = 0;
    long long int currentSum = 0;

    int twine;
    for (int i = 0; i < n; i++)
    {
        cin >> twine;
        currentSum += (long long int)twine;

        if (currentSum >= w)
        {
            result++;
            currentSum = 0;
        }
    }

    cout << result << endl;
}
