
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
ll arr[100001];
// 테스트 케이스 초기화 시
void init()
{

}
void solve() {
	ll max_result = 0;
	stack<int> s;
	int idx = 0;
	while (idx < N) {
		if (s.empty() || arr[s.top()] <= arr[idx]) {//새로 들어오는 히스토그램의 높이가, 저장된 히스토그램보다 더 높을 경우, 푸쉬 하자. 
			//왜냐하면 기존에 있는 (작은 히스토그램)들로, 새로 들어오는(큰 히스토그램)을
			//자를 수 있으니까, 후보에 넣는거다.
			//스택에 넣는 값은, 이 히스토그램의 인덱스이다.
			s.push(idx++);
		}
		else {
			//새로 들어오는 히스토그램의 높이가, 저장된 히스토그램 후보들의 마지막보다 더 낮을 경우이다.


			//기존에 저장된 히스토그램들은 반드시 (오름차순 정렬)이 되어있을 것이다.
			//그런데, 낮은 값이 들어오면, 이 성질이 깨지므로 
			//이 성질을 유지시켜줄 때 까지 스택에서 pop 해야 한다.
			//else문에서는 딱 한번 pop을 하지만, idx를 증가시켜주지 않으므로, 위의 while문에 의해서, arr[idx]보다 더 작거나 같은 값이 나올 때까지 pop해주게 된다.
			
			//2 4 5 1이라는 input에서, 1이 들어왔을 떄를 가정해 보자.
			//5, 4*2, 2 * 3을 계산해주면서 max값이 갱신될 것이다. 마지막에 2*3은 스택이 비어있을 떄, idx-s.top() -1을 하게 되면 오류가 발생하므로, 예외처리를 해 준것이ㅏㄷ.
			
			int tp = s.top();
			s.pop();
			ll area = arr[tp] * (ll)(s.empty() ? idx : idx - s.top() - 1);
			if (max_result < area) {
				max_result = area;
			}
		}
	}
	while (s.empty() == false) {
		int tp = s.top();
		s.pop();
		ll area = arr[tp] * (s.empty() ? idx : idx - s.top() - 1);
		if (max_result < area) {
			max_result = area;
		}
	}
	cout << max_result << '\n';

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	solve();

	return 0;
}