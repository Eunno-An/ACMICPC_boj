
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

int T;
int arr_zero[51] = {};
int arr_first[51] = {};
int zero_count = 0;
int first_count = 0;
// 테스트 케이스 초기화 시
void init()
{
	for (int i = 0; i < 51; i++) {
		arr_zero[i] = 0;
		arr_first[i] = 0;
	}
}

int fibonacci_zero(int N) {
	if (N == 0) {
		return arr_zero[0] = 1;
	}
	if (N == 1) {
		return 0;
	}
	if (arr_zero[N]) {
		return arr_zero[N];
	}
	return arr_zero[N] = fibonacci_zero(N - 1) + fibonacci_zero(N - 2);
}
int fibonacci_first(int N) {
	if (N == 0) {
		return 0;
	}if (N == 1) {
		return arr_first[1] = 1;
	}if (arr_first[N]) {
		return arr_first[N];
	}return arr_first[N] = fibonacci_first(N - 1) + fibonacci_first(N - 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		init();
		int N;
		cin >> N;
		cout << fibonacci_zero(N) << ' '  << fibonacci_first(N) << '\n';
	}


	return 0;
}