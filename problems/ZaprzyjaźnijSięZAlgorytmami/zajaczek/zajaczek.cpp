#include<iostream>
#include<climits>
using namespace std;

int main() {
    int n;
    cin>>n;
    int lastIdx = -1;
    int fib[300000];

    fib[0] = 0;
    fib[1] = 1;
    lastIdx = 1;

    for (int i = 2; i <= n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        lastIdx = i;

        if (fib[i] >= n) {
            break;
        }
    }

    int stones[n+1];
    for (int i = 0; i < n+1; i++)
    {
        cin>>stones[i];
    }

    if (stones[0] == 1 || stones[n] == 1) {
        cout<<-1<<endl;
        return 0;
    }

    int jumps[n+1];
    jumps[0] = 0;
    for (int i = 1; i < n+1; i++)
    {
        jumps[i] = INT_MAX - 1;
        if (!stones[i])
        {
            for (int k = 1; k <= lastIdx; k++)
            {
                if (i - fib[k] >= 0) {
                    jumps[i] = min(jumps[i], 1 + jumps[i - fib[k]]);
                }
                
            }
        }
    }
    if (jumps[n] >= INT_MAX - 1) {
        cout<<-1<<endl;
    }
    else {
        cout<<jumps[n]<<endl;
    }
}
