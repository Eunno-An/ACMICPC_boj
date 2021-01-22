#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> arr;
vector<int> v;
void pointing(int size) {
	if (size == M) {
		for (int i = 0; i < size; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		v.push_back(arr[i]);
		pointing(size + 1);
		v.pop_back();
	}
}
int main() {
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	pointing(0);
	return 0;
}