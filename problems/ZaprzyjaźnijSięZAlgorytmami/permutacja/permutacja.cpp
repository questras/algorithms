#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int zlicz[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		zlicz[i] = 0;
	}

	int numb;
	for (int i = 0; i < n; ++i)
	{
		cin>>numb;

		if (numb > n || zlicz[numb] > 0) {
			cout<<"NIE"<<endl;
			return 0;
		}
		
		zlicz[numb]++;
	}

	cout<<"TAK"<<endl;

	return 0;
}