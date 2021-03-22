#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> get_divisors(int n) {
    vector<int> divisors;

    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i*i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    
    return divisors;
}

int main() {
    int n;
    cin>>n;

    int heights[n];
    for (int i = 0; i < n; i++)
    {
        cin>>heights[i];
    }

    int peaks[n];
    peaks[0] = 0;
    peaks[n-1] = 0;
    for (int i = 1; i < n-1; i++)
    {
        if (heights[i] > heights[i-1] && heights[i] > heights[i+1]) {
            peaks[i] = 1;
        }
        else {
            peaks[i] = 0;
        }
    }

    int peaks_prefixes[n+1];
    peaks_prefixes[0] = 0;
    for (int i = 1; i < n+1; i++)
    {
        peaks_prefixes[i] = peaks_prefixes[i-1] + peaks[i-1];
    }

    vector<int> divisors = get_divisors(n);
    int best_divisor = INT_MAX;

    while (!divisors.empty()) {
        int divisor = divisors.back();
        bool flag = true;

        for (int i = 1; i < n / divisor; i++)
        {
            if (peaks_prefixes[i * divisor]-peaks_prefixes[(i-1) * divisor] == 0) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            best_divisor = min(best_divisor, divisor);
        }

        divisors.pop_back();
    }

    cout<<n / best_divisor<<endl;    
    
}
