#include <bits/stdc++.h>
using namespace std;

struct person {
	int ID;
	int age;
	char gender;
};

int N;
vector<person> old;
vector<person> child;
vector<person> adult;
queue<person> seq;

void Read() {
	cin >> N;

	for(int i = 0; i < N; i++) {
		int ID, age;
		char gender;

		cin >> ID >> age >> gender;

		person p;
		p.ID = ID;
		p.age = age;
		p.gender = gender;

		if      (p.age >= 61) { old.push_back(p);   }
		else if (p.age <= 15) { child.push_back(p); }
		else				  { adult.push_back(p); }
	}
}

void Order() {
	vector<person>::iterator oldi;
	vector<person>::iterator childi;
	vector<person>::iterator adulti;
	for(oldi = old.begin(); oldi != old.end(); oldi++) {
		if((*oldi).gender == 'M') {
			seq.push((*oldi));
			old.erase(oldi);
			oldi--;
		}
	}

	for(auto i : old) {	seq.push(i); }

	for(auto i : child) { seq.push(i); }

	for(adulti = adult.begin(); adulti != adult.end(); adulti++) {
		if((*adulti).gender == 'F') {
			seq.push((*adulti));
			adult.erase(adulti);
			adulti--;
		}
	}

	for(auto i : adult) { seq.push(i); }
}

void MyQprint() {
	while(!seq.empty()) {
		cout << seq.front().ID << endl;
		seq.pop();
	}
}

int main() {
	Read();
	Order();
	MyQprint();
}
