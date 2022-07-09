#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> in;
vector<int> memo;

void read() {
	int t;
	cin >> N;

	for(int i = 0; i < N; i++) {
		cin >> t;
		in.push_back(t);
		memo.push_back(-1001);
	}
	memo.push_back(-1001);
}

void operating() {
	int n, m;
	for(int i = 0; i < N; i++) {
		n = in[i];
		m = memo[i] + n;
		memo[i+1] = max(n, m);
	}
}

void outcome() {
	cout << *max_element(memo.begin(), memo.end()) << "\n";
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
