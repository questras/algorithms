#include<iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	cin>>n;

	for (int i = floor(sqrt(n)); i >= 1; --i)
	{
		if (n % i == 0) {
			cout<<2 * i + 2 * (n/i)<<endl;
			return 0;
		}
	}

}
