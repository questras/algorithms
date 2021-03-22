#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cin>>n;

	int sizes[n];
	int directions[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>sizes[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin>>directions[i];
	}

	stack <int> s;

	for (int i = 0; i < n; ++i)
	{
		if (s.empty()) {
			s.push(i);
		}
		else if (directions[i] == 0 && directions[s.top()] == 1) {
			while (true) {
				if (s.empty() || directions[s.top()] == 0) {
					s.push(i);
					break;
				} 
				else {
					if (sizes[i] > sizes[s.top()]) {
						s.pop();
					}
					else {
						break;
					}
				}
			}
		}
		else {
			s.push(i);
		}
	}

	cout<<s.size()<<endl;
}
