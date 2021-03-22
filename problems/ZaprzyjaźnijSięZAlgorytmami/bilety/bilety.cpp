#include<iostream>
using namespace std;

class Heap {
    public:
        pair<int, int> *t;
        int last;

        Heap(int n) {
            t = new pair<int, int>[n + 1];
            last = 0;
        }

        bool isEmpty() {
            return last == 0;
        }

        int getMax() {
            if (isEmpty()) {
                return -1;
            }
            else {
                return -t[1].first;
            }
        }

        void add(pair<int, int> value) {
            last++;
            t[last] = value;
            t[last].first *= -1;

            int w = last;
            while (w > 1 && t[w / 2].first < t[w].first) {
                swap(t[w / 2], t[w]);
                w /= 2;
            }
        }

        void removeMax() {
            t[1].second --;
            if (t[1].second == 0) {
                t[1] = t[last];
                last--;

                restore(1);
            }
        }

        void restore(int i) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int maks = i;

            if (left <= last && t[left].first > t[maks].first) {
                maks = left;
            }
            if (right <= last && t[right].first > t[maks].first) {
                maks = right;
            }

            if (maks > i) {
                swap(t[maks], t[i]);
                restore(maks);
            }
        }
};

int main() {
    int n;
    cin>>n;

    pair<int, int> priceAndQuantity[n];
    for (int i = 0; i < n; i++)
    {
        cin>>priceAndQuantity[i].first;
        cin>>priceAndQuantity[i].second;
    }

    Heap h = Heap(n + 1);
    long long int result = 0;
    for (int i = 0; i < n; i++)
    {
        h.add(priceAndQuantity[i]);
        result += h.getMax();
        h.removeMax();
    }
    
    cout<<result<<endl;   
}
