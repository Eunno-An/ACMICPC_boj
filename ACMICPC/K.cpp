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

int N;
int A, B, C;
int X, Y;
int M;
int arr[51][51];
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}
bool ok(int xPos, int yPos) {
	if (xPos >= N || xPos < 0 || yPos >= N || yPos < 0) {
		return false;
	}
	return true;
}
void move_like_Knight(int xPos, int yPos) {
		
}
void move_like_VS(int xPos, int yPos) {

}
void move_like_RK(int xPos, int yPos) {

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	cin >> A >> B >> C;
	cin >> X >> Y;
	cin >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
	}


	return 0;
}