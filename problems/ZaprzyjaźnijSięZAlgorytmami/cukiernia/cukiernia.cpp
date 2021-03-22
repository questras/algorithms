#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	pair<int, int> pricesAndPos[n];

	int price;
	for (int i = 0; i < n; ++i)
	{
		cin>>price;
		pricesAndPos[i] = make_pair(price, i);
	}

	pair<int, int> minims[n];
	minims[n-1] = pricesAndPos[n-1];
	for (int i = n-2; i >= 0; i--)
	{
		if (pricesAndPos[i].first < minims[i+1].first) {
			minims[i] = pricesAndPos[i];
		}
		else {
			minims[i] = minims[i+1];
		}
	}
		
	int currentPosition = -1;
	long long int toPay = 0;
	// Loop until at the beginning of queue;
	while (currentPosition != n-1) {
		pair<int, int> best = minims[currentPosition+1];
		toPay += ((long long)(best.second - currentPosition) * (long long)best.first);
		currentPosition = best.second;
	}

	cout<<toPay<<endl;
}
