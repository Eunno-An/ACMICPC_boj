
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include<iomanip>

using namespace std;

/*
- endl ��� '\n' ����ϱ�
- cin.tie(0) ���
- �׽�Ʈ ���̽� �ִ� ������ �� �������� �ʱ�ȭ �Ű澲��
- (A + B + C) % D = ((A + B) % D + C) % D
- ���ڿ� ��� ������ ���� ���ڿ� �����ؼ� �ڵ忡 �ֱ�
- ��ȣ ��� �����ϱ�
- ���ڿ��� �Լ��� �ѱ� �� const & �� ����ϱ�

- �־��� ��� int �� �ʰ��ϴ���, �迭 �ε��� �ʰ��ϴ��� Ȯ��
- n ���� Ȯ�� (0�� ���), ������� �����Ҽ� Ȯ��, �Ұ����̽� -1 ��� �� Ȯ��
- ū �迭 ���� �� ��������, ���� ���� �� �ʱ�ȭ, �迭 �뷮 max N + 5
*/

#define MOD 1000000007
#define INT_MAX 987654321
#define MAX 100005

typedef long long int ll;
typedef pair<int, int> pii;
int N, K;

// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	

	init();
	cin >> N >> K;
	int input;
	stack<int> s;
	for (int i = 0; i < N; i++) {
		scanf("%1d", &input);
		if (s.empty()) {
			s.push(input);
		}
		else {
			while (!s.empty() && s.top() < input) {
				if (K == 0) {
					break;
				}
				s.pop();
				K--;
			}
			s.push(input);
			if (K == 0) {
				if (i != N) {
					continue;
				}
			}
		}
	}
	while (K--) {
		s.pop();
	}
	vector<int> temp;
	while (!s.empty()) {
		temp.push_back(s.top());
		s.pop();
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		cout << temp[i];
	}
	cout << '\n';



	return 0;
}