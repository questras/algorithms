#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    long long int left = 0;
    long long int right = pow(2, (k - 1)) - 1;

    int current = n;
    if (n > (right + 1))
    {
        current = (n % (right + 1));
        if (current == 0)
        {
            current = (right + 1);
        }
    }

    while (current != 1)
    {
        if (current % 2 == 0)
        {
            left = ((left + right) / 2) + 1;
        }
        else
        {
            right = (left + right) / 2;
        }

        current = (current + 1) / 2;
    }

    cout << left << endl;
}
