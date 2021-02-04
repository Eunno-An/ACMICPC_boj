
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
int arr[1001];
int dp_ascending[1001];
int dp_descending[1001];
int dp_bitonic[1001];
// 테스트 케이스 초기화 시
void init()
{
	for (int i = 1; i <= N; i++) {
		dp_ascending[i] = 1;
		dp_descending[i] = 1;
		dp_bitonic[i] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/*for (int i = 1; i <= 500; i++) {
		cout << i << ' ';
	}
	for (int i = 499; i >= 1; i--) {
		cout << i << ' ';
	}*/
	cin >> N;

	init();
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		int max_val = dp_ascending[i];
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) {
				if (max_val < dp_ascending[j] + 1) {
					max_val = dp_ascending[j] + 1;
				}
			}
		}
		dp_ascending[i] = max_val;
	}
	
	for (int i = N; i >= 1; i--) {
		int max_val = dp_descending[i];
		for (int j = i; j <= N; j++) {
			if (arr[i] > arr[j]) {
				if (max_val < dp_descending[j] + 1) {
					max_val = dp_descending[j] + 1;
				}
			}
		}
		dp_descending[i] = max_val;
	}
	/*
	for (int i = 1; i < N; i++) {
		if (arr[i] != arr[i + 1]) {
			dp_bitonic[i] = dp_ascending[i] + dp_descending[i + 1];
		}
		else {
			dp_bitonic[i] = max(dp_ascending[i], dp_descending[i]);
		}
	}*/
	//dp_bitonic[N] = dp_ascending[N];

	for (int i = 1; i <= N; i++) {
		dp_bitonic[i] = dp_ascending[i] + dp_descending[i] - 1;
	}

	int max_val = 1;
	for (int i = 1; i < N; i++) {
		if (max_val < dp_bitonic[i]) {
			max_val = dp_bitonic[i];
		}
	}
	cout << max_val << '\n';
	return 0;
}
//
//5 1 4 4 2 3 2 1 1 1
//1 5 2 1 4 3 3 3 2 1
//1 1 1 1 1 1 1 1 1 1
