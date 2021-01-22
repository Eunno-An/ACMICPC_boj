//레이지 프로퍼게이션
//기존 세그먼트 트리의 쿼리 문제에는
//어느 리프노드 하나의 값만을 갱신했다면
//레이지 프로퍼게이션에서는
//구간의 값을 갱신하는 문제가 나온다. 
//이러면 구간의 길이(N) * 갱신 복잡도(logN) = O(NlogN), 
//쿼리의 질의 수 까지 합친다면 이 문제는
//O((M+K)NlogN))이 되서 타임 오바다.

#include<iostream>
#include<vector>
using namespace std;
int N, M, K;
vector<long long> seg_tree;
vector<long long> inputs;
vector<long long> lazys;

long long initTree(int start, int end, int nodeNum) {
	if (start == end) {
		return seg_tree[nodeNum] = inputs[start];
	}
	int mid = (start + end) / 2;
	return seg_tree[nodeNum] = initTree(start, mid, nodeNum * 2) + initTree(mid + 1, end, nodeNum * 2 + 1);
}
void propagation(int nodeNum, int start, int end) {
	if (lazys[nodeNum]) {
		//현재 node에 딸린 리프노드 개수 만큼 lazys를 더해준다. 
		seg_tree[nodeNum] += ((long long)end - start + 1) * lazys[nodeNum];
		if (start != end) {
			lazys[nodeNum * 2] += lazys[nodeNum];
			lazys[nodeNum * 2 + 1] += lazys[nodeNum];
		}
		lazys[nodeNum] = 0;
	}
}

//구간 [fixL, fixR]에 value를 더하라
void query1(int start, int end, int nodeNum, int fixL, int fixR, int value) {
	//나는 현재 fixL부터 fixR까지 뭔가를 할껀데, 재귀함수에서 start, end가 [fixL, fixR]에서 어떤 위치에 있나 보면 됨.
	propagation(nodeNum, start, end);
	if (end < fixL || fixR < start) return ;
	if (fixL <= start && end <= fixR) {

		seg_tree[nodeNum] += ((long long)end-start+1) * value; // 구간 합을 구해줌
		if (start != end) {
			lazys[nodeNum * 2] += value;
			lazys[nodeNum * 2 + 1] += value;
		}
		return ;
	}
	int mid = (start + end) / 2;
	query1(start, mid, nodeNum * 2, fixL, fixR, value);
	query1(mid + 1, end, nodeNum * 2 + 1, fixL, fixR, value);
	seg_tree[nodeNum] = seg_tree[nodeNum * 2] + seg_tree[nodeNum * 2 + 1];
}
long long query2(int start, int end, int nodeNum, int fixL, int fixR) {
	propagation(nodeNum, start, end);
	if (end < fixL || fixR < start) return 0;
	if (fixL <= start && end <= fixR) return seg_tree[nodeNum];
	int mid = (start + end) / 2;
	return query2(start, mid, nodeNum * 2, fixL, fixR) + query2(mid + 1, end, nodeNum * 2 + 1, fixL, fixR);
}

int main() {
	cin >> N >> M >> K;
	seg_tree.resize(4 * N);
	lazys.resize(4 * N);

	long long input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputs.push_back(input);
	}
	initTree(0, N - 1, 1);
	int a, b, c, d;
	for (int i = 0; i < M + K; i++) {
		cin >> a;
		if (a == 1) {//add d to [b, c] 
			cin >> b >> c >> d;
			query1(0, N - 1, 1, b - 1, c - 1, d);
		}
		else if (a == 2) {//print sum of [b, c]
			cin >> b >> c;
			cout << query2(0, N - 1, 1, b - 1, c - 1) << '\n';
		}
	}
	return 0;
}