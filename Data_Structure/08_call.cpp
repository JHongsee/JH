#include <bits/stdc++.h>
using namespace std;

int N, len, k1, k2;
stack<string> s;
stack<string> seq;
vector<vector<string>> v;

void Read() {
	cin >> N >> k1 >> k2;

	for(int i = 0; i < N; i++) {
		string str;
		vector<string> temp;
		do {
			cin >> str;
			temp.push_back(str);
		}while(str != "$");
		for(int i = 0; i < temp.size(); i++) {
			if((!(temp[i][0] >= 'A' && temp[i][0] <= 'Z')) && (temp[i] != "$"))
				temp[i] = temp[0] + "-" + temp[i];
		}
		v.push_back(temp);
	}
}

bool isrecursive(stack<string> temp) {
	vector<string> v1;
	vector<string> v2;
	v1.push_back("M");
	v2.push_back("M");
	int i = 1;

	while(!temp.empty()) {
		v1.push_back(temp.top());
		temp.pop();
		if(!temp.empty())
			if(v1[1] == temp.top()) break;
	}

	while(!(temp.empty()) && (i < v1.size())) {
		v2.push_back(temp.top());
		temp.pop();
		i++;
	}

	if (v1.size() == 1) {
		return false;
	}
	else {
		if(v1 == v2) return true;
		else return false;
	}
	return false;
}

void re(int par) {
	int i = 1;
	while(i < v[par].size()) {
		if(v[par][i] == "$") seq.pop();
		else if(v[par][i].length() == 1) {
			int p;
			string name = v[par][i];
			seq.push(name);
			for(p = 0; p < N; p++) {
				if(v[p].front() == name) break;
			}
			if(isrecursive(seq)) return;
			re(p);
			if(isrecursive(seq)) return;
		}
		else {
			s.push(v[par][i]);
			len++;
		}
		i++;
	}
}

void Set() {
	int i;
	string name = "M";
	seq.push(name);
	for(i = 0; i < N; i++) {
		if(v[i].front() == name) break;
	}
	re(i);
}

void result(stack<string> s, int k) {
	while(k) {
		s.pop();
		k--;
	}
	cout << s.top() << endl;
}

int main() {
	Read();
	Set();
	k1 = len - k1;
	k2 = len - k2;

	if(isrecursive(seq)) cout << "DEADLOCK" << endl;
	else {
		if(k1 < 0) cout << "NONE" << endl;
		else result(s, k1);

		if(k2 < 0) cout << "NONE" << endl;
		else result(s, k2);
	}
	return 0;
}
