#include<iostream>
#include<vector>
//중복 순열
using namespace std;
int M, N;
vector<int> arr;
void function(int a, int b, vector<int>& v) {
	if (v.size() == b) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < a; i++) {
		v.push_back(i + 1);
		function(a, b, v);
		v.pop_back();
	}
}
int main() {
	cin >> M >> N;
	function(M, N, arr);
	return 0;
}