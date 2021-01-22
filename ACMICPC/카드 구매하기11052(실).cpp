#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main() {
	//�Է�
	/*ù° �ٿ� �α԰� �����Ϸ��� �ϴ� ī���� ���� N�� �־�����. 
	(1 �� N �� 1, 000)
	��° �ٿ��� Pi�� P1���� PN���� ������� �־�����. 
	(1 �� Pi �� 10, 000)*/
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
	//���
	//ù° �ٿ� �α԰� ī�� N���� ���� ���� �����ؾ� �ϴ� �ݾ��� �ִ��� ����Ѵ�.
	return 0;
}