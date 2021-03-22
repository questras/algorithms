#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;

    int fields[n];
    for (int i = 0; i < n; i++)
    {
        cin>>fields[i];
    }

    long long int bestValues[n];
    bestValues[0] = (long long int) fields[0];
    for (int i = 1; i < n; i++)
    {
        bestValues[i] = (long long int) fields[i];
        long long int bestAdd = LONG_LONG_MIN;
        for (int k = 1; k < 7 && i - k >= 0; k++)
        {
            bestAdd = max(bestValues[i-k], bestAdd);
        }
        bestValues[i] += bestAdd;
    }

    cout<<bestValues[n-1]<<endl;
    


    
}
