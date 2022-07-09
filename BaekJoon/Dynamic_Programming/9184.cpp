#include <bits/stdc++.h>
#define GET_abc memo[a][b][c]
using namespace std;

array< array< array< int, 21 >, 21 >, 21 > memo;

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}

	if (GET_abc)
		return GET_abc;

	if (a < b && b < c) {
		GET_abc = w(a, b  , c-1) +
				  w(a, b-1, c-1) -
				  w(a, b-1, c  );
	}
	else {
		GET_abc = w(a-1, b  , c  ) +
				  w(a-1, b-1, c  ) +
				  w(a-1, b  , c-1) -
				  w(a-1, b-1, c-1);
	}
	return GET_abc;
}

void read() {
	while(true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) return;

		cout << "w(" << a << ", " << b << ", " << c <<") = ";
		cout << w(a, b, c) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	return 0;
}
