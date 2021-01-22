#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string input = "";
	getline(cin, input); // <string>�� getline. c��� ���ڿ��� ���� ���� cin.getline�̿�(���� �迭�� �Ķ���ͷ� ����)

	while (input != ".") {
		stack <char> par;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(' || input[i] == ')' || input[i] == '[' || input[i] == ']') {
				if (par.size() != 0) {
					char temp = par.top();
					if (temp == '(' && input[i] == ')') {
						par.pop();
					}
					else if (temp == '[' && input[i] == ']') {
						par.pop();
					}
					else {
						par.push(input[i]);
					}
				}
				else {
					par.push(input[i]);
				}
				
			}
			
		}
		if (par.size() == 0) {
			cout << "yes";
		}
		else {
			cout << "no";
		}
		cout << '\n';
		cin.clear();
		cout.clear();
		getline(cin, input); // <string>�� getline. c��� ���ڿ��� ���� ���� cin.getline�̿�(���� �迭�� �Ķ���ͷ� ����)

	}
	return 0;
}