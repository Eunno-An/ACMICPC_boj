#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int T=0;
	int N=0, M=0;
	int prior = 0;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> M;
		vector<pair<int, int>> v;
		vector<pair<int, int>> printList;
		pair<int, int> p;
		for (int i = 0; i < N; i++) {
			cin >> p.first;
			p.second = i;
			v.push_back(p);
		}
		if (v.size() == 1) {
			cout << 1 << '\n';
			continue;
		}
		/*cout << "vector v first: ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << ' ';
		}cout << '\n';
		cout << "vector v second: ";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].second << ' ';
		}cout << '\n';*/
		
		while (v.size() != 0) {
			int count = 0;
			pair<int, int> first = v[0];
			for (int i = 0; i < v.size(); i++) {
				if (first.first < v[i].first) {
					v.push_back(first);
					v.erase(v.begin()+0);
					break;
				}
				count++;
			}
			if (count == v.size()) {
				printList.push_back(v.front());
				v.erase(v.begin()+0);
			}
		}
		/*for (int i = 0; i < printList.size(); i++) {
			cout << "prior:" << printList[i].first << ' ';
		}cout << '\n';
		for (int i = 0; i < printList.size(); i++) {
			cout << "position: " << printList[i].second << ' ';
		}cout << '\n';*/
		for (int i = 0; i < printList.size(); i++) {
			if (printList[i].second == M) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}