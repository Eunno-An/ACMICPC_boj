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

int C, N;
vector<pair<int, int>> arr;
int arr_C[1101] = {};
// 테스트 케이스 초기화 시
void init()
{
	for (int i = 0; i < 1101; i++) {
		arr_C[i] = INT_MAX;
	}
}
bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> C >> N;
	if (C == 0 || N == 0) {
		cout << 0 << '\n';
		return 0;
	}
	pair<int, int> cost_client;
	//cost를 들이면 num_client 만큼 고객이 늘어난다.
	for (int i = 0; i < N; i++) {
		cin >> cost_client.first >> cost_client.second;
		arr_C[cost_client.second] = cost_client.first;
		arr.push_back(cost_client);
	}
	sort(arr.begin(), arr.end(), cmp);
	arr_C[0] = 0;
	for (int i = 1; i <= 1100; i++) {
		for (int j = 0; j < arr.size(); j++) {
			int cost = arr[j].first;
			int client_Num = arr[j].second;
			if (client_Num > i) {
				break;
			}
			//i가 18 이고 j가 3 7 9 18
			arr_C[i] = min(arr_C[i - arr[j].second] + arr[j].first, arr_C[i]);
		}
	}
	int min_value = INT_MAX;
	for (int i = C; i <= 1100; i++) {
		if (min_value > arr_C[i]) {
			min_value = arr_C[i];
		}
	}
	cout << min_value << '\n';
	return 0;
}