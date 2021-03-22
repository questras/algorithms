#include<iostream>
using namespace std;

bool isPerfect2(int n) {
    long long int product = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) {
            product *= i;
            if (i * i != n) {
                product *= n / i;
            } 

            if (product > n) {
                return false;
            }
        }
    }
    
    return product == n;
}

// int productOfDivisors(int n) {
//     int product = 1;
//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0) {
//             cout<<i<<" "<<n / i<<endl;
//             product *= i;
//             if (i * i != n) {
//                 product *= n / i;
//             } 
//         }
//     }
    
//     return product;
// }

int main() {
    int z;
    cin>>z;
    int *a = new int[z];
    int *b = new int[z];
    int max_size = 0;
    for (int ii = 0; ii < z; ii++)
    {
        cin>>a[ii]>>b[ii];
        max_size = max(max_size, b[ii]);
    }

    

    int *perfects = new int[max_size+1];
    int *prefixes = new int[max_size+1];
    perfects[0] = 0;
    perfects[1] = 0;
    prefixes[0] = 0;
    prefixes[1] = 0;
    for (int i = 2; i < max_size + 1; ++i) {
        perfects[i] = isPerfect2(i);
        prefixes[i] = prefixes[i-1] + perfects[i];
    }

    for (int i = 0; i < z; i++) {
        cout<<prefixes[b[i]]-prefixes[a[i]-1]<<endl;
    }
    

}
