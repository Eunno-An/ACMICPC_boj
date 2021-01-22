#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	//백준에서는 ctrl+Z로 파일의 끝을 알려준다.(텍스트 파일로 입출력)
	//따라서 테스트 할 때도 ctrl + Z를 눌러서 파일의 끝을 알려주어야 한다.
	int alphabet[26] = {};
	string s;
	
	
	while (!cin.eof()){
		getline(cin, s);
		for (int i = 0; i < s.length(); i++) {
			if (isalpha(s[i])) {
				alphabet[int(s[i]) - 97]++;
			}
		}
	}
	int max = 0;
	vector<int> results;
	for (int i = 0; i < 26; i++) {
		if (max < alphabet[i]) {
			results.clear();
			max = alphabet[i];
			results.push_back(i);
		}
		else if (max == alphabet[i]) {
			results.push_back(i);
		}

	}
	sort(results.begin(), results.end());
	for (int i = 0; i < results.size(); i++) {
		cout << char(results[i]+97);
	}
	cout << '\n';
	return 0;
}