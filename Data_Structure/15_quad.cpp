#include <bits/stdc++.h>
using namespace std;

int k;
string op;
array<string, 2> ops = { "QTS", "IMG" };
list<char> I2Q_Outcome;
list<list<char>> Q2I_Outcome;

void Read() {
	cin >> k >> op;
}

void QTS_2_IMG() {
	string input;
	cin >> input;
	list<char> qts(input.begin(), input.end());
	stack<char> s;
	list<char> temp;
	for(auto i : qts) {
		if      (i == '(') s.push('(');
		else if (i == ')') s.pop();
		else {
			int n = k - s.size();
			for(int j = 0; j < pow(2, n) * pow(2, n); j++) { temp.push_back(i);	}
		}
	}

	for(auto i : temp) {
		list<char> c;
		c.push_back(i);
		Q2I_Outcome.push_back(c);
	}

	do{
		auto it1 = Q2I_Outcome.begin();
		auto it2 = Q2I_Outcome.begin();
		auto it3 = Q2I_Outcome.begin();
		auto it4 = Q2I_Outcome.begin();
		advance(it2, 1);
		advance(it3, 2);
		advance(it4, 3);
		do{
			it1 -> splice(it1 -> begin(), *it2, it2 -> begin(), it2 -> end());
			it4 -> splice(it4 -> begin(), *it3, it3 -> begin(), it3 -> end());
			Q2I_Outcome.erase(it3);
			Q2I_Outcome.erase(it2);
			advance(it1, 4);
			advance(it2, 4);
			advance(it3, 4);
			advance(it4, 4);
		} while(it1 != Q2I_Outcome.end());
		auto idx = Q2I_Outcome.begin();
		for(auto i : Q2I_Outcome) {
			if(i.empty()) { Q2I_Outcome.erase(idx); }
			advance(idx, 1);
		}
	} while(Q2I_Outcome.front().size() != pow(2, k));
}

void IMG_2_QTS(list<list<char>> I2Q, int k) {
	if(all_of(I2Q.begin(), I2Q.end(), [](list<char> c){return all_of(c.begin(), c.end(), [](char c){return c == '1';});})) {
		I2Q_Outcome.push_back('1');
	}
	else if(all_of(I2Q.begin(), I2Q.end(), [](list<char> c){return all_of(c.begin(), c.end(), [](char c){return c == '0';});})) {
		I2Q_Outcome.push_back('0');
	}
	else {
		I2Q_Outcome.push_back('(');
		list<list<char>> I2Q_1;
		list<list<char>> I2Q_2;
		list<list<char>> I2Q_3;
		list<list<char>> I2Q_4;
		list<list<char>> I2Q_t;

		auto it = I2Q.begin();
		advance(it, k/2);
		I2Q_t.splice(I2Q_t.begin(), I2Q, I2Q.begin(), it);

		for(auto i : I2Q_t) {
			list<char> temp1;
			list<char> temp2;
			auto it = i.begin();
			advance(it, k/2);
			temp2.splice(temp2.begin(), i, i.begin(), it);
			temp1.splice(temp1.begin(), i, i.begin(), i.end());
			I2Q_2.push_back(temp2);
			I2Q_1.push_back(temp1);
		}
		for(auto i : I2Q) {
			list<char> temp3;
			list<char> temp4;
			auto it = i.begin();
			advance(it, k/2);
			temp3.splice(temp3.begin(), i, i.begin(), it);
			temp4.splice(temp4.begin(), i, i.begin(), i.end());
			I2Q_3.push_back(temp3);
			I2Q_4.push_back(temp4);
		}

		IMG_2_QTS(I2Q_1, k/2);
		IMG_2_QTS(I2Q_2, k/2);
		IMG_2_QTS(I2Q_3, k/2);
		IMG_2_QTS(I2Q_4, k/2);
		I2Q_Outcome.push_back(')');
	}
}

void Outcome() {
	int idx = find(ops.begin(), ops.end(), op) - ops.begin();
	switch(idx) {
		case 0: {
			QTS_2_IMG();
			break;
		}
		case 1: {
			k = pow(2, k);
			list<list<char>> I2Q;
			for(int i = 0; i < k; i++) {
				string str;
				cin >> str;
				list<char> temp(str.begin(), str.end());
				I2Q.push_back(temp);
			}
			IMG_2_QTS(I2Q, k);
			for(auto i : I2Q_Outcome) { cout << i; }
			break;
		}
		default: { cout << "INVALID OPERATION" << endl; }
	}
}

int main() {
	Read();
	Outcome();
	return 0;
}
