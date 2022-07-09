#include <bits/stdc++.h>
using namespace std;

int T;
array<unsigned long long, 101> arr;

unsigned long long operating(int N) {
	if(arr[N]) { return arr[N]; }

	arr[N] = operating(N-5) + operating(N-1);
	return arr[N];
}

void read() {
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	cin >> T;
	while(T) {
		int N;
		cin >> N;

		cout << operating(N) << "\n";
		T--;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	return 0;
}
