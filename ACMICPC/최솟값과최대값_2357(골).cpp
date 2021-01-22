#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> inputs;
vector<int> max_seg_tree, min_seg_tree;
int make_max_tree(int start, int end, int nodeNum) {
	if (start == end) {
		return max_seg_tree[nodeNum] = inputs[start];
	}
	int mid = (start + end) / 2;
	return max_seg_tree[nodeNum] = max(make_max_tree(start, mid, nodeNum * 2), make_max_tree(mid + 1,end, nodeNum * 2 + 1));
}
int make_min_tree(int start, int end, int nodeNum) {
	if (start == end) {
		return min_seg_tree[nodeNum] = inputs[start];
	}
	int mid = (start + end) / 2;
	return min_seg_tree[nodeNum] = min(make_min_tree(start, mid, nodeNum * 2), make_min_tree(mid + 1, end,nodeNum * 2 + 1));
}
int calculate_max(int start, int end, int nodeNum, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	if (left <= start && end <= right) {
		return max_seg_tree[nodeNum];
	}
	int mid = (start + end) / 2;
	return max(calculate_max(start, mid, nodeNum * 2, left, right), calculate_max(mid + 1, end, nodeNum * 2 + 1, left, right));
}
int calculate_min(int start, int end, int nodeNum, int left, int right) {
	if (start > right || end < left) {
		return 1000000001;
	}
	if (left <= start && end <= right) {
		return min_seg_tree[nodeNum];
	}
	int mid = (start + end) / 2;
	return min(calculate_min(start, mid, nodeNum * 2, left, right), calculate_min(mid + 1, end, nodeNum * 2 + 1, left, right));
}
int main() {
	//cin과 cout이 번갈아 호출되는 경우에는 
	//sync_with_stdio(false)보다도 훨씬 중요한 문장이 
	//cin.tie(NULL); 입니다. 
	//cin은 cout과 기본적으로 묶여있어 
	//cin을 할 때마다 cout을 flush시키기 때문에, 
	//이를 해제해주면 눈에 띄는 속도 향상을 볼 수 있습니다.
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputs.push_back(input);
	}
	max_seg_tree.resize(4 * N);
	min_seg_tree.resize(4 * N);
	make_max_tree(0, N - 1, 1);
	make_min_tree(0, N - 1, 1);
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << calculate_min(0, N - 1, 1, a - 1, b - 1) << ' ' << calculate_max(0, N - 1, 1, a - 1, b - 1) << '\n';
	}
	return 0;
}