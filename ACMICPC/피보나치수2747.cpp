#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, fibo=1, a0=0, a1=1;
	cin >> n;
	if (n == 1) {
		cout << 1 << '\n';
	}
	else {
		for (int i = 1; i < n; i++) {
			fibo = a0 + a1;
			a0 = a1;
			a1 = fibo;
		}
		cout << fibo << '\n';
	}
	return 0;
}