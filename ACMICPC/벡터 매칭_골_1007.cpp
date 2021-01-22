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
백준 대회 ID
	579_013
	ZgdxHXStpraTGmCT

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
int N;
vector<pair<int, int>> inputs;
bool comb_idxs[21] = { false, };
double result = 9223372036854775807;
double temp;
// 테스트 케이스 초기화 시
void init()
{
	inputs.clear();
	for (int i = 0; i < N; i++) {
		comb_idxs[i] = false;
	}
	temp = 0;
	result = 9223372036854775807;
}
void vector_matching(int index, int r, int count) {
	if (r == count) {
		double sum_x = 0, sum_y = 0;
		double sum_minus_x = 0, sum_minus_y = 0;
		for (int i = 0; i < N; i++) {
			if (comb_idxs[i]) {
				sum_x += inputs[i].first;
				sum_y += inputs[i].second;
			}
			else {
				sum_x -= inputs[i].first;
				sum_y -= inputs[i].second;
			}
		}
		temp = sqrt(pow(sum_x, 2) + pow(sum_y, 2));
		if (temp < result) result = temp;
		return;
	}
	if (index == N) {
		return;
	}
	comb_idxs[index] = true;
	vector_matching(index + 1, r, count+1);
	comb_idxs[index] = false;
	vector_matching(index + 1, r, count);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	pair<int, int> input;
	while (T--) {
		cin >> N;
		

		init();
		for (int i = 0; i < N; i++) {
			cin >> input.first >> input.second;
			inputs.push_back(input);
		}
		
		if (N == 2) {
			cout << fixed << setprecision(12) << sqrt(pow(inputs[0].first - inputs[1].first, 2) + pow(inputs[0].second - inputs[1].second, 2)) << '\n';
			continue;
		}
		vector_matching(0, N / 2, 0);
		cout << fixed << setprecision(12) << result << '\n';
	}


	return 0;
}