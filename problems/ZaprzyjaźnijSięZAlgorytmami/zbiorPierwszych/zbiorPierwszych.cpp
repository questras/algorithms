#include<iostream>
#include<set>
using namespace std;

// YES if a==b
// 
// product of prime divisors of a must be gcd of prime divisors of b

// a b 
// nwd(a, b)

int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (a % b == 0) {
        return b;
    }

    return gcd(b, a%b);
}

// 2 4
// gcd = 2
// 2 / gcd = 1 OK

// 4 10
// gcd = 2
// 4 / gcd = 2
// 
// 2 4

bool ans(int a, int b) {
    // Assuming a and b are not 1
    int g = gcd(a, b);
    if (g == 1) {
        return false;
    }

    if (a / g == 1) {
        return true;
    }
    else {
        return ans(a / g, g);
    }

}

int main() {
    int z;
    cin>>z;

    for (int i = 0; i < z; i++)
    {
        int a, b;
        cin>>a>>b;
        if (a == b) {
            cout<<"TAK"<<endl;
        }
        else if (a == 1) {
            cout<<"TAK"<<endl;
        }
        else if (b == 1) {
            cout<<"NIE"<<endl;
        }
        else if (ans(a, b)) {
            cout<<"TAK"<<endl;
        }
        else {
            cout<<"NIE"<<endl;
        }
    }

}
