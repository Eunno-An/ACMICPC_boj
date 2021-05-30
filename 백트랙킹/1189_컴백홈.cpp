#include<iostream>
using namespace std;
int R, C, K;
char arr[5][5];
bool visit[5][5];
int dx[4] = { 0, 1 , 0 , -1 };
int dy[4] = { 1, 0, -1, 0 };
int result;
bool ok(int x, int y, int dx, int dy) {
	if (x + dx < 0 || y + dy < 0 || x + dx > R - 1 || y + dy > C - 1 || arr[x+dx][y+dy] == 'T' || visit[x+dx][y+dy] == true) {
		return false;
	}
	return true;
}

void dfs(int x, int y, int count) {
	if (x == 0 && y == C - 1 && count == K) {
		result++;
		return;
	}
	if (count > K) {
		return;
	}

	
	for (int i = 0; i < 4; i++) {
		int _dx = dx[i];
		int _dy = dy[i];
		if (ok(x, y, _dx, _dy)) {
			visit[x+_dx][y+_dy] = true;//한번 간 곳은 다시 돌아오지 않는다!
			dfs(x + _dx, y + _dy, count + 1);
			visit[x + _dx][y + _dy] = false;
		}
	}
}
int main() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	visit[R - 1][0] = true;//문제 조건에서, 한번 간 곳은 다시 돌아가지 않으므로, 시작 포인트도 visit true로 해주어야 한다.
	dfs(R - 1, 0, 1);
	
	cout << result << '\n';
}
