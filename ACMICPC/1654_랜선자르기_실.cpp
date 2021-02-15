
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
#define MAX_LINE 2147483647
typedef long long int ll;
typedef pair<int, int> pii;
int K, N;
ll length[1000001];


ll result;
ll max_num[1000001];
// 테스트 케이스 초기화 시
void init()
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> K >> N;
	
	ll input;
	ll max_line = -1;
	for (int i = 0; i < K; i++) {
		cin >> input;
		if (max_line < input) {
			max_line = input;
		}
		length[i] = input;
	}
	if (N == 1) {
		cout << max_line;
		return 0;
	}
	//1부터 21억까지의 랜선길이를 탐색해야 함.
	//사소한 조건 하나하나가 중요하네..
	ll max_length = 0;
	ll lo = 1, hi = max_line;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		ll sum = 0;
		for (int i = 0; i < K; i++) {
			sum += length[i] / mid;
		}
		if (sum >= N) {
			lo = mid+1;
		}
		else {
			hi = mid-1;
		}
		
	}
	cout << hi << '\n';
	
	return 0;
}