#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string input = "";
	getline(cin, input); // <string>의 getline. c기반 문자열을 받을 때는 cin.getline이용(문자 배열만 파라미터로 가능)

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
		getline(cin, input); // <string>의 getline. c기반 문자열을 받을 때는 cin.getline이용(문자 배열만 파라미터로 가능)

	}
	return 0;
}