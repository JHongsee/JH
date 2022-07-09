#include <bits/stdc++.h>
using namespace std;

int N;
array<int, 1000001> tiles;

int get_tile(int N) {
	if (tiles.at(N)) return tiles.at(N);

	tiles.at(N) = get_tile(N-1) + get_tile(N-2);
	if (tiles.at(N) > 15746) {
		int q = tiles.at(N) / 15746;
		tiles.at(N) -= q * 15746;
	}
	return tiles.at(N);
}

void read() {
	cin >> N;

	tiles.at(1) = 1;
	tiles.at(2) = 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	read();
	cout << get_tile(N) % 15746;
	return 0;
}
