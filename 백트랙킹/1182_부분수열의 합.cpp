#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N, S;
vector<int> inputs;
int count_subset;
//대표적인 부분집합 구하기 문제
//S가 0일때, 아무것도 선택을 안한 경우도 들어갈 수 있음.
//그 예외처리만 해 주면 됨.
void comb(vector<bool> visit, int idx) {
	if (idx == N) {
		
		int sum = 0;
		for (int i = 0; i < N; i++) {
			//cout << visit[i] << ' ';
			if (visit[i]) {
				sum += inputs[i];
			}
		}
		//cout << '\n';
		if (sum == S) {
			count_subset++;
			//cout << "Above This!\n";
		}
		
		return;
	}
	visit[idx] = true;
	comb(visit, idx + 1);
	visit[idx] = false;
	comb(visit, idx + 1);
}
int main() {
	
	cin >> N >> S;

	
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		inputs.push_back(input);
	}

	sort(inputs.begin(), inputs.end());
	vector<bool> visit(N);
	for (int i = 0; i < N; i++) {
		visit[i] = false;
	}
	comb(visit, 0);
	if (S == 0) {
		count_subset--;
	}
	cout << count_subset << '\n';
	return 0;
}
