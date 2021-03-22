#include<iostream>
using namespace std;

int main() {
    int n, sweetsTypes;
    cin>>n>>sweetsTypes;

    int *presentSweets = new int[sweetsTypes + 1];
    for (int i = 0; i < sweetsTypes + 1; i++)
    {
        presentSweets[i] = 0;
    }

    int *sweets = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>sweets[i];
    }

    int beg = 0, end = 0;
    presentSweets[sweets[beg]]++;
    long long int result = 0;
    while(beg < n) {
        if (end + 1 < n && presentSweets[sweets[end + 1]] == 0) {
            end++;
            presentSweets[sweets[end]]++;
        }
        else {
            result += (end - beg) + 1;
            presentSweets[sweets[beg]]--;
            if (beg == end) {
                end++;
                end = min(end, n-1);
                presentSweets[sweets[end]]++;
            }
            beg++;
        }
    }
    
    cout<<result<<endl;
    
}
