
#define _CRT_SECURE_NO_WARNINGS

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
#include<iomanip>

using namespace std;

/*
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
int N;
int dp[1001][11];
ll count = 0;
// 테스트 케이스 초기화 시
void init()
{

}
/*
* dp[n][i]
* dp[n][10] = 길이가 n인 오르막 수의 앞자리가 i일 때 1부터 i까지의 오르막 수의 개수 합
* dp[1][10] = 1 2 3 4 5 6 7 8 9 10 ( 0 ~ 9 까지)
* dp[2][10] = 00 ~ 09(앞자리 0), 11~19(앞자리 1), ... 99(앞자리 9)
*			= dp[1][10],dp[1][9] +dp[2][1], dp[1][8] + dp[2][2], ... ,dp[1][1] + dp[2][9]
* dp[3][10] = dp[2][10], dp[2][9] + dp[3][0], ...
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	
	for (int i = 1; i <= 10; i++) {
		dp[0][i] = 1;
		dp[1][i] = i;
	}
	for (int i = 2; i <= N; i++) {
		dp[i][1] = 1;
		for (int j = 2; j <= 10; j++) {
			dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
		}
	}
	cout << dp[N][10] << '\n';
	return 0;
}