#include<iostream>
#include<stack>
using namespace std;

bool isOpening(char b) {
	return b == '[' || b == '{' || b == '(';
}

bool match(char a, char b) {
	return (a == '[' && b == ']') ||
			(a == '(' && b == ')') ||
			(a == '{' && b == '}');
}

int main() {
	

	int n;
	cin>>n;

	for (int ii = 0; ii < n; ++ii)
	{
		stack <char> s;
		string brackets;
		cin>>brackets;

		if (!isOpening(brackets[0])) {
			cout<<"NIE"<<endl;
			break;
		}

		char bracket;
		bool ok = true;
		for (int i = 0; i < brackets.length(); ++i)
		{
			bracket = brackets[i];

			if (isOpening(bracket)) {
				s.push(bracket);
			} 
			else {
				char topBracket = s.top();
				s.pop();
				if (!match(topBracket, bracket)) {
					cout<<"NIE"<<endl;
					ok = false;
					break;
				}
			}
		}


		if (ok) {
			if (s.empty()) {
				cout<<"TAK"<<endl;
			}
			else {
				cout<<"NIE"<<endl;
			}
			
		}
	}
	
}
