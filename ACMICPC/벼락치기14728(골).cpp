#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int main() {
	//입력
	//첫째 줄에는 이번 시험의 단원 개수 N(1 ≤ N ≤ 100)과 시험까지 공부 할 수 있는 
	//총 시간 T(1 ≤ T ≤ 10000)가 공백을 사이에 두고 주어진다.
	//둘째 줄부터 N 줄에 걸쳐서 
	//각 단원 별 예상 공부 시간 K(1 ≤ K ≤ 1000)와 그 단원 문제의 배점 S(1 ≤ S ≤ 1000)가 공백을 사이에 두고 주어진다.
	
	int N, T;
	cin >> N >> T;
	vector<int> vector_studyTime;
	vector<int> vector_Score;
	vector_studyTime.push_back(-1);
	vector_Score.push_back(-1);
	for (int i = 0; i < N; i++) {
		int input_studyTime, input_Score;
		cin >> input_studyTime >> input_Score;
		vector_studyTime.push_back(input_studyTime);
		vector_Score.push_back(input_Score);
	}

	//출력
	//첫째 줄에 준석이가 얻을 수 있는 최대 점수를 출력한다.
	return 0;
}