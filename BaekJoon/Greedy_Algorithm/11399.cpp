#include <bits/stdc++.h>
using namespace std;

struct C {
	int b, e;
};

int N, cnt;
vector<C> inputs;

bool mycmp(C a, C b) {
	if (a.e == b.e) {
		return a.b < b.b ? true : false;
	}
	return a.e < b.e ? true : false;
}

void read() {
	int a, b;
	C c;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		c.b = a; c.e = b;
		inputs.push_back(c);
	}
	sort(inputs.begin(), inputs.end(), mycmp);
}

void operating() {
	int e = -1;
	for(auto c : inputs) {
		if (c.b < e) { continue; }
		e = c.e;
		cnt++;
	}
}

void outcome() {
	cout << cnt << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	operating();
	outcome();
	return 0;
}
