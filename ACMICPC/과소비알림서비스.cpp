#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int T;
	int n, d;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> d;
		vector<int> inputs(n);
		
		for (int j = 0; j < n; j++) {
			cin >> inputs[i];
		}

		int numAlarms = 0;
		for (int j = d; j < n; j++) {
			vector<int> numbers(201);
			int right = j - 1;
			int left = j - d;
			for (int k = left; k <= right; k++) {
				numbers[inputs[k]]++;
			}
			if (d % 2 == 0) {//Â¦¼ö
				
			}
			else {//È¦¼ö

			}
		}
		cout << numAlarms << '\n';
	}
	return 0;
}