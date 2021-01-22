#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int, int);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int input_gcd = v[1] - v[0];
	for (int i = 2; i < N; i++) {
		input_gcd = gcd(input_gcd, v[i] - v[i - 1]);
	}
	vector<int> result;
	for (int i = 2; i * i <= input_gcd; i++) {//약수 최적화
		if (input_gcd % i == 0) {
			result.push_back(i);
			result.push_back(input_gcd / i);
		}
	}
	result.push_back(input_gcd);
	sort(result.begin(), result.end());

	result.erase(unique(result.begin(), result.end()), result.end());

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << '\n';
}
int gcd(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}