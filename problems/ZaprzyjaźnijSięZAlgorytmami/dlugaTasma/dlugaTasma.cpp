#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int minNumber;
	cin>>minNumber;

	int input;
	for (int i = 1; i < n; ++i)
	{
		cin>>input;
		minNumber = min(minNumber, input);
	}

	cout<<minNumber<<".00"<<endl;
}
