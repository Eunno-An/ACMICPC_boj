
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
const int MAXN = 1000001;

typedef long long int ll;
typedef pair<int, int> pii;
int n;
ll A, B;
ll C;
vector<pair<int, ll>> candy_box_vec;
int tree[MAXN * 4];
// 테스트 케이스 초기화 시
void init()
{

}
void update(int index, int target, int diff, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(index * 2, target, diff, start, mid);
	update(index * 2 + 1, target, diff, mid + 1, end);
}

int query(int index, int target, int start, int end) {
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	if (target <= tree[index * 2])
		return query(index * 2, target, start, mid);
	else // 1 2 3 4 5 라는 리프노드를 가진 세그트리가 있을 때, 루트노드의 자식 노드가 10, 5 라고 가정하고, target이 11일때
		//우린 트리에 대해서 순위를 판단하는 것이기 때문에 target - tree[inde*2]를 넘겨주어야 한다.
		return query(index * 2 + 1, target - tree[index * 2], mid + 1, end);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> n; //사탕상자에 손을 댄 횟수
	//맨 처음에 사탕상자에는 아무것도 없다고 가정.

	/*
	B라는 사탕 순위의 캔디를 "찾아서" 하나 꺼내야 함
	1. 앞에서부터 B번째에 있는 캔디를 찾는다? O(n^2) 타임리밋
	2. 전체 사탕의 개수 = candy_e
	   0에서 부터 전체 사탕 개수(ex 100)
	   앞에서 3번째에 있는 사탕의 맛이 무엇이냐?
	   50번째 사탕의 맛은?
	   25번째 사탕의 맛은?
	   12번째 사탕의 맛은?
	   6번째 사탕의 맛은?
	   3번째 사탕의 맛은?
	   1번째 사탕의 맛은?
	   2번쨰 사탕의 맛은?
	*/
	
	ll candy_s = 0, candy_e = 0; 
	for (int i = 0; i < n; i++) {
		cin >> A;
		if (A == 1) { //사탕상자에서 사탕을 꺼내는 경우
			cin >> B; // 꺼낼 사탕의 순위
			//구간의 합을 빠르게 뽑아야 하는 자료구조 -> 세그트리 필요
			int favor = query(1, B, 1, MAXN);
			cout << favor << '\n';
			update(1, favor, -1, 1, MAXN);

		}
		else if (A == 2) { //사탕을 넣는 경우
			cin >> B >> C; // B: 넣고 뺄 사탕의 맛, C: 사탕의 갯수
			update(1, B, C, 1, MAXN);
		}
	}
	

	return 0;
}