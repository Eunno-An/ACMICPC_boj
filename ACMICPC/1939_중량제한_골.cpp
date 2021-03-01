
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

int N, M, start, fin;
vector<pair<int, int>> v[100000];
bool visited[100000];
// 테스트 케이스 초기화 시
void init()
{
	
}
bool bfs(int mid) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		if (from == fin) return true;
		for (int i = 0; i < v[from].size(); i++) {
			int next = v[from][i].first;
			int nextC = v[from][i].second;
			if (visited[next]) continue;
			if (mid <= nextC) {//현재 트럭의 중량보다, 중량제한이 더 클 경우, 갈 수 있음
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}
//전형적인 BFS + Binary Search 문제.


//파라메트릭 서치란?
//최적화 문제를 결정 문제로 바꾼뒤, 이것을 이분법을 이용해 해결하는 방법

//최적화 문제: 다리에 대한 정보가 주어졌을 때, 중량의 최댓값을 반환
//결정 문제: 다리에 대한 정보와 중량제한의 값이 주어졌을 때,
//			 공장이 있는 두 섬을 중량제한 값 이상으로 오갈 수 있는 방법이 있는가?
//			 즉, 모든 다리의 중량제한의 값이 mid 이상인 경로가 있는가?

//결정문제는 "답 x가 존재하는가?"가 아니라, "x또는 그보다 좋은 답이 있는가?" 라는 질문데 대답해야 한다.
//이렇게 해야 답의 후보가 되는 구간이 연속적으로 존재해서, 최적화 문제에서
//답이 존재하는 범위를 절반으로 줄여나가며 최종적으로는 답이 있는 위치를 맞출 수 있기 때문이다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N >> M;
	int A, B, C;
	int left = 0, right = 0;
	for (int i = 0; i < M; i++) {//A번 섬과 B번 섬 사이에 중량제한 C인 다리가 존재
		cin >> A >> B >> C;
		v[A].push_back(make_pair(B, C));
		v[B].push_back(make_pair(A, C));
		if (right < C) right = C;
	}
	cin >> start >> fin;

	int ans = 0;
	while (left <= right) {
		memset(visited, false, sizeof(visited));
		int mid = (left + right) / 2;
		if (bfs(mid)) {
			left = mid + 1;
			ans = mid;
		}
		else
			right = mid - 1;
	}
	//i1에서 i2로 가는경로 중에서
	//간선의 최대값을 구하는 것

	cout << ans << '\n';

	//https://velog.io/@jua0610/%EB%B0%B1%EC%A4%80-1939-%EC%A4%91%EB%9F%89%EC%A0%9C%ED%95%9C-%ED%8C%8C%EB%9D%BC%EB%A9%94%ED%8A%B8%EB%A6%AD-%EC%84%9C%EC%B9%98
	return 0;
}