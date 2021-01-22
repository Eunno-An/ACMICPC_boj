#include <iostream> 
using namespace std; 
const int MAX = 100 * 4 + 1; 
char starMap[MAX][MAX];
void func(int y, int x, int depth)
{ if (depth == 1) { starMap[y][x] = '*'; return; }
for (int i = 0; i < 4 * (depth - 1) + 1; i++)
{ if (i == 0 || i == 4 * (depth - 1))
{ for (int j = 0; j < 4 * (depth - 1) + 1; j++)
{ starMap[y + i][x + j] = '*'; } continue; }
starMap[y + i][x] = '*'; starMap[y + i][x + 4 * (depth - 1)] = '*'; }
func(y + 2, x + 2, depth - 1); return; } 
int main(void) { 
	int N; cin >> N; func(0, 0, N);
	for (int i = 0; i < 4 * (N - 1) + 1; i++)
	{ for (int j = 0; j < 4 * (N - 1) + 1; j++) 
	{ char c = starMap[i][j] == '*' ? '*' : ' '; cout << c; } 
	cout << "\n"; } 
	return 0; }
