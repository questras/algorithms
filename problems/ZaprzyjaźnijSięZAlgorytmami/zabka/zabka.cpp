#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x, y, s;
	cin>>x>>y>>s;

	int diff = y-x;
	int result = diff / s;

	if (diff % s != 0) {
		result++;
	}

	cout<<result<<endl;
}