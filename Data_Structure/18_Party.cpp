#include <bits/stdc++.h>
using namespace std;

struct Vertex {
	char name;
	vector<char> adj;
};

int N;
vector<char> person;
vector<Vertex> graph;
vector<tuple<char, int, int, int>> dis;

void Read() {
	char a, b, c;
	cin >> N >> a >> b >> c;

	person.push_back(a);
	person.push_back(b);
	person.push_back(c);
	person.resize(3);
	graph.resize(N);

	for(int i = 0; i < N; i++) {
		Vertex temp;
		cin >> a;
		temp.name = a;
		while(true) {
			cin >> a;
			if(a == '$') break;
			temp.adj.push_back(a);
		}
		graph.push_back(temp);
	}
}

char s;
vector<tuple<char, int>> BFS(char name) {
	queue<char> Q;
	int distance = 1, len = 0;
	vector<char> visited;
	vector<tuple<char, int>> dis;

	Q.push(name);
	visited.push_back(name);
	dis.push_back(make_tuple(name, 0));

	while(!Q.empty()) {
		s = Q.front();
		Q.pop();

		auto it1 = find_if(graph.begin(), graph.end(), \
						[](Vertex v){return v.name == s;});

		for(auto i : it1 -> adj) {
			auto it2 = find(visited.begin(), visited.end(), i);
			if(it2 == visited.end()) {
				Q.push(i);
				visited.push_back(i);
				dis.push_back(make_tuple(i, distance));
			}
		}
		if(len == 0) {
			len = Q.size() - 1;
			distance++;
		}
		else {
			len--;
		}
	}

	return dis;
}

bool mycmp(tuple<char, int> a, tuple<char, int> b) {
	if(get<1>(a) == get<1>(b)) {
		return get<0>(a) < get<0>(b);
	}
	return get<1>(a) < get<1>(b);
}

char name;
void Process() {
	vector<tuple<char, int>> dis1 = BFS(person.at(0));
	vector<tuple<char, int>> dis2 = BFS(person.at(1));
	vector<tuple<char, int>> dis3 = BFS(person.at(2));
	vector<tuple<char, int>> dis_all;

	int len = dis1.size() + dis2.size() + dis3.size();
	if(len != 3*N) {
		cout << '@' << '\n' << -1 << endl;
		return;
	}

	for(auto i : dis1) {
		name = get<0>(i);
		auto it2 = find_if(dis2.begin(), dis2.end(), [](tuple<char, int> t){return get<0>(t) == name;});
		auto it3 = find_if(dis3.begin(), dis3.end(), [](tuple<char, int> t){return get<0>(t) == name;});
		int dis_max = max({get<1>(i), get<1>(*it2), get<1>(*it3)});
		dis_all.push_back(make_tuple(name, dis_max));
	}

	sort(dis_all.begin(), dis_all.end(), mycmp);

	int dis = get<1>(dis_all.front());
	if(dis != 0) { dis = dis + 2*(dis - 1); }
	cout << get<0>(dis_all.front()) << '\n' << dis << endl;
}

int main() {
	Read();
	Process();
	return 0;
}
