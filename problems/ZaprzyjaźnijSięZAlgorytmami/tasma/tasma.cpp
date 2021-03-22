#include <iostream>
#include <climits>
using namespace std;

int abs(int numb) {
	if (numb < 0) {
		return -numb;
	}

	return numb;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}

	return b;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int numbs[n];
	int sumleft = 0;
	int sumright = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>numbs[i];
		sumright += numbs[i];
	}

	int result = INT_MAX;

	for (int i = 0; i < n-1; ++i)
	{
		/* code */
		sumleft += numbs[i];
		sumright -= numbs[i];
		result = min(result, abs(sumright-sumleft));
	}

	cout<<result<<endl;

	return 0;
}