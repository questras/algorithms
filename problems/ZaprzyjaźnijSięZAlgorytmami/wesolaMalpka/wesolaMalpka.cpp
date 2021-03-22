#include<iostream>
using namespace std;

int nwd(int a, int b) {
    if (a % b == 0) {
        return b;
    }

    return nwd(b, a%b);
}

int main() {
    int z;
    cin>>z;
    for (int i = 0; i < z; i++)
    {
        int n, d;
        cin>>n>>d;

        cout<<n/nwd(n, d)<<endl;
    }
    
}
