#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
vector<int> result;
vector<bool> visited;

void outcome() {
	for(auto i : result)
		cout << i << " ";
	cout << "\n";
}

void read() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		v.push_back(i);
		visited.push_back(false);
	}
}

void operating(int cnt) {
	if(cnt == M) {
		outcome();
		return;
	}
	for(int i = 0; i < N; i++) {
		if(visited[i]) continue;
		visited[i] = true;
		result.push_back(v[i]);
		operating(cnt+1);
		visited[i] = false;
		result.pop_back();
	}
}

int main() {
	read();
	operating(0);
	return 0;
}
