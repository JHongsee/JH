#include <bits/stdc++.h>
using namespace std;

int N, K, cnt;
vector<int> cost;

void read() {
	int t;
	cin >> N >> K;
	for(int i = 0; i < N; i++) {
		cin >> t;
		cost.push_back(t);
	}
}

void operating() {
	while(K) {
		if (cost[--N] > K) { continue; }
		cnt += K / cost[N];
		K %= cost[N];
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
