//세그먼트 트리를 이용한 분할 정복
//i,j까지 구간의 직사각형의 넓이는 
//i,j까지의 높이가 최솟값인 부분에 의하여 결정된다.
//따라서 높이가 최솟값인 부분을 기준으로 
//양쪽을 분할 정복해 나갈 것이다.
//이를 계산하기 위하여 높이가 최솟값인 지점을 
//세그먼트 트리에 저장을 해줘야 한다.

#include<iostream>
#include<algorithm>
#define MAX_N 100000
using namespace std;
typedef long long ll;
int n, a[MAX_N + 1], seg[4 * MAX_N];
void init(int node, int x, int y) {
	if (x == y)
		seg[node] = x;
	else {
		int mid = (x + y) >> 1;
		init(node * 2, x, mid);
		init(node * 2 + 1, mid + 1, y);
		if (a[seg[node * 2]] <= a[seg[node * 2 + 1]])
			seg[node] = seg[node * 2];
		else
			seg[node] = seg[node * 2 + 1];
	}
}
int query(int lo, int hi, int node, int x, int y) {
	if (y < lo || hi < x)
		return -1;
	if (lo <= x && y <= hi)
		return seg[node];
	int mid = (x + y) >> 1;
	int q1 = query(lo, hi, node * 2, x, mid);
	int q2 = query(lo, hi, node * 2 + 1, mid + 1, y);
	if (q1 == -1) return q2;
	if (q2 == -1) return q1;
	if (a[q1] <= a[q2]) // 높이 최소
		return q1;
	return q2;
}
ll sol(int lo, int hi) {
	int m = query(lo, hi, 1, 0, n - 1); // 높이가 가장 작은 것의 index
	ll res = (ll)(hi - lo + 1) * a[m]; // 가장 작은 높이 * 구간
	if (lo <= m - 1) {
		ll ans = sol(lo, m - 1);
		res = max(res, ans);
	}
	if (m + 1 <= hi) {
		ll ans = sol(m + 1, hi);
		res = max(res, ans);
	}
	return res;
}
int main() {
	cin >> n;
	while (n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		init(1, 0, n - 1);
		cout << sol(0, n - 1) << '\n';
		cin >> n;
	}
}