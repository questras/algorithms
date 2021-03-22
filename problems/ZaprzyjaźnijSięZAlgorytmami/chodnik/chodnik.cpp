#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
	long long int n;
	cin>>n;

	long long int result = (1+n)*n/2;
	int numb;
	for (int i = 0; i < n - 1; ++i)
	{
		cin>>numb;
		result -= numb;
	}

	cout<<result<<endl;
}