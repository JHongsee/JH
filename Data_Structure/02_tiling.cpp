#include <bits/stdc++.h>
using namespace std;

int main(void) {
	vector<int>v(1001,0);
	int i, h;

	do {
		cin >> h;
		for(i = 0; i < h; i++)
			v[i]++;
	} while (h != 0);

	i = 0;
	do {
		cout << v[i] << " ";
		i++;
	} while(v[i-1] != 0);
	return 0;
}
