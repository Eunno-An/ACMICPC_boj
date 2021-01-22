#include<iostream>
#include<vector>
using namespace std;
int N, M, K;
vector<long long> inputs;
vector<long long> segmentTree;
long long make_tree(int start, int end, int nodeNum) {
	//� ���� tree�� leaf ����� ������ N�� ��,
	//tree ���Ϳ����� leaf ��� ���� �ε����� N/2�̴�.
	if (start == end) return segmentTree[nodeNum] = inputs[start];
	long long mid = (start + end) / 2;
	return segmentTree[nodeNum] = make_tree(start, mid, nodeNum * 2) + make_tree(mid + 1, end, nodeNum * 2 + 1);
}
long long mul(int start, int end, int nodeNum, int nodeL, int nodeR) {
	if (nodeL > end || nodeR < start)	return 0;
	if (nodeL <= start && nodeR >= end) return segmentTree[nodeNum]; // [start, end]�� [nodeL, nodeR]�� ���Եɋ�
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
	//N = ���� ����, M = ���� ������ �Ͼ�� Ƚ��, K = ������ ���� ���ϴ� Ƚ��
	//(1 �� N �� 1,000,000)
	//(1 �� M �� 10,000)
	//(1 �� K �� 10,000)

	cin >> N >> M >> K;
	long long input;
	for (int i = 0; i < N; i++) { // O(�鸸)
		cin >> input;
		inputs.push_back(input);
	}
	
	segmentTree.resize(4 * N);
	make_tree(0, N - 1, 1);

	
	int a, b, c;
	for (int i = 0; i < M+K; i++) {//O(2��)
		cin >> a >> b >> c;
		if (a == 1) {//b(1<=b<=N)��° ���� c�� �ٲ�
			int diff = c - inputs[b - 1];
			inputs[b - 1] = c;
			update(0, N - 1, 1, b-1, diff);
		}
		else if (a == 2) {//b(1<=b<=N)��° ������ c��° �������� ���� ���Ͽ� ���
			cout << mul(0, N - 1, 1, b-1, c-1) << '\n';
		}
	}
	return 0;
}