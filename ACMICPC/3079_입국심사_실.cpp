
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

#define MOD 1000000000 //십억칠
#define INT_MAX 987654321
#define MAX 100005

typedef long long int ll;
typedef pair<int, int> pii;

int N, M;
int arr[MAX];
// 테스트 케이스 초기화 시
void init()
{

}
ll calc(ll mid) {
	ll res = 0;
	for (int i = 0; i < N; i++) {
		res += mid / arr[i]; // 시간 mid 동안, 시간 arr[i]만큼 걸리는 심사관은 총 mid / arr[i]만큼을 처리할 수 있다.
	}return res;
}
int main()
{
	/*
	M명을 N개의 심사대에서 심사, 최소의 시간
	N개의 심사 시간이 주어짐
	1. N <= M일 때, 항상 N을 다 채운다고 최소로 되는건 아님
	7 10
	0초: 7초 10초
	7초: 14초 10초
	10초: 14초 20초
	14초: 21초 20초
	20초: 21초 30초 or 21ch: 28초 20초

	*/
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	ll lo = arr[0], hi = (ll)arr[N - 1] * M;
	ll ans = 0;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll c = calc(mid);
		if (c >= M) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}