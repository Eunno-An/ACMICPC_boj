#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, Q; // 1 <= N, Q <= 100,000
vector<int> inputs;
vector<long long> seg_tree;
void make_tree(int start, int end, int nodeNum) {
	if (start == end) {
		seg_tree[nodeNum] = inputs[start];
		return;
	}
	int mid = (start + end) / 2;
	make_tree(start, mid, nodeNum * 2);
	make_tree(mid + 1, end, nodeNum * 2 + 1);
	seg_tree[nodeNum] = seg_tree[nodeNum * 2] + seg_tree[nodeNum * 2 + 1];
}
long long sum(int start, int end, int nodeNum, long long nodeL, long long  nodeR) {
	if (end < nodeL || nodeR < start) {
		return 0;
	}
	if (nodeL <= start && end <= nodeR) {
		return seg_tree[nodeNum];
	}
	int mid = (start + end) / 2;
	return sum(start, mid, nodeNum * 2, nodeL, nodeR) + sum(mid + 1, end, nodeNum * 2 + 1, nodeL, nodeR);
}
void update(int start, int end, int nodeNum, int index, long long value) {
	if (index < start || end < index) {
		return;
	}

	seg_tree[nodeNum] += value;
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, nodeNum*2, index, value);
	update(mid + 1, end, nodeNum*2+1, index, value);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	seg_tree.resize(4 * N);
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputs.push_back(input);
	}
	make_tree(0, N - 1, 1);
	long long x, y, a, b;
	for (int i = 0; i < Q; i++) {
		cin >> x >> y >> a >> b;
		if (x > y) {
			swap(x, y);
		}
		cout << sum(0, N - 1, 1, x - 1, y - 1) << '\n';
		long long dif = b - inputs[a - 1];
		inputs[a - 1] = b;
		update(0, N - 1, 1, a - 1, dif);
	}
	return 0;
}