
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
/*
	파라메트릭 서치란?
	최적화 문제를 결정 문제로 바꾼뒤, 이것을 이분법을 이용해 해결하는 방법

	최적화 문제: 다리에 대한 정보가 주어졌을 때, 중량의 최댓값을 반환
	결정 문제: 다리에 대한 정보와 중량제한의 값이 주어졌을 때,
			 공장이 있는 두 섬을 중량제한 값 이상으로 오갈 수 있는 방법이 있는가?
			 즉, 모든 다리의 중량제한의 값이 mid 이상인 경로가 있는가?
	*/

typedef long long int ll;
typedef pair<int, int> pii;
int T;
int n, m;
int arr[1001];
vector<int> arr_sub;
int arr2[1001];
vector<int> arr2_sub;
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
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	/*
	1 4 5 7
	3 
	4 1
	6 3 2 -> 1, 2, 3, 4, 5, 6, 7

	1 4 6
	3
	5 2 -> 1 2 3 4 5 6
	
	투포인터

	*/
	//배열의 부분집합의 합 구하기
	for (int i = 0; i < n; i++) {
		int sum = arr[i];
		arr_sub.push_back(arr[i]);
		for (int j = i+1; j < n; j++) {
			sum += arr[j];
			arr_sub.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		int sum = arr2[i];
		arr2_sub.push_back(sum);
		for (int j = i+1; j < m; j++) {
			sum += arr2[j];
			arr2_sub.push_back(sum);
		}
	}
	sort(arr_sub.begin(), arr_sub.end());
	sort(arr2_sub.begin(), arr2_sub.end());
	//절대 중복제거 하면 안된다!
	//투포인트에서 자꾸 막히네..

	int p1 = 0;
	int p2 = arr2_sub.size() - 1;
	ll cnt = 0;
	while (1) {
		if (arr_sub[p1] + arr2_sub[p2] == T) {
			ll cnt1 = 1;
			ll cnt2 = 1;
			while (p1 + 1 <= arr_sub.size() - 1 && arr_sub[p1] == arr_sub[p1 + 1]) {
				p1++;
				cnt1++;
			}
			while (p2 - 1 >= 0 && arr2_sub[p2] == arr2_sub[p2 - 1]) {
				p2--;
				cnt2++;
			}
			cnt += cnt1 * cnt2;
			p1++;
		}
		if (p1 <= arr_sub.size() - 1 && p2 >= 0 && arr_sub[p1] + arr2_sub[p2] < T) {
			p1++;
		}
		if (p1 <= arr_sub.size() - 1 && p2 >= 0 && arr_sub[p1] + arr2_sub[p2] > T)
			p2--;
		if (p1 > arr_sub.size() - 1 || p2 < 0)
			break;
	}
	cout << cnt << '\n';


	return 0;
}