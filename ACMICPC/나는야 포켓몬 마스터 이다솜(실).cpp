#include<iostream>
#include<string>
#include<map>

using namespace std;
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M; // 1 <= N, M <= 100,000
	string name_pocketmon;
	string question;
	cin >> N >> M;

	map<string, int> names;
	map<int, string> numbers;
	for (int i = 0; i < N; i++) {
		cin >> name_pocketmon;
		names[name_pocketmon] = i + 1;
		numbers[i + 1] = name_pocketmon;
	}
	for (int i = 0; i < M; i++) {
		cin >> question;
		if (names.count(question)) {
			cout << names.find(question)->second << '\n';
			continue;
		}
		else {
			int integer_question = stoi(question);
			cout << numbers.find(integer_question)->second << '\n';
		}
	}
	return 0;
}