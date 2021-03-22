#include<iostream>
using namespace std;


int main() {
	int n;
	cin>>n;
	int directions[n];
	int prefixes[n+1];

	prefixes[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>directions[i];
		prefixes[i+1] = prefixes[i] + directions[i];
	}

	long long int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		if (directions[i] == 0) {
			sum += prefixes[n] - prefixes[i+1];
		}
	}

	cout<<sum<<endl;
}
