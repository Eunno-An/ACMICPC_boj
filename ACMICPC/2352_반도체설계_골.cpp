
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
int n;
int port[40001];
int dp[40001];
// 테스트 케이스 초기화 시
void init()
{

}
int b_search(int r, int val) {
	int l = 0, mid, result = r;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (dp[mid] >= val) {
			result = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return result;
}
int main()
{
	//이분 탐색과 LIS가 같이 있는 문제,
	//lower_bound로 쉽게 할 수 있으나 직접 구현해보는것도 좋음
	//LIS까진 생각했으나, 이분 탐색을 어떻게 써야할지 몰랐음
	//이 문제에서 이분탐색은, LIS를 구현할 떄 새로 들어온 수가
	//dp 배열의 마지막 수 보다 작을 때, 그 수가 어디에 들어갈 지를
	//n번만에 탐색하는 것 보다, log n  만에 탐색하는게 키 포인트
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> n;
	int idx = 0;
	for (int i = 0; i < n; i++) { // 모든 수를 담는다
		cin >> port[i];
	}
	dp[0] = port[0]; 
	//dp 배열에 가장 긴 증가하는 부분수열 중에서 idx번째에 위치한 수를 저장한다.
	for (int i = 1; i < n; i++) {
		if (port[i] > dp[idx]) {
			dp[++idx] = port[i];
		}
		else {
			int val = b_search(idx, port[i]);
			dp[val] = port[i];
		}
	}
	cout << idx + 1 << '\n';
	/*
	port : 4 2 6 3 1 5
	dp : 
	4
	idx = 0, port[i] < dp[idx] : val = b_search(0, 2), dp[val] = 2;
	b_search(0, 2): l=0, result = 0, return 0; val = 0, dp[0] = 2;

	dp:
	2
	port[i] > dp[idx] : dp[1] = 6

	dp:
	2 6
	val = b_search(1, 3), l = 0, result = 1
	while(0 <= 1) mid = 0 + 0; dp[0] < val, l = 1
	return 1
	dp[1] = 3
	
	dp:
	2 3

	*/

	return 0;
}