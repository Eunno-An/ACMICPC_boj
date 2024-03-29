
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
int arr[100001];
// 테스트 케이스 초기화 시
void init()
{

}

//16분 40초
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
	sort(arr, arr + N);
	int max = -1;
	int weight = 0;
	int count = 1;
	for (int i = N - 1; i >= 0; i--) {
		weight += arr[i];
		if (max < arr[i] * count) {
			max = arr[i] * count;
		}
		count++;
	}
	cout << max << '\n';


	/*
	2
	10 15
	-> 10 15를 사용하여 드는 방법, 15를 사용하여 드는 방법, 10을 사용하여 드는 방법

	5
	2 4 30 6 40
	1. 꼭 min * N이 최대 중량이 아닐 수 있다.
	2. 그렇다고 해서 max가 최대 중량이 아닐 수 있다.
	3. 조합으로 할 경우 시간초과가 발생할 수 있다.
	*/
	return 0;
}
