//문제 이해: 이동 했다라고 가정! 확률에 따른 이동이 아니라, 이동에 따른 확률을 구하기
//동 동 으로 이동했다고 가정하고, 동 이동 확률이 0.25 일 때, 0.25 ^ 2가 동동 이동 확률임.
//42~43번째 줄 : 절대 상대 오차 허용 범위 꼭 확인하기. 
#include<iostream>
using namespace std;

int N;
int pe, pw, ps, pn;
double d_p[4];

int arr[32][32];
double answer;
//0, 0, 1, -1
//1 -1 0 0
int dx[4] = {0, 0, 1, -1 }; // 남 동 북 서
int dy[4] = { 1, -1, 0, 0 };
//  단순한 경우의 수 / 전체 경우의 수

void dfs(int x, int y, int count, double now_prop) {
	if (count == N) {
		//cout << now_prop << ' ';
		answer += now_prop;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (arr[x + dx[i]][y + dy[i]] != 1) {
			arr[x + dx[i]][y + dy[i]] = 1;
			dfs(x + dx[i], y + dy[i], count + 1, now_prop * d_p[i]);
			arr[x + dx[i]][y + dy[i]] = 0;
		}
	}
}
int main() {
	cin >> N >> pe >> pw >> ps >> pn;
	d_p[0] = (double)pe / 100;
	d_p[1] = (double)pw / 100;
	d_p[2] = (double)ps / 100;
	d_p[3] = (double)pn / 100;
	
	arr[15][15] = 1;
	dfs(15, 15, 0, 1);
	cout << fixed;
	cout.precision(9);
	cout << answer << '\n';
	return 0;
}
