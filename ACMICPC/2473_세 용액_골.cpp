
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
ll arr[5001];
vector<int> a;
vector<int> b;
vector<int> c;
// 테스트 케이스 초기화 시
void init()
{

}

int main()
{
	//3-sum 알고리즘
	//2467 문제와 비슷함
	//그러나 못풀었음. 이분탐색 할 필요도 없음.
	//그냥 투포인터로 풀어도 되는 문제
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int ans1, ans2, ans3;
	if (arr[0] >= 0) {
		ans1 = arr[0];
		ans2 = arr[1];
		ans3 = arr[2];
	}
	else if (arr[N - 1] <= 0) {
		ans1 = arr[N - 3];
		ans2 = arr[N - 2];
		ans3 = arr[N - 1];
	}
	else {
		ll mini = 3e10 + 7;
		for (int i = 0; i < N - 1; i++) {
			int j, k;
			j = i + 1;
			k = N - 1;
			while (1) {
				if (j >= k)
					break;
				ll x = arr[i] + arr[j] + arr[k];
				ll nx = x < 0 ? -x : x;
				if (mini > nx) {
					mini = nx;
					ans1 = arr[i];
					ans2 = arr[j];
					ans3 = arr[k];
				}
				if (x > 0) {
					k--;
				}
				else {
					j++;
				}
			}
		}
	}
	cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
	return 0;
	//https://zzudy.tistory.com/50
}