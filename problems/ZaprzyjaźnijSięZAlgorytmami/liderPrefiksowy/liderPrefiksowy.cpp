#include<iostream>
#include<algorithm>
#include<stack>
#include<climits>
using namespace std;

bool check_candidate(int t[], int n, int candidate) {
	int candidate_count = 0;
	int prefixes_count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (t[i] == candidate) {
			candidate_count++;
		}

		if (candidate_count > (i+1)/2) {
			prefixes_count++;
		}
	}

	return prefixes_count > (n/2);
}

int main() {
	int n;
	cin>>n;


	int t[n];
	int candidates[n];
	stack <int> s;
	int number;
	for (int i = 0; i < n; ++i)
	{
		cin>>number;
		t[i] = number;
		if (s.empty() || s.top() == number) {
			s.push(number);
		}
		else {
			s.pop();
		}

		if (s.empty()) {
			candidates[i] = number;
		}
		else {
			candidates[i] = s.top();
		}
	}

	int value = INT_MAX;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (count == 0) {
			value = candidates[i];
			count++;
		}
		else if (t[i] != value) {
			count--;
		}
		else {
			count++;
		}
	}

	if (s.empty()) {
		cout<<"NIE"<<endl;
		return 0;
	}

	int candidate = s.top();

	if (!check_candidate(t, n, candidate)) {
		cout<<"NIE"<<endl;
	}
	else {
		cout<<candidate<<endl;
	}


}
