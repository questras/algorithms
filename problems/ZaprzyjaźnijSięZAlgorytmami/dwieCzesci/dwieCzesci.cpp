#include<iostream>
#include<climits>
using namespace std;

int find_candidate(int t[], int n) {
	int size = 0;
	int value = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		if (size == 0) {
			value = t[i];
			size++;
		}
		else {
			if (t[i] == value) {
				size++;
			}
			else {
				size--;
			}
		}
	}

	return value;
}

bool check_candidate(int t[], int n, int candidate) {
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (t[i] == candidate) {
			count++;
		}
	}

	return count > n/2;
}

int main() {
	int n;
	cin>>n;

	int t[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>t[i];
	}

	// Find leader
	int candidate = find_candidate(t, n);

	if (check_candidate(t, n, candidate)) {
		int leader_prefixes[n+1];
		leader_prefixes[0] = 0;
		for (int i = 1; i < n+1; ++i)
		{
			leader_prefixes[i] = leader_prefixes[i-1];
			if (t[i-1] == candidate) {
				leader_prefixes[i]++;
			}
		}

		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			if (leader_prefixes[i+1] > (i+1)/2 && 
				leader_prefixes[n] - leader_prefixes[i+1] > (n-(i+1))/2) {
				result ++;
			}
		}

		cout<<result<<endl;

	}
	else {
		cout<<0<<endl;
	}


}
