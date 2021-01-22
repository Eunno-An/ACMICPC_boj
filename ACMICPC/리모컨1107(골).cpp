#include<iostream>
#include<cmath>
//어려운 문제
//https://seol-limit.tistory.com/48

//어떻게 생각하면 쉬운 문제.
//너무 복잡하게 생각하지 말아야 한다는 것을 알려준다.
using namespace std;
bool broken[10];
int check(int n) {
	if (n == 0) {
		if (broken[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while(n > 0) {
		if (broken[n % 10])return 0;
		n = n / 10;
		len += 1;
	}
	return len;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int j;
		cin >> j;
		broken[j] = true;
	}
	int result = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = check(c);
		if (len > 0) {
			int press = abs(c - n);
			if (result > press + len)
				result = press + len;
		}
	}
	cout << result << '\n';
	return 0;
}