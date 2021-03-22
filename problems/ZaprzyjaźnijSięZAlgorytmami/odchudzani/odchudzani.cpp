#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;

	long long int differences[n-1];
	int previous;
	int weight;
	cin>>previous;

	for (int i = 0; i < n-1; ++i)
	{
		cin>>weight;
		differences[i] = -(weight-previous);

		previous = weight;
	}

	long long int previousSum = 0;
	long long int sum = 0;
	long long int maxSum = 0;

	for (int i = n-2; i >= 0; --i)
	{
		sum = differences[i] + max((long long int)0, previousSum);
		maxSum = max(maxSum, sum);

		previousSum = sum;
	}

	cout<<maxSum<<endl;
}
