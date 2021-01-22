
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
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
int cal_s_k(int k) {
	if (k == 0) {
		return 3;
	}

	return  2 * cal_s_k(k - 1) + k + 3;
}
//k>=1
//S(k) = S(k-1) + m o ... o(o�� k+2��) + S(k-1) = �� ���� 2*S(k-1) + k+3
//������ ���� �߿� K���� ���� ���������� ã�� ����. ����� 18222 ������ ���ڿ��� ����� ����
//�̸� ���ҷ��� �� ������ �����ϴ� ���迡 ���� ���� ��ȭ������ �ؾ���

//��ȭ�� ��ü�� ��͸� ���ø��� �ȴ�.
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (1) {


		init();
		cin >> N;
		string s = "moo";
		ll count = 4;
		ll size = 3;
		while (1) {
			if (size >= N) {
				break;
			}
			size = 2 * size + count;
			count++;
		}
		count -= 1;
		ll before_str;

		before_str = (size - count) / 2;
		if (before_str < N && N <= before_str + count) {
			N -= before_str;
			break;
		}
		else if (before_str >= N) {
			count--;
			size = before_str;
		}
		else {
			N -= (count + before_str);
			count--;
			size = before_str;
		}
	}

	if (N == 1) {
		cout << 'm' << '\n';
	}
	else {
		cout << 'o' << '\n';
	}

	return 0;
}