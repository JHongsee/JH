#include <bits/stdc++.h>
using namespace std;

vector<string> ops { "front", "back", "cut", "double", "flip", "report" };
list<char> DNA;
int N;

void Read() {
	ifstream in("/NESPA/sapiens.txt");
	string str;
	getline(in, str);
	if(in.is_open()) {
		while(!in.eof()) {
			char c;
			in.get(c);
			if(c != '\n') { DNA.push_back(c); }
		}
	}
	in.close();
	cin >> N;
}

void do_front(list<char>::iterator its, list<char>::iterator ite) {
	DNA.splice(DNA.begin(), DNA, its, ite);
}

void do_back(list<char>::iterator its, list<char>::iterator ite) {
	DNA.splice(DNA.end(), DNA, its, ite);
}

void do_cut(list<char>::iterator its, list<char>::iterator ite) {
	DNA.erase(its, ite);
}

void do_double(list<char>::iterator its, list<char>::iterator ite) {
	DNA.insert(ite, its, ite);
}

void do_flip(list<char>::iterator its, list<char>::iterator ite) {
	auto tempit = its;
	advance(tempit, -1);
	list<char> templist;
	templist.splice(templist.begin(), DNA, its, ite);
	templist.reverse();
	advance(tempit, +1);
	DNA.splice(tempit, templist, templist.begin(), templist.end());
}

void do_report(list<char>::iterator its, list<char>::iterator ite) {
	for(auto i = its; i != ite; i++) {
		cout << *i;
	}
	printf("\n");
}

bool cmp(int& i, int& j) {
	if(i > DNA.size()) { return false; }
	else if(i <= DNA.size() && j > DNA.size()) {
		j = DNA.size();
		return true;
	}
	else { return true;	}
}

void do_work() {
	while(N) {
		string str;
		int i, j;
		cin >> str >> i >> j;
		auto its = DNA.begin();
		auto ite = DNA.begin();
		int index = find(ops.begin(), ops.end(), str) - ops.begin();
		if(cmp(i, j)) {
			advance(its, i-1);
			advance(ite, j  );
			switch(index) {
				case 0:  { do_front (its, ite); break; }
				case 1:  { do_back  (its, ite); break; }
				case 2:  { do_cut   (its, ite); break; }
				case 3:  { do_double(its, ite); break; }
				case 4:  { do_flip  (its, ite); break; }
				case 5:  { do_report(its, ite); break; }
				default: { cout << "INVALID OPERATION" << endl; }
			}
		}
		else {
			if(index == 5) { cout << "NONE" << endl; }
		}
		N--;
	}
}

int main () {
	Read();
	do_work();
	return 0;
}
