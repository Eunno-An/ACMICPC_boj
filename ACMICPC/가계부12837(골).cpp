#include<iostream>
#include<vector>
using namespace std;
int N, Q; 
vector<long long> seg_tree;
vector<double> days;
double make_tree(int start, int end, int nodeNum) {
	if (start == end) {
		return seg_tree[nodeNum] = 0;
	}
	int mid = (start + end) / 2;
	return seg_tree[nodeNum] = make_tree(start, mid, nodeNum * 2) + make_tree(mid + 1, end, nodeNum * 2 + 1);
}
long long add(int start, int end, int nodeNum, int left, int right) {
	if (end < left || start > right)	return 0;
	if (left <= start && end <= right)	return seg_tree[nodeNum];
	int mid = (start + end) / 2;
	return add(start, mid, nodeNum * 2, left, right) + add(mid + 1, end, nodeNum * 2 + 1, left, right);
}
void update(int start, int end, int nodeNum, int index, int c) {
	if (index < start || index > end) return;
	
	seg_tree[nodeNum] += c;
	if (start != end) {
		int mid = (start + end) / 2;
		update(start, mid, nodeNum * 2, index, c);
		update(mid + 1, end, nodeNum * 2 + 1, index, c);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	seg_tree.resize(4 * N);
	int a, b, c;
	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(0, N - 1, 1, b - 1, c);
		}
		else if (a == 2) {
			cout << add(0, N - 1, 1, b - 1, c - 1) << '\n';
		}
	}
	return 0;
}