//kmp�� �־��̶� �ȵ�. ���̾� ��� �־��̶� �ȵ�.
#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main() {
	deque<char> front;
	deque<char> back;
	string a, t;
	cin >> a >> t;
	int front_index, last_index; // �տ������� �����ϴ� index�� �ڿ��� ���� �����ϴ� index
	front_index = 0; last_index = t.size() - 1;
	while (front_index <= last_index) {
		while (front_index <= last_index) {
			bool b = false;
			front.push_back(t[front_index]);
			front_index++;
			if (front.size() >= a.size()) { // A�� ũ�⸸ŭ ���ڰ� ���� �ִٸ�
				b = true;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] != front[front.size() - a.size() + i]) {
						b = false;
						break;
					}
				}
			}
			if (b) {//���� A�� ��ġ�Ѵٸ� A�� ũ�⸸ŭ ������ ������.
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