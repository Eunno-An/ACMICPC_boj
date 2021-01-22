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
	return segmentTree[nodeNum] = make_tree(start, mid, nodeNum * 2) * make_tree(mid + 1, end, nodeNum * 2 + 1) % 1000000007;
}
long long mul(int start, int end, int nodeNum, int nodeL, int nodeR) {
	//cout << "start: " << start  << ' ' << "end: " << end << ' ' << "nodeNum: " << nodeNum << ' ' << "nodeL: " << nodeL << ' ' << "nodeR: " << nodeR << ' ' << '\n';
	if (nodeL > end || nodeR < start) {
		//cout << "out target range\n";
		return 1; 
	}
	if (nodeL <= start && nodeR >= end) {
		//cout << "in target range\n";
		return segmentTree[nodeNum]; // [start, end]�� [nodeL, nodeR]�� ���Եɋ�
	}
	//cout << "segmentTree[" << nodeNum << "] is " << segmentTree[nodeNum] << '\n';
	int mid = (start + end) / 2;
	//�̺κб����� ������ ������ �ؾ� ����.
	return mul(start, mid, nodeNum * 2, nodeL, nodeR) * mul(mid + 1, end, nodeNum * 2 + 1, nodeL, nodeR) % 1000000007;
}
void update(int start, int end, int nodeNum, int index, int dif) {
	if (index < start || index > end) return;
	if (start == end) {
		segmentTree[nodeNum] += dif;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, nodeNum*2, index, dif);
	update(mid + 1, end, nodeNum *2 + 1, index, dif);
	segmentTree[nodeNum] = segmentTree[nodeNum * 2] * segmentTree[nodeNum * 2 + 1] % 1000000007;
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
	
	segmentTree.resize(4 * N, 1);
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
			cout << mul(0, N - 1, 1, b-1, c-1) % 1000000007<< '\n';
		}
	}
	return 0;
}