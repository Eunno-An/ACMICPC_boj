
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

long long int S;
vector<ll> vector_N;
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
	cin >> S;
	if (S <= 2) {
		cout << 1 << '\n';
		return 0;
	}
	//S = 200
	//S = 1 , N = 1 (1)
	//S = 2 , N = 1 (2)
	//S = 3 , N = 2 (1, 2), (3)
	//S = 4 , N = 2 (1, 3)
	//S = 5 , N = 2 (2, 3)
	//S = 6 , N = 3 (1, 2, 3)
	//S = 7 , N = 3 (1, 2, 4)
	//S = 10, N = 4 (1, 2, 3, 4)
	//1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210  
	ll N = 2;
	ll temp = 1;
	int count = 0;
	while (temp <= S) {
		temp += N;
		N += 1;
		count++;
	}
	cout << count << '\n';
	return 0;
}