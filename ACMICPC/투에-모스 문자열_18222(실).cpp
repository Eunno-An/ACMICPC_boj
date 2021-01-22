
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
long long k;
ll print_k(ll idx) {
	if (idx <= 1) {
		return 0;
	}
	int p = 0;
	while (1) {
		ll result = (long long)pow(2, p);
		if (idx < result) {
			break;
		}
		p += 1;
	}
	return 1 - print_k(idx - pow(2,p-1));
}
long long getV(long long a) {
	long long v = 1;
	while (v * 2 < a) v *= 2;
	return a - v;
}

//1: cnt 1, 0 -> 1
//2 : cnt 1, 1 cnt 2, 0 -> 2
//3 : cnt 1, 1 cnt 2, 0
//4 : cnt 1, 2 cnt 2, 1 cnt 3, 0 -> 3
//5 : cnt 1, 1 cnt 2, 0
//6 : cnt 1, 2 cnt 2, 1 cnt 3, 0
//7 : cnt 1, 3 cnt 2, 1 cnt 3, 0
//8 : cnt 1, 4 cnt 2, 2 cnt 3, 1 cnt 4, 0 -> 4
//9 : cnt 1, 1 cnt 2, 0
//10 : cnt 1, 2 cnt 2, 1 cnt 3, 0
//11 : cnt 1, 3 cnt 2, 1 cnt 3, 0
//12 : cnt 1, 4 cnt 2, 2 cnt 3, 1 cnt 4, 0
//13 : cnt 1, 5 cnt 2, 1 cnt 3, 0
//14 : cnt 1, 6 cnt 2, 2 cnt 3, 1 cnt 4, 0
//15 : cnt 1, 7 cnt 2, 3 cnt 3, 1 cnt 4, 0
//16 : cnt 1, 8 cnt 2, 4 cnt 3, 2 cnt 4, 1 cnt 5, 0 -> 5

//1 2 2 3
//2 3 3 4
//2 3 3 4 3 4 4 5
//3 4 4 5 4 5 5 6
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s = "1";
	
	cin >> k;
	int cnt = 0;
	while (k != 0) {
		cnt++;
		k = getV(k);
	}
	//k에서 k보다 작은 2의 제곱들을 빼면서 1이 되기까지 얼마나 걸렸는지?
	if (cnt % 2 == 1) {
		cout << 0;
	}
	else
		cout << 1;
	

	return 0;
}