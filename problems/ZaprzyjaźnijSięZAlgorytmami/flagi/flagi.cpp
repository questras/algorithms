#include<iostream>
using namespace std;

// 10
// 3 5 2 1 4 3 6 1 7 2
// 0 1 0 0 1 0 1 0 1 0

// 22
// 1 2 1 1 1 2 1 2 1 2 1 1 1 1 2 1 2 1 1 1 1 2

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

    int closest_peak_to_right[n];
    int current_peak = -1;
    for (int i = n-1; i >= 0; i--) {
        if (peaks[i] == 1) {
            current_peak = i;
        }

        closest_peak_to_right[i] = current_peak;
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        int possible_result = min(i, n/i);
        if (possible_result > result) {
            int flags = 1;
            int current_flag_pos = closest_peak_to_right[0];
            while (current_flag_pos + i < n && current_flag_pos != -1) {
                current_flag_pos = closest_peak_to_right[current_flag_pos + i];
                if (current_flag_pos != -1) {
                    flags++;
                }
            }

            result = max(result, min(i, flags));
        }
    }

    cout<<result<<endl;
}
