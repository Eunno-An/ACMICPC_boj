#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//���� ����
//���̵��� ���� ������ ��������. direction �迭�� ����, ��Ģ�� ���ؼ� swap����.
//�������� ���̵��� �������� �� �� ����
//���� ���
//���� § �ڵ�: �̷��� ���̵��� �������� �����ϰ�, ���� p���� id�� �������� ������� ������. 
//���⼭ ������ �߻��Ǵµ�
//7 15 1
//1 7
//3 - 4
//6 - 5
//8 3
//10 - 1
//11 - 2
//13 - 6
//�� ���ÿ��� �ùٸ� ������ ������� ���Ѵ�.

//���� �������� ���� ���� ���̵��� ������ �ٲ��, �׸�ŭ �Ÿ��� �ٲ�µ�, ������ �Ÿ��� ����ؼ� ������ ���̴�.

//�ùٸ� ����, ������ �Ÿ��� ����ؼ� �����ϰ�, �׶��׶� ���� id�� ����, 
//���� id�� �����̸� �������� ������ ���̰�, ����̸� ���������� ������ ���̴�.


bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
void print_Directions(vector<int>& directions) {
	for (int i = 0; i < directions.size(); i++) {
		cout << directions[i] << ' ';
	}
	cout << '\n';
};
void print_Ants(vector<pair<int, int>>& ants) {
	cout << "ants[i].first is: ";
	for (int i = 0; i < ants.size(); i++) {
		cout << ants[i].first << ' ';
	}
	cout << "\nants[i].second is : ";
	for (int i = 0; i < ants.size(); i++) {
		cout << ants[i].second << ' ';
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//�Է��� ��������, ����� �������� �����϶�
	//�Է�: ������ ID�� ���� ���� ��ġ
	//1. ID: ���̸��� �ٸ���, ID�� ��ȣ�� �ٶ󺸴� �����̴�.
	//2. �� ���̰� �� ������ �浹�ϴ� ���, �� ���̴� �����ϴ� ������ �ݴ�� �ٲٰ�, ������ ����Ѵ�.
	int T; // testcase
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, L, k; //N: ������ ������, L: ������ ����, k: ���°�� �������� ����
		//(1 �� pi �� L - 1, 3 �� N �� 100,000, 10 �� L �� 5,000,000, 1 �� k �� N)
		cin >> N >> L >> k;
		vector<int> ids;
		vector<int> positions;
		vector<pair<int, int>> ants;
		for (int j = 0; j < N; j++) {
			int p, a;
			//-10^9 <= a <= 10^9
			cin >> p >> a;
			ids.push_back(a);
			positions.push_back(p); //p�� �׻� �����ϴ� ������ �־�����.
			pair<int, int> moving_ants;
			moving_ants.first = ids[j] < 0 ? positions[j] : L - positions[j];
			moving_ants.second = ids[j];
			ants.push_back(moving_ants);
		}
		sort(ants.begin(), ants.end()); // O(NlogN)
		//print_Ants(ants);
		vector<int> fallList;
		int start = 0;
		int end = ids.size() - 1;
		for (int j = 0; j < ants.size(); j++) {
			int front = ids[start], back = ids[end];
			if (j != ants.size() - 1 && ants[j].first == ants[j + 1].first) {
				if (front < back) {
					fallList.push_back(front);
					fallList.push_back(back);
				}
				else {
					fallList.push_back(back);
					fallList.push_back(front);
				}
				end--; start++; j++;
			}
			else if (ants[j].second < 0) {
				fallList.push_back(front);
				start++;
			}
			else {
				fallList.push_back(back);
				end--;
			}
		}
		cout << fallList[k - 1] << '\n';
	}
	//���: ���̰� �������� ����
	//���ÿ� ������ ���, ���� ���̰� ���� ��������.(ID�� ���� �ͺ���)
	return 0;
}
