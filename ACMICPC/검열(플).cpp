//kmp도 최악이라 안됨. 보이어 무어도 최악이라 안됨.
#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main() {
	deque<char> front;
	deque<char> back;
	string a, t;
	cin >> a >> t;
	int front_index, last_index; // 앞에서부터 시작하는 index와 뒤에서 부터 시작하는 index
	front_index = 0; last_index = t.size() - 1;
	while (front_index <= last_index) {
		while (front_index <= last_index) {
			bool b = false;
			front.push_back(t[front_index]);
			front_index++;
			if (front.size() >= a.size()) { // A의 크기만큼 문자가 덱에 있다면
				b = true;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] != front[front.size() - a.size() + i]) {
						b = false;
						break;
					}
				}
			}
			if (b) {//만약 A와 일치한다면 A의 크기만큼 덱에서 제거함.
				for (int i = 0; i < a.size(); i++)front.pop_back();
				break;
			}
		}
		while (front_index <= last_index) {
			back.push_front(t[last_index]);
			last_index--;
			bool b = false;
			if (back.size() >= a.size()) {
				b = true;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] != back[i]) {
						b = false;
						break;
					}
				}
			}
			if (b) {
				for (int i = 0; i < a.size(); i++) 
					back.pop_front();
				break;
				
			}
		}
	}
	string answer;
	for (int i = 0; i < front.size(); i++) answer.push_back(front[i]);
	for (int i = 0; i < back.size(); i++) answer.push_back(back[i]);
	while (answer.find(a) < 30000)
		answer.erase(answer.find(a), a.size());
	if (!answer.empty()) cout << answer << '\n';
	return 0;
}