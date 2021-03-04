
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

int M, N, L;
vector<int> pos_x;
vector<pii> pos_animal;

// 테스트 케이스 초기화 시
void init()
{

}

bool compare(pii& a, pii& b) {
	return a.second > b.second;
}
int main()
{
	//이것도 진짜 좋은문제.
	//동물들의 점 하나를, 사대와의 거리를 비교하면서, 
	//거리조건을 만족하면 결과에 추가하고
	//그렇지 않으면, 사대 중에서 이분탐색을 하여 맞는 사대를 찾는것.

	//중요한 점: 무엇을 찾아야 하는가?
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> M >> N >> L;
	int input_x;
	for (int i = 0; i < M; i++) {
		cin >> input_x;
		pos_x.push_back(input_x);
	}

	pii input;
	for (int i = 0; i < N; i++) {
		cin >> input.first >> input.second;
		if (input.second > L) {
			// 직교거리가 사정거리 L 초과일 경우,
			// 절대 닿을 수 없음.
			continue;
		}
		pos_animal.push_back(input);
	}

	//사대의 위치 pos_x[i]와 동물의 위치 pos_animal[i] 간의 거리는
	//abs(pos_x[i] - pos_animal[i].first) + pos_animal[i].second

	//O(MN) -> time limit
	
	sort(pos_x.begin(), pos_x.end());
	int result = 0;
	for (int i = 0; i < pos_animal.size(); i++) {
		int l = 0, r = pos_x.size() - 1;
		int mid;
		while (l <= r) {
			mid = l + (r - l) / 2;
			int cal = abs(pos_x[mid] - pos_animal[i].first) + pos_animal[i].second;
			if (cal <= L) {
				result++;
				break;
			}
			else {
				if (pos_animal[i].first >= pos_x[mid])
					l = mid + 1;
				else r = mid - 1;
			}
		}
	}
	cout << result << '\n';

	/*
	1 4
	8 4
	9 4
	3 3
	7 2
	2 2
	5 1
	*/
	return 0;
}