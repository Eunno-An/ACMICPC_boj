
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

int N, M, start, fin;
vector<pair<int, int>> v[100000];
bool visited[100000];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{
	
}
bool bfs(int mid) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int from = q.front();
		q.pop();
		if (from == fin) return true;
		for (int i = 0; i < v[from].size(); i++) {
			int next = v[from][i].first;
			int nextC = v[from][i].second;
			if (visited[next]) continue;
			if (mid <= nextC) {//���� Ʈ���� �߷�����, �߷������� �� Ŭ ���, �� �� ����
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}
//�������� BFS + Binary Search ����.


//�Ķ��Ʈ�� ��ġ��?
//����ȭ ������ ���� ������ �ٲ۵�, �̰��� �̺й��� �̿��� �ذ��ϴ� ���

//����ȭ ����: �ٸ��� ���� ������ �־����� ��, �߷��� �ִ��� ��ȯ
//���� ����: �ٸ��� ���� ������ �߷������� ���� �־����� ��,
//			 ������ �ִ� �� ���� �߷����� �� �̻����� ���� �� �ִ� ����� �ִ°�?
//			 ��, ��� �ٸ��� �߷������� ���� mid �̻��� ��ΰ� �ִ°�?

//���������� "�� x�� �����ϴ°�?"�� �ƴ϶�, "x�Ǵ� �׺��� ���� ���� �ִ°�?" ��� ������ ����ؾ� �Ѵ�.
//�̷��� �ؾ� ���� �ĺ��� �Ǵ� ������ ���������� �����ؼ�, ����ȭ ��������
//���� �����ϴ� ������ �������� �ٿ������� ���������δ� ���� �ִ� ��ġ�� ���� �� �ֱ� �����̴�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N >> M;
	int A, B, C;
	int left = 0, right = 0;
	for (int i = 0; i < M; i++) {//A�� ���� B�� �� ���̿� �߷����� C�� �ٸ��� ����
		cin >> A >> B >> C;
		v[A].push_back(make_pair(B, C));
		v[B].push_back(make_pair(A, C));
		if (right < C) right = C;
	}
	cin >> start >> fin;

	int ans = 0;
	while (left <= right) {
		memset(visited, false, sizeof(visited));
		int mid = (left + right) / 2;
		if (bfs(mid)) {
			left = mid + 1;
			ans = mid;
		}
		else
			right = mid - 1;
	}
	//i1���� i2�� ���°�� �߿���
	//������ �ִ밪�� ���ϴ� ��

	cout << ans << '\n';

	//https://velog.io/@jua0610/%EB%B0%B1%EC%A4%80-1939-%EC%A4%91%EB%9F%89%EC%A0%9C%ED%95%9C-%ED%8C%8C%EB%9D%BC%EB%A9%94%ED%8A%B8%EB%A6%AD-%EC%84%9C%EC%B9%98
	return 0;
}