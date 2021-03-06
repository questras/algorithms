#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
    int position;
    long long int value;
};

bool comparePoints(struct Point a, struct Point b)
{
    if (a.value != b.value)
    {
        return a.value < b.value;
    }

    return a.position < b.position;
}

bool comparePointsNegative(struct Point a, struct Point b)
{
    if (a.value != b.value)
    {
        return a.value > b.value;
    }

    return a.position > b.position;
}

int main()
{
    int n, s;
    cin >> n >> s;

    int values[n];
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    long long int *prefixes = new long long int[n + 1];
    prefixes[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        prefixes[i] = prefixes[i - 1] + values[i - 1];
    }

    struct Point points[n + 1];

    struct Point firstPoint;
    firstPoint.position = 0;
    firstPoint.value = 0;
    points[0] = firstPoint;

    for (int i = 1; i < n + 1; i++)
    {
        struct Point p;
        p.position = i;
        p.value = prefixes[i];
        points[i] = p;
    }

    int beg = 0, end = 0;
    int result = 0;
    if (s < 0)
    {
        sort(points, points + n + 1, comparePointsNegative);
        while (beg < n + 1)
        {
            if (beg == end)
            {
                if (beg == n)
                {
                    beg++;
                }
                else
                {
                    end = min(end + 1, n);
                }
            }
            else
            {
                long long int diff = points[end].value - points[beg].value;

                if (diff >= s)
                {
                    if (diff == s)
                    {
                        result = max(result, points[end].position - points[beg].position);
                    }
                    end++;

                    if (end == n + 1)
                    {
                        break;
                    }
                }
                else
                {
                    beg++;
                }
            }
        }
    }
    else
    {
        sort(points, points + n + 1, comparePoints);
        while (beg < n + 1)
        {
            if (beg == end)
            {
                if (beg == n)
                {
                    beg++;
                }
                else
                {
                    end = min(end + 1, n);
                }
            }
            else
            {
                long long int diff = points[end].value - points[beg].value;

                if (diff <= s)
                {
                    if (diff == s)
                    {
                        result = max(result, points[end].position - points[beg].position);
                    }
                    end++;

                    if (end == n + 1)
                    {
                        break;
                    }
                }
                else
                {
                    beg++;
                }
            }
        }
    }

    if (result == 0)
    {
        cout << "BRAK" << endl;
    }
    else
    {
        cout << result << endl;
    }
}
