#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main() {
	int N;
	cin >> N;
	int x, v, h, i, j, k;
	vector<int> sl;
	cin >> x >> v >> h;
	sl.pb(x);
	sl.pb(v);
	sl.pb(h);
	sl.pb(-v);
	sl.pb(0);
	sl.pb(0);
	for(i = 0; i < N - 1; i++) {
		cin >> x >> v >> h;
		int slx = 0;
		int sly = 0;
		for(j = 0; j < sl.size(); j+=2) {
			int sle = 0;
			for(k = 0; k < sl.size(); k+=2)
				sle += sl[k];
			slx += sl[j];
			if(x < slx) {
				if(x + h < slx){
					sl[j] = slx - (x+h);
					sl.insert(sl.begin()+j, sly - v);
					sl.insert(sl.begin()+j, h);
					sl.insert(sl.begin()+j, v - sly);
					sl.insert(sl.begin()+j, slx - (h+sl[j+3]));
				}
				else if(x + h == slx){
					if(v > sly) {
						sl.erase(sl.begin()+j);
						if(v == sly + sl[j+1]) {
							sl.erase(sl.begin()+j);
							sl.front() += slx - x;
						}
						else{
							sl[j] += (sly - v);
							sl.insert(sl.begin()+j, h);
						}
						sl.insert(sl.begin()+j, v - sly);
						sl.insert(sl.begin()+j, slx - sl[j+1]);
					}
				}
				else {
					if(v > sly) {
						sl.erase(sl.begin()+j);
						if(v == sly + sl[j+1]) {
							sl.erase(sl.begin()+j);
							sl.front() += slx - x;
						}
						else{
							sl[j] += (sly - v);
							sl.insert(sl.begin()+j, h);
						}
						sl.insert(sl.begin()+j, v - sly);
						sl.insert(sl.begin()+j, slx - sl[j+1]);
						h -= sl[j+2];
						x = slx;
					}
					else if (v <= sly) {
						if(slx == sl[0]) {
							sl.erase(sl.begin());
							sl.erase(sl.begin());
							sl.front() += slx - x;
							sl.insert(sl.begin(), v);
							sl.insert(sl.begin(), x);
							h -= (slx - x);
							x = slx;
						}
						else if(sle == slx) {
							if(v < sly) {
								sl.pop_back();
								sl.pop_back();
								sl.back() += v;
								sl.pb(h - (sle - x));
								sl.pb(-v);
							}
							else {
								sl.pop_back();
								sl.pop_back();
								sl.pop_back();
								sl.back() += h - (sle-x);
								sl.pb(-v);
							}
						}
					}
				}
			}
			else if(x == slx) {
				if(slx != sle) {
					if(v <= sly + sl[j+1]) {
						if(h > sl[j+2]) {
							x += sl[j+2];
							h -= sl[j+2];
						}
					}
					else {
						if(h > sl[j+2]) {
							sl[j+1] = v - sly;
						}
						x += sl[j+2];
						h -= sl[j+2];
					}
				}
				else {
					sl.erase(sl.end()-1);
					sl.erase(sl.end()-1);
					if(v == sly) {
						sl.erase(sl.end()-1);
						sl.back() += h;
					}
					else {
						sl.back() += v;
						sl.pb(h);
					}
					sl.pb(-v);
					sl.pb(0);
					sl.pb(0);
				}
			}
			else if(x > sle) {
				if(sl[j+2] == 0) {
					sl.erase(sl.end()-1);
					sl.erase(sl.end()-1);
					sl.pb(x - sle);
					sl.pb(v);
					sl.pb(h);
					sl.pb(-v);
					sl.pb(0);
					sl.pb(0);
				}
			}
			sly += sl[j+1];
		}
	}
	sl.pop_back();
	sl.pop_back();
	for(i = 0; i < sl.size(); i++)
		cout << sl[i] << " ";
	return 0;
}
