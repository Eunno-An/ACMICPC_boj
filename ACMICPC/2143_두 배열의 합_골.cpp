
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
/*
	�Ķ��Ʈ�� ��ġ��?
	����ȭ ������ ���� ������ �ٲ۵�, �̰��� �̺й��� �̿��� �ذ��ϴ� ���

	����ȭ ����: �ٸ��� ���� ������ �־����� ��, �߷��� �ִ��� ��ȯ
	���� ����: �ٸ��� ���� ������ �߷������� ���� �־����� ��,
			 ������ �ִ� �� ���� �߷����� �� �̻����� ���� �� �ִ� ����� �ִ°�?
			 ��, ��� �ٸ��� �߷������� ���� mid �̻��� ��ΰ� �ִ°�?
	*/

typedef long long int ll;
typedef pair<int, int> pii;
int T;
int n, m;
int arr[1001];
vector<int> arr_sub;
int arr2[1001];
vector<int> arr2_sub;
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	/*
	1 4 5 7
	3 
	4 1
	6 3 2 -> 1, 2, 3, 4, 5, 6, 7

	1 4 6
	3
	5 2 -> 1 2 3 4 5 6
	
	��������

	*/
	//�迭�� �κ������� �� ���ϱ�
	for (int i = 0; i < n; i++) {
		int sum = arr[i];
		arr_sub.push_back(arr[i]);
		for (int j = i+1; j < n; j++) {
			sum += arr[j];
			arr_sub.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		int sum = arr2[i];
		arr2_sub.push_back(sum);
		for (int j = i+1; j < m; j++) {
			sum += arr2[j];
			arr2_sub.push_back(sum);
		}
	}
	sort(arr_sub.begin(), arr_sub.end());
	sort(arr2_sub.begin(), arr2_sub.end());
	//���� �ߺ����� �ϸ� �ȵȴ�!
	//������Ʈ���� �ڲ� ������..

	int p1 = 0;
	int p2 = arr2_sub.size() - 1;
	ll cnt = 0;
	while (1) {
		if (arr_sub[p1] + arr2_sub[p2] == T) {
			ll cnt1 = 1;
			ll cnt2 = 1;
			while (p1 + 1 <= arr_sub.size() - 1 && arr_sub[p1] == arr_sub[p1 + 1]) {
				p1++;
				cnt1++;
			}
			while (p2 - 1 >= 0 && arr2_sub[p2] == arr2_sub[p2 - 1]) {
				p2--;
				cnt2++;
			}
			cnt += cnt1 * cnt2;
			p1++;
		}
		if (p1 <= arr_sub.size() - 1 && p2 >= 0 && arr_sub[p1] + arr2_sub[p2] < T) {
			p1++;
		}
		if (p1 <= arr_sub.size() - 1 && p2 >= 0 && arr_sub[p1] + arr2_sub[p2] > T)
			p2--;
		if (p1 > arr_sub.size() - 1 || p2 < 0)
			break;
	}
	cout << cnt << '\n';


	return 0;
}