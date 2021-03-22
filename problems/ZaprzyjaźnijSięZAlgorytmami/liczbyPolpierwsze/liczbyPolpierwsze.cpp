#include<iostream>
using namespace std;

//   0 0 0 1 2 0 1 0 1 2 3 0 1 0 1 2 3
//2: 0 0 0 1 1 1 1 1 1 2 3 3 3 3 3 4 5

//3: 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 2

bool isHalfPrime(int n, int F[]) {
    return F[n] != 0 && F[n / F[n]] == 0 && n / F[n] != 1;
}

int main() {
    int max_size = 1000000;

    int F[max_size+1];
    for (int i = 0; i < max_size+1; i++)
    {
        F[i] = 0;
    }

    for (int i = 2; i * i < max_size + 1; i++) {
        if (!F[i]) {
            for (int k = i * i; k < max_size + 1; k += i) {
                if (!F[k]) {
                    F[k] = i;
                }
            }
        }
    }

    int halfprimes[max_size+1];
    halfprimes[0] = 0;
    halfprimes[1] = 0;
    for (int i = 2; i < max_size+1; i++)
    {
        halfprimes[i] = isHalfPrime(i, F);
    }

    int *prefixes1 = new int[max_size+1];
    int *prefixes2 = new int[max_size+1];
    int *prefixes3 = new int[max_size+1];
    
    prefixes1[0] = 0;
    prefixes2[0] = 0;
    prefixes3[0] = 0;

    for (int i = 1; i < max_size+1; i++) {
        prefixes1[i] = prefixes1[i-1];
        prefixes2[i] = prefixes2[i-1];
        prefixes3[i] = prefixes3[i-1];

        if (halfprimes[i]) {
            prefixes1[i]++;

            if (halfprimes[i - 1]) {
                prefixes2[i]++;

                if (i > 2 && halfprimes[i-2]) {
                    prefixes3[i]++;
                }
            }
        }
        
    }

    int z;
    cin>>z;
    for (int ii = 0; ii < z; ii++)
    {
        int a, b;
        cin>>a>>b;
        if (prefixes3[b] - prefixes3[a+1] > 0) {
            cout<<3<<endl;
        }
        else if (prefixes2[b] - prefixes2[a] > 0) {
            cout<<2<<endl;
        }
        else if (prefixes1[b] - prefixes1[a-1] > 0) {
            cout<<1<<endl;
        }
        else {
            cout<<0<<endl;
        }
    }
    

}
