#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	
	double d1(1234567891010);
	long long int ll1(1234567891010);
	cout << setprecision(15) << d1 << '\n' << ll1 << '\n';
}