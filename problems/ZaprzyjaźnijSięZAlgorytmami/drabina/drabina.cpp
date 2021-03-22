#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int z;
    cin>>z;
    int *p = new int[z];
    int *s = new int[z];
    int max_p = 0;
    int max_s = 0;

    for (int i = 0; i < z; i++)
    {
        cin>>s[i];
        cin>>p[i];
        max_p = max(max_p, p[i]);
        max_s = max(max_s, s[i]);
    }

    long long int *ladder = new long long int[max_s + 1];
    ladder[0] = 1;
    ladder[1] = 1;
    for (int i = 2; i < max_s + 1; i++)
    {
        ladder[i] = (ladder[i-2] + ladder[i-1]) % (long long int)(pow(2, max_p));
    }

    for (int i = 0; i < z; i++) {
        cout<<ladder[s[i]] % (long long int)(pow(2, p[i]))<<endl;
    } 
}
