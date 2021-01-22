
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
vector<pair<int, int>> cost_N;
int my_money;
vector<int> max_result;
// 테스트 케이스 초기화 시
void init()
{

}
bool is_max(vector<int> a, vector<int> b) {
	// if true, a is bigger than b
	if (a.size() > b.size()) {
		return true;
	}
	if (a.size() < b.size()) {
		return false;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < b[i]) {
			return false;
		}
	}
	return true;
}/*
calc(2, 21, 0, temp)
->calc(2, 21, 8, temp)
->calc(2, 21, 16, temp)->calc(2, 21, 24, temp) -> if :  calc(1, 21, 16, temp)->calc(1, 21, 23, temp) ->  if calc(0, 21, 16, temp)->calc(0, 21, 22, temp)->calc(-1, 21, 16, temp) : return
																																 

*/
// (2,) (2, ) (2,)
//            (1, )
//            (0, )
//            (-1,)
//       (1, )(1, )
//       (1, )(0, )
//            (-1, )
//       (0, )(0, )
//       (0, )(-1,)
//(2, )(1, )(1, )
//(2, )(1, )(0, )
//			(-1,)
void cal_max(int idx, int cost, int now_cost, vector<int> temp) { // 재귀로 짜야함
	if (idx < 0) {
		bool flag = is_max(max_result, temp);
		if (!flag) {
			max_result = temp;
		}
		return;
	}
	if (cost < now_cost) {
		now_cost -= cost_N[idx].first;
		temp.pop_back();
		cal_max(idx-1, cost, now_cost, temp);
		return;
	}
	now_cost += cost_N[idx].first;
	temp.push_back(idx);
	for (int i = idx; i >= 0; i--) {
		cal_max(i, cost, now_cost, temp);
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	pair<int, int> cost; // first = cost of number, second = number
	for (int i = 0; i < N; i++) {
		cin >> cost.first;
		cost.second = i;
		cost_N.push_back(cost);
	}
	cin >> my_money;
	vector<int> temp;
	cal_max(cost_N.size() - 1, my_money, 0, temp);
	for (int i = 0; i < max_result.size(); i++) {
		cout << max_result[i];
	}
	cout << '\n';


	return 0;
}