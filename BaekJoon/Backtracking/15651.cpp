#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
vector<int> result;

void outcome() {
	for(auto i : result)
		cout << i << " ";
	cout << "\n";
}

void read() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		v.push_back(i);
	}
}

void operating(int cnt) {
	if(cnt == M) {
		outcome();
		return;
	}
	for(int i = 0; i < N; i++) {
		result.push_back(v[i]);
		operating(cnt+1);
		result.pop_back();
	}
}

int main() {
	read();
	operating(0);
	return 0;
}
