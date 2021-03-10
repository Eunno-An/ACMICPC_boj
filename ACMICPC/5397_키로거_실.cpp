
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

int T;
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
	string L;
	
	for (int test_case = 0; test_case < T; test_case++) {
		stack<char> left;
		stack<char> right;
		cin >> L;
		for (int i = 0; i < L.size(); i++) {
			if (L[i] == '<') {
				if (left.empty()) {
					continue;
				}
				char x = left.top(); left.pop();
				right.push(x);
			}
			else if (L[i] == '>') {
				if (right.empty()) {
					continue;
				}
				char x = right.top(); right.pop();
				left.push(x);
			}
			else if (L[i] == '-') {
				if (left.empty()) {
					continue;
				}
				left.pop();
			}
			else {
				left.push(L[i]);
			}
		}

		vector<char> left_vec;
		while (!left.empty()) {
			left_vec.push_back(left.top());
			left.pop();
		}
		for (int i = left_vec.size() - 1; i >= 0; i--) {
			cout << left_vec[i];
		}
		while (!right.empty()) {
			cout << right.top();
			right.pop();
		}
		cout << '\n';
		
	}


	return 0;
}