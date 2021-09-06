//kth DP
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
typedef long long ll;
ll cache[32][32];
string ans;
void find(ll N, ll L, ll I) {
	if (N == 0) return;
	if (L == 0) {
		for (int i = 0; i < N; i++)
			ans += "0";
		return;
	}
	ll pivot = cache[N - 1][L];
	//앞 자리가 0인 것들의 개수.
	//cout << pivot << endl;
	//나머지 N-1개의 자리수에서도 I번째 큰 수가 나올 수 있다.
	if (pivot >= I) {
		ans += "0";
		find(N - 1, L, I);
	}
	else {
		ans += "1";
		find(N - 1, L - 1, I - pivot);
	}
}
ll calc(ll N, ll L) {
	ll& ret = cache[N][L];
	if (ret != -1)
		return ret;
	if (N == 0 || L == 0) 
		return ret = 1;
	ret = 0;
	return ret = calc(N - 1, L - 1) + calc(N - 1, L);
}
int main() {
	ll N, L, I;
	cin >> N >> L >> I;
	
	memset(cache, -1, sizeof(cache));
	calc(N, L);
	find(N, L, I);
	
	cout << ans << endl;
	return 0;
}
