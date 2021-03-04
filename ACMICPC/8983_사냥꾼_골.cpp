
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

int M, N, L;
vector<int> pos_x;
vector<pii> pos_animal;

// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

bool compare(pii& a, pii& b) {
	return a.second > b.second;
}
int main()
{
	//�̰͵� ��¥ ��������.
	//�������� �� �ϳ���, ������ �Ÿ��� ���ϸ鼭, 
	//�Ÿ������� �����ϸ� ����� �߰��ϰ�
	//�׷��� ������, ��� �߿��� �̺�Ž���� �Ͽ� �´� ��븦 ã�°�.

	//�߿��� ��: ������ ã�ƾ� �ϴ°�?
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();

	cin >> M >> N >> L;
	int input_x;
	for (int i = 0; i < M; i++) {
		cin >> input_x;
		pos_x.push_back(input_x);
	}

	pii input;
	for (int i = 0; i < N; i++) {
		cin >> input.first >> input.second;
		if (input.second > L) {
			// �����Ÿ��� �����Ÿ� L �ʰ��� ���,
			// ���� ���� �� ����.
			continue;
		}
		pos_animal.push_back(input);
	}

	//����� ��ġ pos_x[i]�� ������ ��ġ pos_animal[i] ���� �Ÿ���
	//abs(pos_x[i] - pos_animal[i].first) + pos_animal[i].second

	//O(MN) -> time limit
	
	sort(pos_x.begin(), pos_x.end());
	int result = 0;
	for (int i = 0; i < pos_animal.size(); i++) {
		int l = 0, r = pos_x.size() - 1;
		int mid;
		while (l <= r) {
			mid = l + (r - l) / 2;
			int cal = abs(pos_x[mid] - pos_animal[i].first) + pos_animal[i].second;
			if (cal <= L) {
				result++;
				break;
			}
			else {
				if (pos_animal[i].first >= pos_x[mid])
					l = mid + 1;
				else r = mid - 1;
			}
		}
	}
	cout << result << '\n';

	/*
	1 4
	8 4
	9 4
	3 3
	7 2
	2 2
	5 1
	*/
	return 0;
}