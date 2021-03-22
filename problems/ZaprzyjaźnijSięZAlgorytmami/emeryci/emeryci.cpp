#include<iostream>
using namespace std;

class Heap {
    public:
        int t[500000];
        bool deleted[10000000];
        int last;

        Heap() {
            last = 0;
            for (int i = 0; i < 10000000; i++)
            {
                deleted[i] = false;
            }
        }

        bool isEmpty() {
            return last == 0;
        }

        int getMax() {
            if (isEmpty()) {
                return -1;
            }
            else {
                return t[1];
            }
        }

        void add(int value) {
            last++;
            t[last] = value;

            int w = last;
            while (w > 1 && t[w / 2] < t[w]) {
                swap(t[w / 2], t[w]);
                w /= 2;
            }
        }

        void removeMax() {
            t[1] = t[last];
            last--;

            restore(1);

            if (!isEmpty() && deleted[t[1]]) {
                removeMax();
                deleted[t[1]] = false;
            }
        }

        void restore(int i) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int maks = i;

            if (left <= last && t[left] > t[maks]) {
                maks = left;
            }
            if (right <= last && t[right] > t[maks]) {
                maks = right;
            }

            if (maks > i) {
                swap(t[maks], t[i]);
                restore(maks);
            }
        }

        void removeItem(int value) {
            if (getMax() == value) {
                removeMax();
            }
            else {
                deleted[value] = true;
            }
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
    
    Heap h = Heap();
    
    for (int i = 0; i < k + 1; i++)
    {
        h.add(t[i]);   
    }

    long long int firstBest = h.getMax();
    h.removeMax();
    long long int secondBest = h.getMax();
    h.add(firstBest);
    long long int result = firstBest + secondBest;

    for (int i = k + 1; i < n; i++)
    {
        h.removeItem(t[i - k - 1]);
        h.add(t[i]);


        firstBest = h.getMax();
        h.removeMax();
        secondBest = h.getMax();
        h.add(firstBest);

        result = max(result, firstBest + secondBest);
    }

    cout<<result<<endl;
    
}
