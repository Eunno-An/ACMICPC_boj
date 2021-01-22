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

using namespace std;

/*
���� ��ȸ ID
	579_013
	ZgdxHXStpraTGmCT

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

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'E') {
			s[i] = 'I';
		}
		else if (s[i] == 'I') {
			s[i] = 'E';
		}
		else if (s[i] == 'S') {
			s[i] = 'N';
		}
		else if (s[i] == 'N') {
			s[i] = 'S';
		}
		else if (s[i] == 'T') {
			s[i] = 'F';
		}
		else if (s[i] == 'F') {
			s[i] = 'T';
		}
		else if (s[i] == 'J') {
			s[i] = 'P';
		}
		else if (s[i] == 'P') {
			s[i] = 'J';
		}
	}
	cout << s << '\n';

	return 0;
}