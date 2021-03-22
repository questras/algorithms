#include<iostream>
using namespace std;

int main() {
    long long int n;
    cin>>n;

    if (n == 1) {
        cout<<2<<endl;
    }
    else if (n == 2) {
        cout<<4<<endl;
    }
    else {
        cout<<1+(n * (n-1))<<endl;
    }
}
