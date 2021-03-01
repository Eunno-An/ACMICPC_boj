
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
vector<pii> conf;
// �׽�Ʈ ���̽� �ʱ�ȭ ��
void init()
{

}

int main()
{
	//��ǰ
	//�˰��� ��ü�� �������� ����.
	//��������� ���� ������ ��, �׸����ϰ� Ž���ϸ� �Ǵ� ������.
	//���� �ð��� ���� ������ ������ ����, �ٲ㼭 ���� �ð��� ���� ������
	//������ ���� �ʾҴ� ���� ���� ������.
	//�ȵɲ���� �����ص�, �ѹ� �� ����.
	//������ ������ ��ȯ�� �ʿ��� ����
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	cin >> N;
	int start_t, end_t;
	pii input;
	int max_t = -1;
	int min_t = 100000001;
	for (int i = 0; i < N; i++) {
		cin >> start_t >> end_t;
		input.first = end_t;
		input.second = start_t;
		conf.push_back(input);
		
	}
	//�� �������� "���� ����"�� ���� ����
	sort(conf.begin(), conf.end());
	
	int time = conf[0].first;
	int count = 1;
	for (int i = 1; i < N; i++) {
		if (time <= conf[i].second) {
			count++;
			time = conf[i].first;
		}
	}
	cout << count << '\n';


	return 0;
}