
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
int N, P;

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
	stack<int> s1, s2, s3, s4, s5, s6;
	cin >> N >> P;
	int input1, input2;
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> input1 >> input2;
		if(input1 == 1){
			if (s1.empty()) {
				s1.push(input2);
				count++;
			}
			
			else {
				while (s1.top() > input2) {
					s1.pop();
					count++;
					if (s1.empty()) {
						break;
					}
				}
				if (!s1.empty() && s1.top() == input2) {
					continue;
				}
				s1.push(input2);
				count++;
			}
		}
		else if(input1 == 2){
			if (s2.empty()) {
				s2.push(input2);
				count++;
			}
			else {
				while (s2.top() > input2) {
					s2.pop();
					count++;
					if (s2.empty()) {
						break;
					}
				}
				if (!s2.empty() && s2.top() == input2) {
					continue;
				}
				s2.push(input2);
				count++;
			}
		}
		else if(input1 == 3){
			if (s3.empty()) {
				s3.push(input2);
				count++;
			}
			else {
				while (s3.top() > input2) {
					s3.pop();
					count++;
					if (s3.empty()) {
						break;
					}
				}
				if (!s3.empty() && s3.top() == input2) {
					continue;
				}
				s3.push(input2);
				count++;
		}
			}
		else if(input1 == 4){
			if (s4.empty()) {
				s4.push(input2);
				count++;
			}
			else {
				while (s4.top() > input2) {
					s4.pop();
					count++;
					if (s4.empty()) {
						break;
					}
				}
				if (!s4.empty() && s4.top() == input2) {
					continue;
				}
				s4.push(input2);
				count++;
			}
		}
		else if(input1 == 5){
			if (s5.empty()) {
				s5.push(input2);
				count++;
			}
			else {
				while (s5.top() > input2) {
					s5.pop();
					count++;
					if (s5.empty()) {
						break;
					}
				}
				if (!s5.empty() && s5.top() == input2) {
					continue;
				}
				s5.push(input2);
				count++;
			}
		}
		else {
			if (s6.empty()) {
				s6.push(input2);
				count++;
			}
			else {
				while (s6.top() > input2) {
					s6.pop();
					count++;
					if (s6.empty()) {
						break;
					}
				}
				if (!s6.empty() && s6.top() == input2) {
					continue;
				}
				s6.push(input2);
				count++;
			}
		}
	}
	cout << count << '\n';
	return 0;
}