#include <bits/stdc++.h>
using namespace std;

void SetBox(int arr[2], int a, int b) {
	arr[0] = a > b ? a : b;
	arr[1] = a > b ? b : a;
}

int main() {
	int a[2], b[2], c[2];
	int w, h, temp;

	cin >> w >> h;
	SetBox(a, w, h);
	cin >> w >> h;
	SetBox(b, w, h);
	cin >> w >> h;
	SetBox(c, w, h);

	int ah[3] = {a[0], b[0], c[0]};
	int aw[3] = {a[1], b[1], c[1]};

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2 - i; j++) {
			if(ah[j] < ah[j+1]) {
				temp     = ah[j];
				ah[j]    = ah[j+1];
				ah[j+1]  = temp;
				temp     = aw[j];
				aw[j]    = aw[j+1];
				aw[j+1]  = temp;
			}
			else if(ah[j] == ah[j+1] && aw[j] < aw[j+1]) {
				temp    = aw[j];
				aw[j]   = aw[j+1];
				aw[j+1] = temp;
			}
		}
	}
	int Min;
	int maxh;
	int maxw;

	maxh = ah[0];
	maxw = aw[0]+aw[1]+aw[2];
	Min  = maxh*maxh + maxw*maxw;

	maxh = max(ah[0], ah[1]+ah[2]);
	maxw = max(aw[0]+aw[1], aw[0]+aw[2]);
	Min  = min(Min, maxh*maxh + maxw*maxw);

	maxh = max(ah[0], ah[1]+aw[2]);
	maxw = max(aw[0]+aw[1], aw[0]+ah[2]);
	Min  = min(Min, maxh*maxh + maxw*maxw);

	maxh = max(ah[0], aw[1]+ah[2]);
	maxw = max(aw[0]+ah[1], aw[0]+aw[2]);
	Min  = min(Min, maxh*maxh + maxw*maxw);

	maxh = max(ah[0], aw[1]+aw[2]);
	maxw = max(aw[0]+ah[1], aw[0]+ah[2]);
	Min  = min(Min, maxh*maxh + maxw*maxw);

	maxh = ah[0]+aw[2];
	maxw = max(aw[0]+aw[1], ah[2]);
	Min  = min(Min, maxh*maxh + maxw*maxw);

	maxh = ah[0]+aw[1];
	maxw = max(aw[0]+aw[2], ah[1]);
	Min  = min(Min, maxh*maxh + maxw*maxw);

	cout << Min << endl;

	return 0;
}
