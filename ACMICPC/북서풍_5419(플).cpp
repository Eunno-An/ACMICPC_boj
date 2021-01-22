#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, n;
vector<pair<int, int>> inputs;
vector<int> seg_tree;
vector<int> pos_y;
vector<int> pos_y_after_compression;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}
bool compare2(int a, int b) {
	return a > b;
}
void init_tree(int start, int end, int nodeNum) {
	if (start == end) {
		seg_tree[start] = 0;
		return;
	}
	int mid = (start + end) / 2;
	init_tree(start, mid, nodeNum * 2);
	init_tree(mid + 1, end, nodeNum * 2 + 1);
}
void update_tree(int start, int end, int nodeNum, int index) {
	if (index > end || index < start) return;
	if (start == end) {
		seg_tree[nodeNum] ++;
		return;
	}
	int mid = (start + end) / 2;
	update_tree(start, mid, nodeNum * 2, index);
	update_tree(mid + 1, end, nodeNum * 2 + 1, index);
	seg_tree[nodeNum] = seg_tree[nodeNum * 2] + seg_tree[nodeNum * 2 + 1];
}
int query(int start, int end, int nodeNum, int nodeL, int nodeR) {
	if (end < nodeL || nodeR < start) return 0;
	if (nodeL <= start && end <= nodeR) {
		return seg_tree[nodeNum];
	}
	int mid = (start + end) / 2;
	return query(start, mid, nodeNum * 2, nodeL, nodeR) + query(mid + 1, end, nodeNum * 2 + 1, nodeL, nodeR);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int test_case = 0;
	cin >> T;
	for (test_case; test_case < T; test_case++) {
		inputs.clear();
		seg_tree.clear();
		pos_y.clear();
		pos_y_after_compression.clear();

		cin >> n;
		seg_tree.resize(4 * n);

		init_tree(0, n - 1, 1);

		pair<int, int> pos;
		for (int i = 0; i < n; i++) {
			cin >> pos.first >> pos.second;
			inputs.push_back(pos);
			pos_y.push_back(pos.second);
		}

		sort(inputs.begin(), inputs.end(), compare);
		sort(pos_y.begin(), pos_y.end(), compare2);

		//upper_bound를 통해 해당 y값이 몇 번째로 큰 값인지 index 확인
		//그 index가 세그먼트 트리의 target node index
		//결국 0~index까지 구간합을 결과값에 더해주면 끝
		long long result = 0;
		for (int i = 0; i < inputs.size(); i++) {
			int x = inputs[i].first, y = inputs[i].second;
			int index = lower_bound(pos_y.begin(), pos_y.end(), y, compare2) - pos_y.begin();
			result += query(0, n - 1, 1, 0, index);
			update_tree(0, n - 1, 1, index);
		}
		cout << result << '\n';
	}
	return 0;
}