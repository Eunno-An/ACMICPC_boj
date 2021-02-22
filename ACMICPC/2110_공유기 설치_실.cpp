
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
int N, C;
vector<int> pos_home;
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
	cin >> N >> C;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		pos_home.push_back(input);
	}
	sort(pos_home.begin(), pos_home.end());
	if (C == 2) {
		cout << pos_home[pos_home.size() - 1] - pos_home[0] << '\n';
		return 0;
	}
	else {
		//공유기 간의 거리를 이분 탐색의 탐색 대상으로 생각
		//어디에 놓을지를 먼저 생각하기 보다, 얼만큼 떨어진 곳에 두어야 하는지
		int left = 1;
		int right = pos_home[N - 1] - pos_home[0];
		int d = 0;
		int ans = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			int start = pos_home[0];
			int cnt = 1;
			for (int i = 1; i < N; i++) {
				d = pos_home[i] - start;
				if (mid <= d) {
					++cnt;
					start = pos_home[i];
				}
			}

			if (cnt >= C) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}