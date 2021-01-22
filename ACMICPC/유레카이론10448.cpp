#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, K=1001;
int tripleCount = 0;
vector<int> set;

void calculate_triple(vector<int>& triples) {
	triples.push_back(1);
	int temp = 0;
	for (int i = 1; i < 46; i++) {
		temp = triples[i - 1];
		triples.push_back(temp + (i + 1));
	}
}
bool calculateSum(vector<int>& triples, int input) {
	for (int i = 0; i < triples.size(); i++) {
		for (int j = 0; j < triples.size(); j++) {
			for (int k = 0; k < triples.size(); k++) {
				if (triples[i] + triples[j] + triples[k] == input) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	vector<int> inputs;
	vector<int> triples;
	vector<bool> visit(46);
	
	calculate_triple(triples);
	int T;
	cin >> T;

	
	int input;
	for (int i = 0; i < T; i++) {
		cin >> input;
		bool flag = calculateSum(triples, input);
		if (flag) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	
	return 0;
}
