
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
// 테스트 케이스 초기화 시
void init()
{

}

int main()
{
	//7분 7초
	//DP로 해결할 수 있을 것 같음.
	//DP[i] += DP[i-1] + arr[i];

	//해결 방법
	//arr[i]를 소트한 다음에 
	//각 단계 i에서는 0부터 i-1까지의 합을 더해준 것이 최소시간이 됨.
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	//각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	ll result = 0;
	for (int i = 0; i < N; i++) {
		ll temp = 0;
		for (int j = 0; j < i; j++) {
			temp += arr[j];
		}
		result += temp + arr[i];
	}
	cout << result << '\n';
	return 0;
}