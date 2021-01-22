#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	string answer;
	cin >> answer;
	char s[3] = {'A', 'B', 'C'};
	char c[4] = { 'B', 'A', 'B', 'C' };
	char h[6] = { 'C','C', 'A', 'A', 'B', 'B' };
	int sCount = 0, cCount = 0, hCount = 0;
	int sIndex = 0, cIndex = 0, hIndex = 0;
	for (int i = 0; i < answer.size(); i++) {
		if (answer[i] == s[sIndex]) {
			sCount++;
		}
		if (answer[i] == c[cIndex]) {
			cCount++;
		}
		if(answer[i] == h[hIndex]){
			hCount++;
		}
		sIndex++;
		cIndex++;
		hIndex++;
		if (sIndex % 3 == 0) {
			sIndex -= 3;
		}
		if (cIndex % 4 == 0) {
			cIndex -= 4;
		}
		if (hIndex % 6 == 0) {
			hIndex -= 6;
		}
	}
	vector<int> scores;
	scores.push_back(sCount);
	scores.push_back(cCount);
	scores.push_back(hCount);
	vector<string> names;
	names.push_back("Adrian");
	names.push_back("Bruno");
	names.push_back("Goran");
	int max = -1;
	for (int i = 0; i < scores.size(); i++) {
		if (max < scores[i]) {
			max = scores[i];
		}
	}
	cout << max << '\n';
	for (int i = 0; i < scores.size(); i++) {
		if (max == scores[i]) {
			cout << names[i] << '\n';
		}
	}
	return 0;
}