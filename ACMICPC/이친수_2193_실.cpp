
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
int count_twchin = 0;
int dp[2][91] = {};
ll fibo[91] = {};
// 테스트 케이스 초기화 시
void init()
{

}
ll fibonacci(int number) {
	if (number == 1) {
		return fibo[number] = 1;
	}
	if (number == 2) {
		return fibo[number] = 1;
	}
	if (fibo[number]) {
		return fibo[number];
	}
	return fibo[number] = fibonacci(number - 1) + fibonacci(number - 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[91] = {};
	init();
	cin >> N;
	if (N == 1 || N == 2) {
		cout << 1 << '\n';
		return 0;
	}
	cout << fibonacci(N) << '\n';
	//규칙이 그냥 피보나치임.



	//dp배열의 의미
	//dp[0][i]는 i번째 자릿수가 0이냐 1이냐를 의미
	//dp[1][1] = 1;
	//dp[0][2] = 1;
	//for (int i = 3; i <= N; i++) {//dp[0][3]과 dp[1][3]의 케이스가 생김. dp [0][3] = do[0][2], dp[1][3] = dp[0][2]+1
	//	if (dp[0][i - 1] != 0) {
	//		dp[0][i] = dp[0][i-1];
	//		dp[1][i] = dp[0][i-1];
	//	}
	//	if (dp[1][i - 1] != 0) { // i-1이 1 일 때
	//		dp[0][i] += 1;
	//	}
	//}
	//cout << dp[0][N] + dp[1][N] << '\n';
	//dp[0]: 0 1 1 1
	//dp[1]: 1 0 1 1

	return 0;
}