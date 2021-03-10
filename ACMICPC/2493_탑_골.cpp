#include <iostream>
#include <stack>
#include <utility>

using namespace std;

//��ǰ. ���ؿ� ���� �ø�. 7�ۼ�Ʈ���� Ʋ�ȴٰ� ��
int main() {

	int num;
	scanf("%d", &num);

	int count = 0;
	stack<pair<int, int>> s;
	pair<int, int> p;
	int input;

	while (count < num) {

		scanf("%d", &input);
		p = make_pair(count + 1, input);

		while (!s.empty()) {
			if (s.top().second > input) {
				printf("%d ", s.top().first);
				break;
			}
			s.pop();
		}

		if (s.empty()) printf("0 ");

		s.push(p);
		count++;
	}

	return 0;
}