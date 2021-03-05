
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
const int MAXN = 1000001;

typedef long long int ll;
typedef pair<int, int> pii;
int n;
ll A, B;
ll C;
vector<pair<int, ll>> candy_box_vec;
int tree[MAXN * 4];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
void update(int index, int target, int diff, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(index * 2, target, diff, start, mid);
	update(index * 2 + 1, target, diff, mid + 1, end);
}

int query(int index, int target, int start, int end) {
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	if (target <= tree[index * 2])
		return query(index * 2, target, start, mid);
	else // 1 2 3 4 5 ��� ������带 ���� ����Ʈ���� ���� ��, ��Ʈ����� �ڽ� ��尡 10, 5 ��� �����ϰ�, target�� 11�϶�
		//�츰 Ʈ���� ���ؼ� ������ �Ǵ��ϴ� ���̱� ������ target - tree[inde*2]�� �Ѱ��־�� �Ѵ�.
		return query(index * 2 + 1, target - tree[index * 2], mid + 1, end);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> n; //�������ڿ� ���� �� Ƚ��
	//�� ó���� �������ڿ��� �ƹ��͵� ���ٰ� ����.

	/*
	B��� ���� ������ ĵ�� "ã�Ƽ�" �ϳ� ������ ��
	1. �տ������� B��°�� �ִ� ĵ�� ã�´�? O(n^2) Ÿ�Ӹ���
	2. ��ü ������ ���� = candy_e
	   0���� ���� ��ü ���� ����(ex 100)
	   �տ��� 3��°�� �ִ� ������ ���� �����̳�?
	   50��° ������ ����?
	   25��° ������ ����?
	   12��° ������ ����?
	   6��° ������ ����?
	   3��° ������ ����?
	   1��° ������ ����?
	   2���� ������ ����?
	*/
	
	ll candy_s = 0, candy_e = 0; 
	for (int i = 0; i < n; i++) {
		cin >> A;
		if (A == 1) { //�������ڿ��� ������ ������ ���
			cin >> B; // ���� ������ ����
			//������ ���� ������ �̾ƾ� �ϴ� �ڷᱸ�� -> ����Ʈ�� �ʿ�
			int favor = query(1, B, 1, MAXN);
			cout << favor << '\n';
			update(1, favor, -1, 1, MAXN);

		}
		else if (A == 2) { //������ �ִ� ���
			cin >> B >> C; // B: �ְ� �� ������ ��, C: ������ ����
			update(1, B, C, 1, MAXN);
		}
	}
	

	return 0;
}