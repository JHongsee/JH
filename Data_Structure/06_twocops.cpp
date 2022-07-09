#include <bits/stdc++.h>
using namespace std;

struct XY {
	int x;
	int y;
};

vector<XY> v;
int N, T, i1, i2, d1, d2;
XY c1, c2, FM1, FM2, SM1, SM2;

int SetI(int i) {
	if (i < 0) return i += N;
	else if (i >= N) return i -= N;
	else return i;
}

void Read() {
	int i;
	cin >> N;
	for (i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		XY co;
		co.x = x;
		co.y = y;
		v.push_back(co);
	}
	cin >> T;
	c1.x = v[0].x;
	c1.y = v[0].y;
	c2.x = v[N / 2 - 1].x;
	c2.y = v[N / 2 - 1].y;
	i1 = 1;
	i2 = N / 2 - 2;
	for (i = 0; i < N / 2 - 1; i++) {
		d1 += (abs(v[i].x - v[i + 1].x) + abs(v[i].y - v[i + 1].y));
	}
	for (i = 0; i < N - 1; i++) {
		d2 += (abs(v[i].x - v[i + 1].x) + abs(v[i].y - v[i + 1].y));
	}
	d2 += (abs(v[0].x - v[N - 1].x) + abs(v[0].y - v[N - 1].y));
}

int clk(XY& c, int i, int t) {
	while (t) {
		if (t >= (abs(c.x - v[i].x) + abs(c.y - v[i].y))) {
			t -= (abs(c.x - v[i].x) + abs(c.y - v[i].y));
			c.x = v[i].x;
			c.y = v[i].y;
		}
		else {
			if (abs(c.x - v[i].x) > abs(c.y - v[i].y)) {
				if (c.x > v[i].x) c.x -= t;
				else c.x += t;
			}
			else {
				if (c.y > v[i].y) c.y -= t;
				else c.y += t;
			}
			t = 0;
		}
		i++;
		i = SetI(i);
	}
	i -= 2;
	return SetI(i);
}

int cclk(XY& c, int i, int t) {
	while (t) {
		if (t >= (abs(c.x - v[i].x) + abs(c.y - v[i].y))) {
			t -= (abs(c.x - v[i].x) + abs(c.y - v[i].y));
			c.x = v[i].x;
			c.y = v[i].y;
		}
		else {
			if (abs(c.x - v[i].x) > abs(c.y - v[i].y)) {
				if (c.x > v[i].x) c.x -= t;
				else c.x += t;
			}
			else {
				if (c.y > v[i].y) c.y -= t;
				else c.y += t;
			}
			t = 0;
		}
		i--;
		i = SetI(i);
	}
	i += 2;
	return SetI(i);
}

int main() {
	Read();
	int t1 = T, t2 = T;
	if (T <= d1 / 2) {
		i1 = clk(c1, i1, t1);
		i2 = cclk(c2, i2, t2);
	}
	else {
		i1 = clk(c1, i1, d1 / 2);
		i2 = cclk(c2, i2, d1 / 2);
		if (d1 % 2 == 0) T -= d1 / 2;
		else T -= (d1 / 2 + 1);
		while (T) {
			t1 = T;
			t2 = T;
			if (T >= d2) {
				T -= d2;
			}
			else if (T >= d2 / 2) {
				if (d1 % 2 == 0) {
					i1 = cclk(c1, i1, d2 / 2);
					i2 = clk(c2, i2, d2 / 2);
				}
				else {
					i1 = cclk(c1, i1, (d2 - 1) / 2);
					i2 = clk(c2, i2, (d2 - 1) / 2);
				}
				T -= d2 / 2;
				i1 = clk(c1, i1, T);
				i2 = cclk(c2, i2, T);
				T = 0;
			}
			else {
				i1 = cclk(c1, i1, t1);
				i2 = clk(c2, i2, t2);
				T = 0;
			}
		}
	}
	cout << c1.x << ' ' << c1.y << endl;
	cout << c2.x << ' ' << c2.y << endl;
	return 0;
}
