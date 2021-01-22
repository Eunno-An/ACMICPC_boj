
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

int arr[51][51];
int temp[51][51];
int N, M;
int K;
// 테스트 케이스 초기화 시
void init()
{

}

int main()
{
	
	init();
	cin >> N >> M;
	int a;
	vector<int> count_row_zero;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &a);
			arr[i][j] = a;	
		}
	}
	cin >> K;
	//1. 특정 행의 0개수 조건이 (완전히 킬 수 있는지 아닌지 확인)
	int count_zero = 0;
	int result = 0;
	int max_result = -1;
	vector<int> idx_able;
	for (int i = 0; i < N; i++) {
		count_zero = 0;
		result = 0;
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				count_zero++;
			}
		}
		if (count_zero <= K && count_zero % 2 == K % 2) {
			for (int j = 0; j < N; j++) {
				int row_match_count = 0;
				for (int k = 0; k < M; k++) {
					if (arr[j][k] == arr[i][k]) {
						row_match_count++;
					}
				}
				if (row_match_count == M) {
					result++;
				}
			}
		}
		max_result = max_result < result ? result : max_result;
	}
	cout << max_result << '\n';
	return 0;
}