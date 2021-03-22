#include<iostream>
using namespace std;

int getMaxRadius(int idx, int n) {
    return max(n-idx-1, idx);
}

int main() {
    int n;
    cin>>n;
    int *t = new int[n];
    int *w = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin>>t[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>w[i];
    }
    
    long long int *prefixes = new long long int[n+1];
    prefixes[0] = 0;
    for (int i = 1; i < n+1; i++)
    {
        prefixes[i] = prefixes[i-1] + t[i-1];
    }


    for (int i = 0; i < n; i++)
    {
        int poc = 0;
        int kon = n-1;//getMaxRadius(n, i);
        int wynik = -1;
        while (poc <= kon) {
            int sro = (poc + kon) / 2;

            long long int sum = (long long int)prefixes[min(n, i + sro + 1)]-(long long int)prefixes[max(0, i - sro)];
            if (sum >= w[i]) {
                wynik = sro;
                kon = sro - 1;
            }
            else {
                poc = sro + 1;
            }
        }
        cout<<wynik<<" ";
    }
    
}
