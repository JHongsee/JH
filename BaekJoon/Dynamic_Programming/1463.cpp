#include <bits/stdc++.h>
using namespace std;

int N;
array<int, 1000001> memo;

void read() {
	cin >> N;
}

int operating(int n) {
	if (n == 1) { return 0; }
	if (n == 2) { return 1; }
	if (n == 3) { return 1; }
	if (memo[n] != 0) { return memo[n]; }

	int a, b, c;
	a = operating(n-1) + 1;
	if (n % 3 == 0) { b = operating(n/3) + 1; }
	else			{ b = a; }
	if (n % 2 == 0) { c = operating(n/2) + 1; }
	else			{ c = a; }
	a = min(a, b);

	return memo[n] = min(a, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	cout << operating(N) << "\n";
	return 0;
}
