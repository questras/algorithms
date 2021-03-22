#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    int minNumb = 1000000, maxNumb = 0;
    int numbers[n];

    for (int i = 0; i < n; i++)
    {
        cin>>numbers[i];
        minNumb = min(minNumb, numbers[i]);
        maxNumb = max(maxNumb, numbers[i]);
    }

    int occurrences[maxNumb+1];
    for (int i = 0; i <= maxNumb; i++)
    {
        occurrences[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        occurrences[numbers[i]]++;
    }

    int howManyDivisors[maxNumb+1];
    for (int i = 0; i <= maxNumb; i++)
    {
        howManyDivisors[i] = 0;
    }
    
    for (int i = minNumb; i <= maxNumb; i++)
    {
        if (occurrences[i]) {
            for (int k = i; k <= maxNumb; k+=i)
            {
                howManyDivisors[k] += occurrences[i];
            }
            
        }
    }
    

    for (int i = 0; i < n; i++)
    {
        cout<<n-howManyDivisors[numbers[i]]<<" ";
    }
    cout<<endl;
    
}
