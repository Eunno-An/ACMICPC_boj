#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int x, y;
vector<pair<int, int>> inputs;
bool compare (pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	pair<int, int> input;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		input.first = x;
		input.second = y;
		inputs.push_back(input);
	}
	sort(inputs.begin(), inputs.end(), compare);
	pair<int, int> a, b;
	a = inputs[0];
	int length = a.second - a.first;
	for (int i = 1; i < inputs.size(); i++) {
		b = inputs[i];
		if (a.second >= b.second) continue;
		if (a.second >= b.first && a.second < b.second) {
			length += (b.second - a.second);
			a.second = b.second;
		}
		else if(a.second < b.first) {
			length += (b.second - b.first);
			a = b;
		}
	}
	cout << length << '\n';
	
	return 0;
}