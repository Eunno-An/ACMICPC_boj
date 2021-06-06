#include<iostream>
#include<algorithm>
using namespace std;
//RGB 함수의 의미: 이전 pos에서 prev를 선택했을 때 , pos~(N-1)마을을 색칠하는데 최솟값.

//track_Color함수의 의미: pos~(N-1)까지 색칠하는데 최솟값 == (pos+1)~(N-1)까지 색칠하는데 최솟값 + cost[pos][i]인
//                       지점을 찾기.
const int INF = 1000000000;
int N;
int cost[1001][3];
int dp[1001][4];
int RGB(int position, int prev = 3) {
	int& ret = dp[position][prev];
	//ret는 그 층에서의 최소값.
	if (ret != -1) return ret; 
	if (position == N) return ret = 0;

	ret = INF;

	for (int i = 0; i < 3; i++) {
		if (prev != i) ret = min(ret, RGB(position + 1, i) + cost[position][i]);
	}
	return ret;
}

void track_Color(int pos, int prev=3) {
	if (pos == N)
		return;
	for (int i = 0; i < 3; i++) {
		if (prev != i && RGB(pos, prev) == RGB(pos + 1, i) + cost[pos][i]) {
			cout << pos + 1 << "th color is " << i << '\n';
			track_Color(pos + 1, i);
			return;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];
	}
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 4; j++) {
			dp[i][j] = -1;
		}
	}
	cout << RGB(0) << '\n';
	track_Color(0);
	return 0;
}
