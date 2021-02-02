
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
int n;
int arr[3][100001];
int dp[3][100001];
// 테스트 케이스 초기화 시
void init()
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
			dp[i][j] = 0;
		}
	}
}

//┌ 을 선택했을 때(1, j),
//
//1. 오른쪽 아래 꼭짓점 하나만 남는경우 : arr[2][j + 1]
//2. ┘가 남는 경우, 두 가지 경우를 비교 :
//2 - 1 : arr[2][j + 1]과 arr[1][j + 2]을 선택 : 또 2 케이스로 반복됨.
//2 - 2 : arr[2][j + 2]를 선택 : 위에 1번과 아래 1번을 비교하는 경우
//
//
//└ 을 선택했을 때(2, j),
//1. 오른쪽 위 꼭짓점 하나만 남는경우 : arr[1][j + 1]
//2. ┐가 남는 경우, 두 가지 경우를 비교 :
//2 - 1 : arr[1][j + 1]과 arr[2][j + 2]를 선택 : 또 2케이스로 반복됨.
//2 - 2 : arr[1][j + 1]를 선택 : 위에 1번과 아래 1번을 비교하는 경우

//50 10 100 20 40
//30 50 70 10 60
//
//50 선택 -> 50과 100선택 -> 60선택
//
//7
//10 30 10 50 100 20 40
//20 40 30 50 60 20 80
//
//3
//20 80 70
//10 30 20
//두 개의 케이스를 해서 최대 최소를 비교해 나가는 수 밖에 없음.
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		init();
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + dp[1][0];
		dp[1][1] = arr[1][1] + dp[0][0];

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = arr[0][i] + std::max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = arr[1][i] + std::max(dp[0][i - 1], dp[0][i - 2]);
		}


		cout << std::max(dp[0][n - 1], dp[1][n - 1]) << endl;
	}


	return 0;
}