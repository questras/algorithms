#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n>>m;

	int liscieDoPokonania = n;
	bool spadly[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		spadly[i] = false;
	}

	int pozycja;
	for (int i = 0; i < m; ++i)
	{
		cin>>pozycja;
		if (!spadly[pozycja]) {
			liscieDoPokonania--;
			spadly[pozycja] = true;

			if (liscieDoPokonania == 0) {
				cout<<i+1<<endl;
				return 0;
			}
		}
	}

	cout<<"-1"<<endl;


	return 0;
}