#include<iostream>
#include<string>
#include<set>
using namespace std;
//set으로 하면 시간초과
//그냥 map도 시간초과
//https://stackoverflow.com/questions/222658/multiset-map-and-hash-map-complexity

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); // 시간초과 나면 이거 꼭 써보자.. 이거 안써서 틀렸네..
	int T, N, M;
	cin >> T;
	while (T--) {
		set<int> note1;
		cin >> N;
		int input;
		for (int i = 0; i < N; i++) {
			cin >> input;
			note1.insert(input);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> input;
			if (note1.count(input)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
	}
	return 0;
}