
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
int A[4001], B[4001], C[4001], D[4001];
vector<int> AB;
vector<int> CD;
ll ans;
// 테스트 케이스 초기화 시
void init()
{

}
/*
CD벡터가 오름차순으로 정렬되어 있으므로
CD[i]가 -AB[j]와 같은 값을 이분탐색으로 찾으면 된다.
근데 같은 값이 여러개일 수도 있으니
맨 앞 인덱스를 반환하는 것과
맨 뒤 인덱스를 반환하는 함수로 나누어 준다.
*/
ll getS(ll value) {
	int start, end;
	//내가 찾는 -AB[i]의 값이 cd 벡터의 맨 앞의 값보다 큰 경우
	//start에 0번 인덱스
	if (CD[0] < value) start = 0;
	//cd벡터의 맨 앞의 값보다 작으면 탐색할 필요가 없음
	else if (CD[0] > value) return -1;
	//같은 경우 0번 인덱스 반환
	else return 0;

	//내가 찾고자 하는 값이 cd벡터의 맨 뒤보다 큰 경우
	//찾을 필요 없음
	if (CD[CD.size() - 1] < value)return -1;
	else end = CD.size() - 1;
	//1 3 4 5 7
	//5을 찾고 싶을 때
	//start = 0, end = 4
	//mid = 2
	//start = 2, end = 4
	//mid = 3
	//end = 3
	//mid = 2
	while (1) {
		int mid = (start + end) / 2;
		//start 다음에 end가 위치하게 되면
		//end일 가능성이 높다.
		if (start + 1 == end) {
			if (CD[end] == value)return end;
			else return -1;
		}

		if (CD[mid] >= value) end = mid;
		else start = mid;
	}

}
ll getE(ll value) {
	int start, end;
	if (CD[0] <= value) start = 0;
	else return -1;

	if (CD[CD.size() - 1] < value)return -1;
	else if (CD[CD.size() - 1] > value)end = CD.size() - 1;
	else return CD.size() - 1;

	while (1) {
		int mid = (start + end) / 2;
		if (start + 1 == end) {
			if (CD[start] == value) return start;
			else return -1;
		}
		if (CD[mid] > value) end = mid;
		else start = mid;
	}
}
ll solve() {
	for (int i = 0; i < AB.size(); i++) {
		ll src = getS(-AB[i]), dst = getE(-AB[i]);
		if (src == -1 || dst == -1) continue;
		ans += dst - src + 1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> n;
	ll input1, input2, input3, input4;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}
	sort(CD.begin(), CD.end());
	cout << solve() << '\n';
	return 0;
}