#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> ar;
vector<int> fi;

void read() {
	cin >> N;
	while(N) {
		int t;
		cin >> t;
		ar.push_back(t);
		N--;
	}

	cin >> M;
	while(M) {
		int t;
		cin >> t;
		fi.push_back(t);
		M--;
	}
}

int range(int s, int e, int f) {
	s = lower_bound(ar.begin() + s, ar.begin() + e, f) - ar.begin();
	e = upper_bound(ar.begin() + s, ar.begin() + e, f) - ar.begin();
	return e - s;
}

void outcome() {
	sort(ar.begin(), ar.end());
	for(auto i : fi) {
		cout << range(0, ar.size(), i) << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	outcome();
	return 0;
}
