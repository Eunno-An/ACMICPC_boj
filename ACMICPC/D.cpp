#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>

using namespace std;

/*
백준 대회 ID
	579_013
	ZgdxHXStpraTGmCT

- endl 대신 '\n' 사용하기
- cin.tie(0) 사용
- 테스트 케이스 있는 문제일 시 전역변수 초기화 신경쓰기
- (A + B + C) % D = ((A + B) % D + C) % D
- 문자열 출력 문제는 정답 문자열 복사해서 코드에 넣기
- 괄호 사용 유의하기
- 문자열은 함수로 넘길 때 const & 잘 사용하기

- 최악의 경우 int 값 초과하는지, 배열 인덱스 초과하는지 확인
- n 범위 확인 (0인 경우), 양수음수 정수소수 확인, 불가케이스 -1 출력 등 확인
- 큰 배열 선언 시 전역선언, 테케 많을 시 초기화, 배열 용량 max N + 5
*/

#define MOD 1000000007
#define INT_MAX 987654321
#define MAX 100005

typedef long long int ll;
typedef pair<int, int> pii;
int N, M;
int arr[2001][2001];
int before[2001][2001];
//오른쪽, 대각 오른 아래, 아래, 왼쪽 아래, 왼쪽, 위에 왼쪽, 위에, 오른쪽 위에
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 }; 
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
// 테스트 케이스 초기화 시
void init()
{
	
}

long long calculate_max(int x, int y, int m) {
	long long max = (long long)3000000000 * -1;
	for (int i = x; i < x + m; i++) {
		for (int j = y; j < y + m; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}
	return max;
}

void fix_matrix(int x, int y, long long value) {
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = (M - 1) / 2; i <= N - (M - 1) / 2 - 1; i++) {
		for (int j = (M - 1) / 2; j <= N - (M - 1) / 2 - 1; j++) {
			if (j == (M - 1) / 2) {

			}
			before[i][j] = arr[i - M / 2][j - M / 2];

		}
	}
	if (N == M || M==1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << 0 << ' ';
			}
			cout << '\n';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	

	return 0;
}