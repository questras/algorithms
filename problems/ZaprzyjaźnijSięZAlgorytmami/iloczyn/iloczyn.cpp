#include<iostream>
#include <algorithm>
using namespace std;

int main() {
	int z;
	cin>>z;
	for (int ii = 0; ii < z; ++ii)
	{
		int n;
		cin>>n;

		int t[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>t[i];
		}

		sort(t, t+n);

		cout<<max(t[0] * t[1] * t[n-1], t[n-3] * t[n-2] * t[n-1])<<endl;
	}
}
