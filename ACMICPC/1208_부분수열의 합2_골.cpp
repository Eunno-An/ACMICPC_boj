
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

int N, S;
int arr[41];
vector<int> a1;
vector<int> a2;

// 테스트 케이스 초기화 시
void init()
{

}

int main()
{
	//부분수열을 구하는 방법
	//조합 방식: 2^40 -> time limit
	//반으로 나눠서 왼쪽 조합 2^20, 오른쪽 조합 2^20
	//결국 투포인터의 개념도 들어감.
	//그리고 정렬
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> N >> S;
	int pos_sum = 0;
	int neg_sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i < N / 2) {
			a1.push_back(arr[i]);
		}
		else {
			a2.push_back(arr[i]);
		}
	}
	vector<int> set1;
	vector<int> set2;
	int s1 = a1.size(), s2 = a2.size();
	for (int i = 0; i < (1 << s1); i++) {//0 to 3
		int sum = 0;
		for (int j = 0; j < s1; j++) {//0 to 1
			if (i & (1 << j)) {
				sum += a1[j];
			}
		}
		//cout << sum << '\n';
		set1.push_back(sum);//0, 
	}
	for (int i = 0; i < (1 << s2); i++) {
		int sum = 0;
		for (int j = 0; j < s2; j++) {
			if (i & (1 << j)) {
				sum += a2[j];
			}
		}set2.push_back(sum);
	}
	sort(set1.begin(), set1.end());
	sort(set2.begin(), set2.end());
	int left = 0, right = set2.size() - 1;
	long long ans = 0;
	s1 = set1.size(), s2 = set2.size();
	while (left < s1 && right >= 0) {
		int sum = set1[left] + set2[right];
		if (sum < S) {
			++left;
		}
		else if (sum > S) {
			--right;
		}
		else {
			long long c1 = 1, c2 = 1;
			for (int i = left + 1; i < s1; ++i, ++c1) {
				if (set1[left] != set1[i]) break;
			}
			for (int i = right - 1; i >= 0; --i, ++c2) {
				if (set2[right] != set2[i]) break;
			}
			ans += c1 * c2;
			left += c1;
			right -= c2;
		}
	}
	if (S == 0) --ans;
	cout << ans;
	//https://dawninthemoon.tistory.com/73
	
	return 0;
}