
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

int T;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> T;
	string L;
	
	for (int test_case = 0; test_case < T; test_case++) {
		stack<char> left;
		stack<char> right;
		cin >> L;
		for (int i = 0; i < L.size(); i++) {
			if (L[i] == '<') {
				if (left.empty()) {
					continue;
				}
				char x = left.top(); left.pop();
				right.push(x);
			}
			else if (L[i] == '>') {
				if (right.empty()) {
					continue;
				}
				char x = right.top(); right.pop();
				left.push(x);
			}
			else if (L[i] == '-') {
				if (left.empty()) {
					continue;
				}
				left.pop();
			}
			else {
				left.push(L[i]);
			}
		}

		vector<char> left_vec;
		while (!left.empty()) {
			left_vec.push_back(left.top());
			left.pop();
		}
		for (int i = left_vec.size() - 1; i >= 0; i--) {
			cout << left_vec[i];
		}
		while (!right.empty()) {
			cout << right.top();
			right.pop();
		}
		cout << '\n';
		
	}


	return 0;
}