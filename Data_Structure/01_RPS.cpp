#include <iostream>
using namespace std;

int main() {
	char a, b, c[7]={'D', 'R', 'P', 'S'};
	cin >> a >> b;
	cout << c[a^b];
	return 0;
}
