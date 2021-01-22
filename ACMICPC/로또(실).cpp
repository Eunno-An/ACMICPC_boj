#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
void print_Combi(vector<int>& lotto, vector<bool>& Combi, int index, int numOfChoice) {
	if (numOfChoice == 6) {
		int count = 0;
		for (int i = 0; i < lotto.size(); i++) {
			if (count == 6) {
				break;
			}
			if (Combi[i] == true) {
				count++;
				cout << lotto[i] << ' ';
			}
			
		}
		cout << '\n';
		return;
	}
	if (index == Combi.size()) {
		return;
	}
	Combi[index] = true;
	print_Combi(lotto, Combi, index + 1, numOfChoice + 1);
	Combi[index] = false;
	print_Combi(lotto, Combi, index + 1, numOfChoice);
	
}
int main() {
	int T;
	cin >> T;
	while (T != 0) {
		vector<int> lotto;
		vector<bool> Combi;
		int input;
		for (int i = 0; i < T; i++) {
			cin >> input;
			lotto.push_back(input);
			Combi.push_back(false);
		}
		print_Combi(lotto, Combi, 0, 0);
		cout << '\n';
		cin >> T;
	}
	return 0;
}