#include<string>
#include<stack>
#include<iostream>
using namespace std;
int main() {
	while (true) {
		string s1, s2;
		cin >> s1 >> s2;
		stack<char> t1, t2;
	
		bool keep = false;
		int bomb_count = 0;
		int match_count = 0;
		while (!keep) {
			deque<char> result;
			match_count = 0, bomb_count = 0;
			for (int i = 0; i < s1.size(); i++) {
				t1.push(s1[i]);
				if (s1[i] == s2[0]) {
					for (int j = 0; j < s2.size() && i + j < s1.size(); j++) {
						if (s1[i + j] == s2[j]) {
							match_count += 1;
						}
						else {
							match_count = 0;
						}
					}
					if (match_count == s2.size()) {
						t1.pop();
						bomb_count += 1;
						i = i + s2.size() - 1;
					}
				}
			}
			if (bomb_count == 0) {
				keep = !keep;
				continue;
			}
			int size_t1 = t1.size();
			for (int i = 0; i < size_t1; i++) {
				result.push_front(t1.top());
				t1.pop();
			}
			s1 = "";
			int size_result = result.size();
			for (int i = 0; i < size_result; i++) {
				s1.push_back(result.front());
				result.pop_front();
			}
		}
		if (s1 == "") {
			cout << "FRULA" << '\n';
		}
		else {
			cout << s1 << '\n';
		}
	}

	

	return 0;
}