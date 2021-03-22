#include<iostream>
using namespace std;

int main() {
	int z;
	cin>>z;

	for (int ii = 0; ii < z; ++ii)
	{
		int n;
		cin>>n;
		int prices[n-1];
		long long int sumOfAll = 0;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>prices[i];
			sumOfAll += prices[i];
		}

		long long int zero = 0;
		long long int previousSum = 0;
		long long int currentSum = 0;
		long long int bestSum = 0;
		long long int worstSum = 0;

		for (int i = n-2; i >= 0; --i)
		{
			currentSum = prices[i] + max(zero, previousSum);
			bestSum = max(bestSum, currentSum);

			previousSum = currentSum;
		}

		previousSum = 0;
		for (int i = n-2; i >= 0; --i)
		{
			currentSum = prices[i] + min(zero, previousSum);
			worstSum = min(worstSum, currentSum);

			previousSum = currentSum;
		}

		sumOfAll += max(bestSum, abs(worstSum));

		cout<<sumOfAll<<endl;
	}
}
