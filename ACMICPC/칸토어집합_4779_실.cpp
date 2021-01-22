
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

int N;
string s;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void make_cantor(int start, int end, string _s) {
	if (_s.size() == 1) {
		return;
	}
	for (int i = start; i < end; i++) {
 		if (i >= start + (end-start + 1) / 3 && i < start + (end - start + 1) / 3 * 2) {
			s[i] = ' ';
		}
	}
	string left="", right="";
	for (int i = 0; i < _s.size(); i++) {
		if (i < _s.size() / 3) {
			left.push_back('-');
		}
		if (i >= _s.size() / 3 * 2) {
			right.push_back('-');
		}
	}
	make_cantor(start, start + (end - start + 1) / 3, left);
	make_cantor(start + (end - start + 1) / 3 * 2, end, right);

}
void init()
{
	s = "";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		init();
		cin >> N;
		if (cin.eof()) {
			break;
		}
		int length = (int)pow(3, N);
		for (int i = 0; i < length; i++) {
			s.push_back('-');
		}
		make_cantor(0, s.size(), s);
		cout << s << '\n';
	}


	return 0;
}