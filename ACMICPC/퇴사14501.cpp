#include<iostream>
#include<vector>
#include<string>
using namespace std;
void calculate_Max_Benefit(vector<int> &, vector<int> &, int index, int remain, int benefit);
int maxBenefit = 0;
int N;
int main() {
	
	cin >> N;
	vector<int> T(N);
	vector<int> P(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 0; i < N; i++) {
		calculate_Max_Benefit(T, P, i,  N-i, 0);
	}
	cout << maxBenefit << '\n';
}
void calculate_Max_Benefit(vector<int>& T, vector<int>& P, int index,  int remain, int benefit) {
	//���� �� = N - remain
	//���� ����
	//���� �� �ִ� ���� �� < ���翡�� ���ؾ� �ϴ� ��
	if (remain <= T[index]) {
		if (remain == T[index]) {
			benefit += P[index];
		}
		if (maxBenefit < benefit) {
			maxBenefit = benefit;
		}
		return;
	}
	//index�� ���� ��.
	benefit += P[index];
	remain -= T[index];
	index += T[index];
	int count = 0;
	for (int i = index; i < N; i++) {	
		calculate_Max_Benefit(T, P, i, remain-count, benefit);
		count++;
	}
}