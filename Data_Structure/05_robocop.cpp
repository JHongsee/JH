#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int main(void) {
	int K, x, y, i;
	cin >> K;

	vector<pair<int, int>> xy;
	for(i = 0; i < K; i++) {
		cin >> x >> y;
		xy.push_back(make_pair(x, y));
	}
	int T[5];
	for(i = 0; i < 5; i++) {
		cin >> T[i];
	}

	for(i = 0; i < 5; i++) {
		int j = 0;
		while(T[i] > 0) {
			if(j < K - 1) {
				T[i] -= abs((xy[j].F - xy[j+1].F) + (xy[j].S - xy[j+1].S));
				j++;
			}
			else {
				T[i] -= abs((xy[j].F - xy[0].F) + (xy[j].S - xy[0].S));
				j = 0;
			}
		}
		if(j != 0) {
			if(xy[j].F == xy[j-1].F) {
				x = xy[j].F;
				if(xy[j].S > xy[j-1].S) {
					y = xy[j].S + T[i];
				}
				else {
					y = xy[j].S - T[i];
				}
			}
			else {
				y = xy[j].S;
				if(xy[j].F > xy[j-1].F) {
					x = xy[j].F + T[i];
				}
				else {
					x = xy[j].F - T[i];
				}
			}
		}
		else {
			if(xy[j].F == xy[K - 1].F) {
				x = xy[j].F;
				if(xy[j].S > xy[K - 1].S) {
					y = xy[j].S + T[i];
				}
				else {
					y = xy[j].S - T[i];
				}
			}
			else {
				y = xy[j].S;
				if(xy[j].F > xy[K - 1].F) {
					x = xy[j].F + T[i];
				}
				else {
					x = xy[j].F - T[i];
				}
			}
		}
		cout << x << ' ' << y << endl;
	}


	return 0;
}
