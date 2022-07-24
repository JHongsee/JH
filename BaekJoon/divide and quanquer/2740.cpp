#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<vector<int>> A, B, result;

void read() {
	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		vector<int> t;
		for(int j = 0; j < M; j++) {
			int n;
			cin >> n;
			t.push_back(n);
		}
		A.push_back(t);
	}

	cin >> M >> K;

	for(int i = 0; i < M; i++) {
		vector<int> t;
		for(int j = 0; j < K; j++) {
			int n;
			cin >> n;
			t.push_back(n);
		}
		B.push_back(t);
	}

	for(int i = 0; i < N; i++) {
		vector<int> t;
		for(int j = 0; j < K; j++) {
			t.push_back(0);
		}
		result.push_back(t);
	}
}

void operating() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			for(int k = 0; k < K; k++) {
				result.at(i).at(k) += A.at(i).at(j) * B.at(j).at(k);
			}
		}
	}
}

void outcome() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < K; j++) {
			cout << result.at(i).at(j) << " ";
		}
		cout << "\n";
	}
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
