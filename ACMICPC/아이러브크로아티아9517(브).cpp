#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	//입력
	int K;//폭탄을 들고 있는 사람의 번호
	cin >> K;
	int N;//질문의 개수
	cin >> N;
	vector<int> T(N);//i번째 질문을 대답하기까지 걸린 시간
	vector<char> Z(N);//그 플레이어의 대답
	//(T = 대답이 맞음, N = 틀림, P = 스킵)
	for (int i = 0; i < N; i++) {
		cin >> T[i] >> Z[i];
	}
	
	//출력 알고리즘
	int remain = 210; // 3분 30초가 지나면 터짐
	int start = K; // 시작 번호. 사람은 1부터 시작하여 8까지 존재
	while (remain > 0) {
		for (int i = 0; i < N; i++) {
			remain -= T[i];
			if (remain <= 0) {
				break;
			}
			if (Z[i] == 'T') {
				if (start == 8) {
					start = 1;
					continue;
				}
				start++;
			}
		}
		
	}

	//출력
	cout << start << '\n';
	return 0;
}