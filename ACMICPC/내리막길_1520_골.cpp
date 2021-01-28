#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int m, n;
int gra[501][501] = { 0, };
int dp[501][501] = { 0, };
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int dfs(int r, int c) {
	if (r == m - 1 && c == n - 1)
		return 1;
	if (dp[r][c] != -1)
		return dp[r][c];

	dp[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		if (nextR >= 0 && nextC >= 0 && nextR < m && nextC < n) {
			if (gra[r][c] > gra[nextR][nextC])
				dp[r][c] += dfs(nextR, nextC);
		}
	}
	return dp[r][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> gra[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(0, 0);
}