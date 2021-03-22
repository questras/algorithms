#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b) {
	return a.second + b.second + abs(b.first - a.first);
}

int main() {
	int n;
	cin>>n;

	pair<int, int> t[n];

	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		t[i] = make_pair(x, y);
	}

	sort(t, t+n);

	pair<int, int> bestNeighbourToLeft[n];
	bestNeighbourToLeft[0] = t[0];
	int result = INT_MAX;

	int distanceToLeft;
	int distanceToBestOfLeft;
	for (int i = 1; i < n; ++i)
	{
		distanceToLeft = dist(t[i], t[i-1]);
		distanceToBestOfLeft = dist(t[i], bestNeighbourToLeft[i-1]);
		if (distanceToLeft > distanceToBestOfLeft) {
			bestNeighbourToLeft[i] = bestNeighbourToLeft[i-1];
			result = min(result, distanceToBestOfLeft);
		}
		else {
			bestNeighbourToLeft[i] = t[i-1];
			result = min(result, distanceToLeft);
		}
	}

	cout<<result<<endl;

}
