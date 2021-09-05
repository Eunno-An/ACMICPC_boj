#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
long long N, L, I;

//Kth DP
//최적화 문제를 푸는 DP를 짜고, 각 단계에서 어떤 선택을 하는지
//따로 배열에 저장한다.

//N자리 이진수 중에서 L개 이하의 비트만 1인 것을 크기순으로 나열했을 때, I번쨰로 나오는 이진수

//최적화 문제: N자리 이진수 중에서 L개 이하의 비트만 사용한 것 중 가장 큰 것

ll cache[31][31];

ll solve(ll N, ll L, ll num) {
	if (N == 0) 
		return num;
	if (L == 0)
		return num << N;
	ll& ret = cache[N][L];
	if (ret != 0)
		return ret;
	ll num1 = solve(N - 1, L - 1, num << 1 + 1);
	ll num2 = solve(N - 1, L, num << 1);
	if (num1 > num2)
		return ret = num1;
	else
		return ret = num2;
};
int main() {
	cin >> N >> L >> I;
	solve(N, L, 0);
}
