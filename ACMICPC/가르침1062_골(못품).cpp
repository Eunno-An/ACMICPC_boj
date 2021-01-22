#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

int N, K, answer;
bool alphabet[26];
vector<string> word;

int canReadWord() {
	bool isRead;
	int count = 0;
	// 알고 있는 알파벳으로 알 수 있는 단어 개수 확인하기
	for (int i = 0; i < word.size(); i++) {
		isRead = true;
		string str = word[i];
		for (int j = 0; j < str.length(); j++) {
			if (alphabet[str[j] - 'a'] == false) {
				isRead = false;
				break;
			}
		}

		if (isRead == true) count++;
	}
	// 완전히 읽을 수 있는 단어 개수 반환
	return count;
}

void DFS(int idx, int cnt) {
	if (cnt == K) {
		int tempAns = canReadWord();
		answer = answer < tempAns ? tempAns : answer;
		return;
	}

	for (int i = idx; i < 26; i++) {
		// 이미 선택보장된 알파벳은 제외
		if (alphabet[i] == true) continue;

		alphabet[i] = true;
		DFS(i, cnt + 1);
		alphabet[i] = false;
	}
}


int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		word.push_back(str);
	}

	if (K < 5) {
		cout << 0 << endl;
		return 0;
	}

	// a, n, t, i, c 알파벳은 선택 보장
	alphabet['a' - 'a'] = true;
	alphabet['n' - 'a'] = true;
	alphabet['t' - 'a'] = true;
	alphabet['i' - 'a'] = true;
	alphabet['c' - 'a'] = true;
	K = K - 5;

	DFS(0, 0); // 조합
	cout << answer << endl;
}
