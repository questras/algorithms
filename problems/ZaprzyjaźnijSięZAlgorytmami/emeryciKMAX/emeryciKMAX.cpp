#include<iostream>
#include<vector>
using namespace std;

class Point {
    public:
    int value;
    int howMany;

    Point(int v, int hm) {
        value = v;
        howMany = hm;
    }
};

class kmaxQueue {
    public:
        vector<Point> points;
        int first;
        int last;

        kmaxQueue() {
            first = 0;
            last = -1;
        }

        bool isEmpty() {
            return last < first;
        }

        Point getFirst() {
            return points.at(first);
        }

        Point getSecond() {
            return points.at(first + 1);
        }

        Point getLast() {
            return points.at(last);
        }

        void removeFirst() {
            if (!isEmpty())
                first++;
        }

        void removeLast() {
            if (!isEmpty()) {
                points.pop_back();
                last--;
            }
        }

        void remove() {
            if (getFirst().howMany == 0) {
                removeFirst();
            }
            else {
                points.at(first).howMany--;
            }
        }

        void addLast(Point p) {
            last++;
            points.push_back(p);
        }

        void add(int v) {
            int hm = 0;
            while(!isEmpty() && v >= getLast().value) {
                hm += getLast().howMany + 1;
                removeLast();
            }

            addLast(Point(v, hm));
        }
};


int main() {
    int n, k;
    cin>>n>>k;

    int t[n];
    for (int i = 0; i < n; i++)
    {
        cin>>t[i];
    }

    int firstBest = 0;
    int secondBest = 0;
    kmaxQueue q = kmaxQueue();

    for (int i = 0; i < k + 1; i++)
    {
        if (t[i] > firstBest) {
            secondBest = firstBest;
            firstBest = t[i];
        }
        else if (t[i] > secondBest) {
            secondBest = t[i];
        }

        q.add(t[i]);
    }

    
}
