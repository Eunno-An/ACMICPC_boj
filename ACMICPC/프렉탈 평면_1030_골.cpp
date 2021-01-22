
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

int s, N, K, R1, R2, C1, C2;
int arr[9][9] = {};
// 테스트 케이스 초기화 시
void init()
{

}
int getColor(int x, int y, int time) {
	if (time == 0) {
		return 0;
	}
	int t = (N - K) / 2, j = (int)pow(N, time - 1);

	if (t * j <= x && x < (t + K) * j && t * j <= y && y < (t + K) * j) return 1;
	while (true) {
		if (x - j >= 0) x -= j;
		else break;
	}while (true) {
		if (y - j >= 0) y -= j;
		else break;
		
	}
	return getColor(x, y, time - 1);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= (N - K) / 2 && j >= (N - K) / 2 && i < (N + K) / 2 && j < (N + K) / 2) {
				arr[i][j] = 1;
			}
		}
	}
	//K= 3일 때
	//s = 1 -> i >= 1 && i < 4 && j >= 1 && j < 4
	//s = 2 -> i >=
	
	for (int i = R1; i <= R2; i++) {
		for (int j = C1; j <= C2; j++) {
			cout << getColor(i, j, s);
		}
		cout << '\n';
	}

	return 0;
}