#include<iostream>
#include<vector>
using namespace std;
int N, M, K;
vector<long long> inputs;
vector<long long> segmentTree;
long long make_tree(int start, int end, int nodeNum) {
	//어떤 이진 tree의 leaf 노드의 개수가 N일 때,
	//tree 벡터에서의 leaf 노드 시작 인덱스는 N/2이다.
	if (start == end) return segmentTree[nodeNum] = inputs[start];
	long long mid = (start + end) / 2;
	return segmentTree[nodeNum] = make_tree(start, mid, nodeNum * 2) + make_tree(mid + 1, end, nodeNum * 2 + 1);
}
long long mul(int start, int end, int nodeNum, int nodeL, int nodeR) {
	if (nodeL > end || nodeR < start)	return 0;
	if (nodeL <= start && nodeR >= end) return segmentTree[nodeNum]; // [start, end]가 [nodeL, nodeR]에 포함될떄
	int mid = (start + end) / 2;
	return mul(start, mid, nodeNum * 2, nodeL, nodeR) + mul(mid + 1, end, nodeNum * 2 + 1, nodeL, nodeR);
}
void update(int start, int end, int nodeNum, int index, int dif) {
	if (index < start || index > end) return;
	segmentTree[nodeNum] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, nodeNum*2, index, dif);
	update(mid + 1, end, nodeNum *2 + 1, index, dif);
}
int main() {
	ios_base::sync_with_stdio(false);
	//N = 수의 개수, M = 수의 변경이 일어나는 횟수, K = 구간의 합을 구하는 횟수
	//(1 ≤ N ≤ 1,000,000)
	//(1 ≤ M ≤ 10,000)
	//(1 ≤ K ≤ 10,000)

	cin >> N >> M >> K;
	long long input;
	for (int i = 0; i < N; i++) { // O(백만)
		cin >> input;
		inputs.push_back(input);
	}
	
	segmentTree.resize(4 * N);
	make_tree(0, N - 1, 1);

	
	int a, b, c;
	for (int i = 0; i < M+K; i++) {//O(2만)
		cin >> a >> b >> c;
		if (a == 1) {//b(1<=b<=N)번째 수를 c로 바꿈
			int diff = c - inputs[b - 1];
			inputs[b - 1] = c;
			update(0, N - 1, 1, b-1, diff);
		}
		else if (a == 2) {//b(1<=b<=N)번째 수부터 c번째 수까지의 합을 구하여 출력
			cout << mul(0, N - 1, 1, b-1, c-1) << '\n';
		}
	}
	return 0;
}