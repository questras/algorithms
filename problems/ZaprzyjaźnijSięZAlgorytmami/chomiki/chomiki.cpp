#include<iostream>
using namespace std;

int main() {
	int n, m;
	cin>>n>>m;

	int prefixes1[n+1];
	int prefixes2[n+1];
	int prefixes3[n+1];
	int prefixes4[n+1];
	int prefixes5[n+1];

	prefixes1[0] = 0;
	prefixes2[0] = 0;
	prefixes3[0] = 0;
	prefixes4[0] = 0;
	prefixes5[0] = 0;

	int age;
	for (int i = 0; i < n; ++i)
	{
		cin>>age;

		prefixes1[i+1] = prefixes1[i];
		prefixes2[i+1] = prefixes2[i];
		prefixes3[i+1] = prefixes3[i];
		prefixes4[i+1] = prefixes4[i];
		prefixes5[i+1] = prefixes5[i];

		if (age == 1) {
			prefixes1[i+1]++;
		}
		else if (age == 2) {
			prefixes2[i+1]++;
		}
		else if (age == 3) {
			prefixes3[i+1]++;
		}
		else if (age == 4) {
			prefixes4[i+1]++;
		}
		else if (age == 5) {
			prefixes5[i+1]++;
		}
	}

	int start, stop;
	for (int i = 0; i < m; ++i)
	{
		cin>>start>>stop;
		if (prefixes1[stop]-prefixes1[start-1] > 0) {
			cout<<1<<endl;
		}
		else if (prefixes2[stop]-prefixes2[start-1] > 0) {
			cout<<2<<endl;
		}
		else if (prefixes3[stop]-prefixes3[start-1] > 0) {
			cout<<3<<endl;
		}
		else if (prefixes4[stop]-prefixes4[start-1] > 0) {
			cout<<4<<endl;
		}
		else if (prefixes5[stop]-prefixes5[start-1] > 0) {
			cout<<5<<endl;
		}
	}
}
