#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string S;
//순열 구하기
//
int main() {
	cin >> S; //알파벳 소문자로만 이루어져 있다.
	//인접해 있는 모든 문자가 같지 않은 문자열 = 행운의 문자열
	int cnt = 0;
	sort(S.begin(), S.end());

	do {
		cout << S << '\n';
		bool flag = false;
		for (int i = 1; i < S.size(); i++) {
			if (S[i - 1] == S[i]) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			cnt++;
		}
	}while(next_permutation(S.begin(), S.end()));

	return 0;
}
