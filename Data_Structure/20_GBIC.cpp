#include <bits/stdc++.h>

using namespace std;

char C;
array<char, 2> op_c = { 'R', 'Q' };
multimap<set<int>, int> GBIC;

void R() {
	set<int> Key;
	while(true) {
		int j;
		cin >> j;

		if(j > 0) { Key.insert(j); }
		else { GBIC.insert(pair<set<int>, int>(Key, j)); break; }
	}
}

void Q() {
	set<int> Key;
	while(true) {
		int j;
		cin >> j;

		if(j != 0) { Key.insert(j); }
		else if( j == 0 && GBIC.count(Key) != 0) {
			set<int, greater<int>> S;
			for(auto iter = GBIC.lower_bound(Key); iter != GBIC.upper_bound(Key); iter++) {
				S.insert(iter -> second);
			}
			for(auto i : S) { cout << i << " "; }
			cout << '\n';
			break;
		}
		else { cout << "None" << endl; break; }
	}
}

void RQ() {
	while(true){
		cin >> C;
		if(C == '$') { return; }

		int i = find(op_c.begin(), op_c.end(), C) - op_c.begin();

		switch(i) {
			case 0: {
				R();
				break;
			}
			case 1: {
				Q();
				break;
			}
			default: { cout << "INVALID OPERATOR" << endl; break; }
		}
	}
}

int main() {
    RQ();
    return 0;
}
