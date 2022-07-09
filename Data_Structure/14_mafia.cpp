#include <bits/stdc++.h>
using namespace std;

class person {
public:
	string name;
	list<person*> child;
	person* boss = NULL;
};

int N;
string a, b;
list<person> member;

void Read() {
	cin >> N;
	while(N-1) {
		cin >> a >> b;
		auto it1 = find_if(member.begin(), member.end(), [](person p){ return p.name == a; });
		auto it2 = find_if(member.begin(), member.end(), [](person p){ return p.name == b; });
		if (it1 != member.end() && it2 != member.end()) {
			(*it1).boss = &(*it2);
			(*it2).child.push_back(&(*it1));
		}
		else if(it1 != member.end()) {
			person p2;
			p2.name = b;
			p2.child.push_back((&(*it1)));
			member.push_back(p2);
			(*it1).boss = &member.back();
		}
		else if(it2 != member.end()) {
			person p1;
			p1.name = a;
			member.push_back(p1);
			(*it2).child.push_back(&member.back());
			member.back().boss = ((&(*it2)));
		}
		else if(it1 == member.end() && it2 == member.end()) {
			person p1, p2;
			p1.name = a;
			p2.name = b;
			member.push_back(p1);
			member.push_back(p2);
			auto it = member.end();
			advance(it, -2);
			member.back().child.push_back(&(*it));
			(*it).boss = &(member.back());
		}
		N--;
	}
}


int do_sub(person p) {
	int len = p.child.size();
	if(!(p.child.empty()))
		for(auto i : p.child) {	len += do_sub(*i); }
	return len;
}

int depth(person* p) {
	if(p -> boss == NULL) { return 0; }
	return depth(p -> boss) + 1;
}

bool mycmp(person p1, person p2) {
	if(do_sub(p1) == do_sub(p2)) {
		if(depth(&p1) == depth(&p2)) {
			return p1.name < p2.name;
		}
		return depth(&p1) < depth(&p2);
	}
	return do_sub(p1) > do_sub(p2);
}

void Outcome() {
	member.sort(mycmp);
	for(auto i : member) { cout << i.name << endl; }
}

int main () {
	Read();
	Outcome();
	return 0;
}
