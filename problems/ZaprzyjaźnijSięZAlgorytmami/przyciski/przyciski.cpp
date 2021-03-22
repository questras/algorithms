#include<iostream>
using namespace std;

int main() {
	int buttonsNumber, clicksNumber;
	cin>>buttonsNumber;
	cin>>clicksNumber;

	int clickCounters[buttonsNumber+1];
	for (int i = 0; i < buttonsNumber + 1; ++i)
	{
		clickCounters[i] = 0;
	}

	int maxValue = 0;
	int maxClicked = 0;

	int input;
	for (int i = 0; i < clicksNumber; ++i)
	{
		cin>>input;

		if (input == buttonsNumber + 1) {
			maxClicked = maxValue;
		} 
		else {
			clickCounters[input] = max(maxClicked, clickCounters[input]) + 1;
			maxValue = max(maxValue, clickCounters[input]);
		}
	}

	for (int i = 1; i <= buttonsNumber; ++i)
	{
		cout<<max(maxClicked, clickCounters[i])<<" ";
	}
	cout<<endl;
}
