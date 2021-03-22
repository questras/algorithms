#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin>>a>>b;

    if (a == b) {
        cout<<0<<endl;
        return 0;
    }

    int result = 0;
    while (a != b) {
        if (a > b) {
            a /= 2;
        }
        else {
            b /= 2;
        }
        result ++;
    }

    cout<<result<<endl;

}
