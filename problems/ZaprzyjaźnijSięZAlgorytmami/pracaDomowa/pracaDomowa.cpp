#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long int t[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>t[i];
	}

	long long int zero = 0;
	long long int sumsToLeft[n];
	long long int sumsToRight[n];

	sumsToLeft[0] = 0;
	sumsToLeft[n-1] = 0;
	for (int i = 1; i < n-1; ++i)
	{
		sumsToLeft[i] = t[i] + max(zero, sumsToLeft[i-1]);
	}

	sumsToRight[0] = 0;
	sumsToRight[n-1] = 0;
	for (int i = n-2; i > 0; --i)
	{
		sumsToRight[i] = t[i] + max(zero, sumsToRight[i+1]);
	}

	long long int result = 0;
	for (int i = 1; i < n-1; ++i)
	{
		result = max(result, max(sumsToLeft[i-1], zero) + max(zero, sumsToRight[i+1]));
	}

	cout<<result<<endl;
}
