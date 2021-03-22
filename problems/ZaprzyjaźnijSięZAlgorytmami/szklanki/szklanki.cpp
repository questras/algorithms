#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int sumOfAll = 0;

    int water[n];
    for (int i = 0; i < n; i++)
    {
        cin >> water[i];
        sumOfAll += water[i];
    }

    long long int desiredWaterLevel = sumOfAll / n;

    int result = 0;
    long long int last = 0;
    long long int current;
    for (int i = 0; i < n; i++)
    {
        current = (water[i] - desiredWaterLevel) + last;

        if (current != 0)
        {
            result++;
        }
        last = current;
    }

    cout << result << endl;
}
