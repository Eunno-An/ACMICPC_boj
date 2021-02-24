
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
int n;
int A[4001], B[4001], C[4001], D[4001];
vector<int> AB;
vector<int> CD;
ll ans;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
/*
CD���Ͱ� ������������ ���ĵǾ� �����Ƿ�
CD[i]�� -AB[j]�� ���� ���� �̺�Ž������ ã���� �ȴ�.
�ٵ� ���� ���� �������� ���� ������
�� �� �ε����� ��ȯ�ϴ� �Ͱ�
�� �� �ε����� ��ȯ�ϴ� �Լ��� ������ �ش�.
*/
ll getS(ll value) {
	int start, end;
	//���� ã�� -AB[i]�� ���� cd ������ �� ���� ������ ū ���
	//start�� 0�� �ε���
	if (CD[0] < value) start = 0;
	//cd������ �� ���� ������ ������ Ž���� �ʿ䰡 ����
	else if (CD[0] > value) return -1;
	//���� ��� 0�� �ε��� ��ȯ
	else return 0;

	//���� ã���� �ϴ� ���� cd������ �� �ں��� ū ���
	//ã�� �ʿ� ����
	if (CD[CD.size() - 1] < value)return -1;
	else end = CD.size() - 1;
	//1 3 4 5 7
	//5�� ã�� ���� ��
	//start = 0, end = 4
	//mid = 2
	//start = 2, end = 4
	//mid = 3
	//end = 3
	//mid = 2
	while (1) {
		int mid = (start + end) / 2;
		//start ������ end�� ��ġ�ϰ� �Ǹ�
		//end�� ���ɼ��� ����.
		if (start + 1 == end) {
			if (CD[end] == value)return end;
			else return -1;
		}

		if (CD[mid] >= value) end = mid;
		else start = mid;
	}

}
ll getE(ll value) {
	int start, end;
	if (CD[0] <= value) start = 0;
	else return -1;

	if (CD[CD.size() - 1] < value)return -1;
	else if (CD[CD.size() - 1] > value)end = CD.size() - 1;
	else return CD.size() - 1;

	while (1) {
		int mid = (start + end) / 2;
		if (start + 1 == end) {
			if (CD[start] == value) return start;
			else return -1;
		}
		if (CD[mid] > value) end = mid;
		else start = mid;
	}
}
ll solve() {
	for (int i = 0; i < AB.size(); i++) {
		ll src = getS(-AB[i]), dst = getE(-AB[i]);
		if (src == -1 || dst == -1) continue;
		ans += dst - src + 1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> n;
	ll input1, input2, input3, input4;
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}
	sort(CD.begin(), CD.end());
	cout << solve() << '\n';
	return 0;
}