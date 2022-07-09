#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> step;
vector<vector<int>> memo;

void read() {
	int t;
	cin >> N;

	vector<int> v;
	memo.push_back(v);
	for(int i = 0; i < N; i++) {
		vector<int> v1, v2;
		v2.push_back(0);
		for(int j = 0; j < i+1; j++) {
			cin >> t;
			v1.push_back(t);
			v2.push_back(0);
		}
		step.push_back(v1);
		memo.push_back(v2);
	}
	memo[1][1] = step[0][0];
}

int operating(int n, int m) {
	if (n == 0 || m == 0) { return 0; }
	if (memo[n][m] != 0) { return memo[n][m]; }
	int a = -1, b = -1;
	for(int i = memo[n].size() - 1; i > 0; i--) {
		if (i != 0) { a = operating(n-1, i-1); }
		if (i != memo[n].size() - 1) { b = operating(n-1, i); }
		memo[n][i] = max(a, b) + step[n-1][i-1];
	}
	return memo[n][m];
}

void outcome() {
	cout << *max_element(memo[N].begin(), memo[N].end());
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	operating(N, N);
	outcome();
	return 0;
}
