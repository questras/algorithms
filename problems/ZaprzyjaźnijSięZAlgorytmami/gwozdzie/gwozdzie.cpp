#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;

	int t[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>t[i];
	}
	sort(t, t+n);

	int result = 0;
	int start = 0;
	int distance;
	for (int i = 1; i < n; ++i)
	{
		if (t[i] != t[start]) {
			distance = min(n-1, i-1+k) - start + 1;
			result = max(result, distance);
			start = i;
		}
	}
	distance = n-1-start+1;
	result = max(result, distance);

	cout<<result<<endl;
}
