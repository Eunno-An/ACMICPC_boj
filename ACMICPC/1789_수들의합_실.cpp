
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

long long int S;
vector<ll> vector_N;
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
	cin >> S;
	if (S <= 2) {
		cout << 1 << '\n';
		return 0;
	}
	//S = 200
	//S = 1 , N = 1 (1)
	//S = 2 , N = 1 (2)
	//S = 3 , N = 2 (1, 2), (3)
	//S = 4 , N = 2 (1, 3)
	//S = 5 , N = 2 (2, 3)
	//S = 6 , N = 3 (1, 2, 3)
	//S = 7 , N = 3 (1, 2, 4)
	//S = 10, N = 4 (1, 2, 3, 4)
	//1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210  
	ll N = 2;
	ll temp = 1;
	int count = 0;
	while (temp <= S) {
		temp += N;
		N += 1;
		count++;
	}
	cout << count << '\n';
	return 0;
}