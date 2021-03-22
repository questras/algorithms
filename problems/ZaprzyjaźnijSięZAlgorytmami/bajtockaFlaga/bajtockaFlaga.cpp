#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;

	int occurrencesOdd[n+1];
	int occurrencesEven[n+1];

	for (int i = 0; i <= n; ++i)
	{
		occurrencesOdd[i] = 0;
		occurrencesEven[i] = 0;
	}

	int color;
	for (int i = 0; i < n; ++i)
	{
		cin>>color;

		if (i%2==0) {
			occurrencesEven[color]++;
		}
		else {
			occurrencesOdd[color]++;
		}
	}

	int bestEven1 = 0;
	int bestEven2 = 0;
	int bestOdd1 = 0;
	int bestOdd2 = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (occurrencesEven[i] > occurrencesEven[bestEven1]) {
			bestEven2 = bestEven1;
			bestEven1 = i;
		}
		else if (occurrencesEven[i] > occurrencesEven[bestEven2]) {
			bestEven2 = i;
		}

		if (occurrencesOdd[i] > occurrencesOdd[bestOdd1]) {
			bestOdd2 = bestOdd1;
			bestOdd1 = i;
		}
		else if (occurrencesOdd[i] > occurrencesOdd[bestOdd2]) {
			bestOdd2 = i;
		}
	}

	if (bestEven1 == bestOdd1) {
		int opt1 = n-(occurrencesEven[bestEven1]+occurrencesOdd[bestOdd2]);
		int opt2 = n-(occurrencesEven[bestEven2]+occurrencesOdd[bestOdd1]);
		cout<<min(opt1, opt2)<<endl;
	} 
	else {
		cout<<n-(occurrencesEven[bestEven1]+occurrencesOdd[bestOdd1])<<endl;
	}

}
