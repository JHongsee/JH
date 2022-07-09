#include <bits/stdc++.h>
using namespace std;

int N, peak_max, peak_b, peak_e, peak_len;
priority_queue<int> b_point, e_point;
vector<int> points;

void Read() {
	cin >> N;
	while(N) {
		int b, e;
		cin >> b >> e;
		b_point.push(b);
		e_point.push(e);
		N--;
	}
	e_point.push(0);
}

void C_peak(int b, int e, int len) {
	if(peak_max < points.size()) {
		peak_max = points.size();
		peak_len = len;
		peak_b = b;
		peak_e = e;
	}
	else if(peak_max == points.size() && peak_len < len) {
		peak_len = len;
		peak_b = b;
		peak_e = e;
	}
}

void Get_peak() {
	int b, e, len;
	while(!b_point.empty()) {
		if(b_point.top() < e_point.top()) {
			e = e_point.top();
			points.push_back(e);
			e_point.pop();
		}
		else if(b_point.top() > e_point.top()) {
			b   = b_point.top();
			len = e - b;
			C_peak(b, e, len);
			e = b;
			points.pop_back();
			b_point.pop();
		}
		else {
			b   = b_point.top();
			len = e - b;
			C_peak(b, e, len);
			e = b;
			b_point.pop();
			e_point.pop();
		}
	}
}

void Outcome() {
	cout << peak_b << ' ' << peak_e << endl;
}

int main() {
	Read();
	Get_peak();
	Outcome();
	return 0;
}
