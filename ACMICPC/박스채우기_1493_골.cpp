#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct var {
	int a;
	int b;
};
bool cmp(var t1, var t2) {
	if (t1.a > t2.a) return true;
	return false;
}
int l, w, h, n;
int result = 0;
var arr[20];
bool jud = true;
void solved(int ll, int ww, int hh) {
	if (jud == false) return;
	if (ll == 0 || ww == 0 || hh == 0) return;

	for (int i = 0; i < n; i++) {
		if (ll >= arr[i].a && ww >= arr[i].a && hh >= arr[i].a && arr[i].b > 0) {
			arr[i].b--;
			result++;
			solved(ll, ww, hh - arr[i].a);
			solved(arr[i].a, ww - arr[i].a, arr[i].a);
			solved(ll - arr[i].a, ww, arr[i].a);
			return;
		}
	}

	jud = false;
}

//하나씩 놓으면 됨.
//1.length * width가 정육면체 큐브와 딱 맞아 떨어지는 경우
   // -> 하나의 파티션(length, width, height - cube_length)
   //2.딱 맞아 떨어지지 않는 경우
   // -> 세개의 파티션
   //(length - cube_length, cube_width, height - cube_length), 
   //(length, width-cube_length, height - cube_height), 
   //(length, width, height - cube_length)로 나뉨
int main() {
	cin >> l >> w >> h;
	cin >> n;
	int temp1, temp2;
	for (int i = 0; i < n; i++) {
		cin >> temp1 >> arr[i].b;
		arr[i].a = pow(2, temp1);
	}
	sort(arr, arr + n, cmp); // 내림차순 정렬

	solved(l, w, h);

	if (jud == false)
		cout << -1 << endl;
	else
		cout << result << endl;
}