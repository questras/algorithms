#include <iostream>
#include <vector>
using namespace std;

struct Temperature
{
    int low;
    int high;
};

class Point
{
public:
    int value;
    int howMany;

    Point(int v, int hm)
    {
        value = v;
        howMany = hm;
    }
};

class kMaxQueue
{
    vector<Point> elements;
    int first;
    int last;

public:
    kMaxQueue()
    {
        first = 0;
        last = -1;
    }

    Point getFirst()
    {
        return elements.at(first);
    }

    Point getLast()
    {
        return elements.at(last);
    }

    bool isEmpty()
    {
        return first > last;
    }

    void remove_first()
    {
        if (!isEmpty())
            first++;
    }

    void remove_last()
    {
        if (!isEmpty())
        {
            elements.pop_back();
            last--;
        }
    }

    void add_last(int v, int hm)
    {
        last++;
        elements.push_back(Point(v, hm));
    }

    void add(int v)
    {
        int hm = 0;
        while (!isEmpty() && getLast().value <= v)
        {
            hm += getLast().howMany + 1;
            remove_last();
        }
        add_last(v, hm);
    }

    void remove()
    {
        if (getFirst().howMany == 0)
        {
            remove_first();
        }
        else
        {
            elements.at(first).howMany--;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    struct Temperature temps[n];
    for (int i = 0; i < n; i++)
    {
        struct Temperature t;
        cin >> t.low >> t.high;
        temps[i] = t;
    }

    int result = 0;
    kMaxQueue queue = kMaxQueue();
    int current = 1;
    int end = -1;

    for (int i = 0; i < n; i++)
    {
        if (queue.isEmpty())
        {
            queue.add(temps[i].low);
            end++;
            current = 1;
        }

        while (end + 1 < n && queue.getFirst().value <= temps[end + 1].high)
        {
            queue.add(temps[end + 1].low);
            end++;
            current++;
        }
        result = max(result, current);
        current--;
        queue.remove();
    }

    cout << result << endl;
}
