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
	//현재 날 = N - remain
	//종료 조건
	//일할 수 있는 남은 날 < 현재에서 일해야 하는 날
	if (remain <= T[index]) {
		if (remain == T[index]) {
			benefit += P[index];
		}
		if (maxBenefit < benefit) {
			maxBenefit = benefit;
		}
		return;
	}
	//index에 일을 함.
	benefit += P[index];
	remain -= T[index];
	index += T[index];
	int count = 0;
	for (int i = index; i < N; i++) {	
		calculate_Max_Benefit(T, P, i, remain-count, benefit);
		count++;
	}
}