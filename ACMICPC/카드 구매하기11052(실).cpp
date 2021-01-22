#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main() {
	//입력
	/*첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. 
	(1 ≤ N ≤ 1, 000)
	둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다. 
	(1 ≤ Pi ≤ 10, 000)*/
	int N;
	cin >> N;
	vector<int> list_P;
	list_P.push_back(0);
	for (int i = 0; i < N; i++) {
		int input_P;
		cin >> input_P;
		list_P.push_back(input_P);
	}
	int dp[1001];
	for (int i = 0; i < 1001; i++) {
		dp[i] = 0;
	}
	dp[1] = list_P[1];
	for (int i = 2; i <= N; i++) {
		int point = ceil(i/2);
		int maxValue = list_P[i];
		for (int j = point; j >= 1; j--) {
			if (maxValue < dp[j] + dp[i - j]) {
				maxValue = dp[j] + dp[i - j];
			}
		}
		dp[i] = maxValue;
	}
	cout << dp[N] << '\n';
	//출력
	//첫째 줄에 민규가 카드 N개를 갖기 위해 지불해야 하는 금액의 최댓값을 출력한다.
	return 0;
}