#include <cstdio>
//약간 세그먼트 트리 느낌도 나고..
//불필요한 탐색 X
//TLE를 잘 생각해주어야 하는 문제
int X, L, R, N;

long long an1 = 0, an2 = 0, an3 = 0;

long long dp[4][21][4];

long long pow(int x, int y) {

	if (y == 0)

		return 1;

	else if (y == 1)

		return x;

	if (y & 1)

		return pow(x, y - 1) * pow(x, 1);

	else

		return pow(x, y / 2) * pow(x, y / 2);

}

int sqrt(long long x) {

	int cnt = 0;

	for (x; x != 1; x /= 3, cnt++);

	return cnt;

}

void cul() {

	long long a = 1, b = 0, c = 0;

	long long na, nb, nc;


	for (int n = 1; n <= 20; n++) {

		na = a + 2 * b;

		nb = a + b + 2 * c;

		nc = a + c;

		a = na; b = nb; c = nc;

		dp[1][n][1] = a; dp[1][n][2] = b; dp[1][n][3] = c;

	}

	a = 0; b = 1; c = 0;

	for (int n = 1; n <= 20; n++) {

		na = a + 2 * b;

		nb = a + b + 2 * c;

		nc = a + c;

		a = na; b = nb; c = nc;

		dp[2][n][1] = a; dp[2][n][2] = b; dp[2][n][3] = c;

	}

	a = 0; b = 0; c = 1;

	for (int n = 1; n <= 20; n++) {

		na = a + 2 * b;

		nb = a + b + 2 * c;

		nc = a + c;

		a = na; b = nb; c = nc;

		dp[3][n][1] = a; dp[3][n][2] = b; dp[3][n][3] = c;

	}

}

void loop(int num, long long range, long long first, long long second) {


	if ((range != 1) && (R < first || (L > second)))

		return;

	if ((range != 1) && (L <= first && second <= R)) {

		int r = sqrt(range);

		an1 += dp[num][r][1]; an2 += dp[num][r][2]; an3 += dp[num][r][3];

		return;

	}

	if (range == 1) {

		if (L <= first && R >= first) {

			if (num == 1)

				an1++;

			else if (num == 2)

				an2++;

			else

				an3++;

			return;

		}

		else

			return;

	}


	long long new_range = range / 3;

	long long f1 = first, s1 = f1 + new_range - 1;

	long long f2 = s1 + 1, s2 = f2 + new_range - 1;

	long long f3 = s2 + 1, s3 = f3 + new_range - 1;

	if (num == 1) {

		loop(1, new_range, f1, s1);

		loop(3, new_range, f2, s2);

		loop(2, new_range, f3, s3);

	}

	else if (num == 2) {

		loop(2, new_range, f1, s1);

		loop(1, new_range, f2, s2);

		loop(1, new_range, f3, s3);

	}

	else if (num == 3) {

		loop(2, new_range, f1, s1);

		loop(3, new_range, f2, s2);

		loop(2, new_range, f3, s3);

	}

	return;

}

int main() {

	scanf("%d%d%d%d", &X, &L, &R, &N);

	cul();

	loop(X, pow(3, N), 0, pow(3, N) - 1);


	printf("%d %d %d\n", an1, an2, an3);

	return 0;

}
