#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int M, N;
vector<int> arr;
vector<int> v;
void pointing(int size, int idx) {
	if (v.size() == size) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < M; i++) {
		v.push_back(arr[i]);
		pointing(N, idx);
		v.pop_back();
		idx++;
	}
}
int main() {
	cin >> M >> N;
	arr.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	pointing(N, 0);
	return 0;
}