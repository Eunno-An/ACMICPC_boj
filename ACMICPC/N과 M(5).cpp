#include<iostream>
#include<vector>
#include<algorithm>
//중복 순열
using namespace std;
int M, N, depth;
vector<int> arr;
vector<int> inputs;
vector<bool> visit;
void function(int a, int b, vector<int>& v, int n, vector<bool>& visit) {
	if (v.size() == b) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < a; i++) {
		if (visit[i]) {
			continue;
		}
		v.push_back(inputs[i]);
		visit[i] = true;
		function(a, b, v, inputs[i], visit);
		v.pop_back();
		visit[i] = false;
	}
}
int main() {
	cin >> M >> N;
	inputs.resize(M);
	visit.resize(M);
	
	for (int i = 0; i < M; i++) {
		cin >> inputs[i];
	}
	sort(inputs.begin(), inputs.end());
	for (int i = 0; i < M; i++) {
		arr.push_back(inputs[i]);
		visit[i] = true;
		function(M, N, arr, inputs[i], visit);
		arr.pop_back();
		visit[i] = false;
	}
	return 0;
}