#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//사전순이라는 말이 명확하지가 않아서 이상한 문제임.
//2가 10보다 앞서나 안앞서나를 찾아봐야 할듯
//예시는 잘 나옴
int N;
vector<int> X;
vector<vector<int>> results;
int main() {
	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		X.push_back(input);
	}
	do {
		vector<int> temp;
		temp = X;
		
		for (int i = 0; i < N; i++) {
			temp.push_back(0);
		}
		/*for (int i = 0; i < temp.size(); i++) {
			cout << temp[i] << ' ';
		}
		cout << '\n';*/
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (i + temp[i] + 1 >= 2 * N) {
				// 범위를 벗어났을 때
				flag = true;
				break;
			}
			if (temp[i + temp[i] + 1] != 0) {
				flag = true;
				break;
			}
			temp[i + temp[i]+1] = temp[i];
		}
		if (!flag) {
			
			results.push_back(temp);
		}
	} while (next_permutation(X.begin(), X.end()));
	
	if (results.size() == 0) {
		cout << -1 << '\n';
	}
	else {
		sort(results.begin(), results.end());
		for (int i = 0; i < results[0].size(); i++) {
			cout << results[0][i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
