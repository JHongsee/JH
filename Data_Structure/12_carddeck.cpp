#include <bits/stdc++.h>
using namespace std;

int N, k;
list<int> deck;

void Read() {
	cin >> N >> k;
	for(int i = 1; i <= N; i++) { deck.push_back(i); }
}

void Shuffle() {
	list<int> A, B;
	auto center = deck.begin();
	advance(center, N/2);

	A.splice(A.begin(), deck, deck.begin(), center    );
	B.splice(B.begin(), deck, deck.begin(), deck.end());

	while(!(B.empty())) {
		deck.push_back(A.front());
		deck.push_back(B.front());
		A.pop_front();
		B.pop_front();
	}
}

void Cut() {
	int i, j;
	cin >> i >> j;
	auto cut_s = deck.begin();
	auto cut_e = deck.begin();;

	advance(cut_s, i-1);
	advance(cut_e, j  );

	deck.splice(deck.end(), deck, cut_s, cut_e);
}

void Work() {
	while(k) {
		string input;
		cin >> input;

		if(input == "Shuffle" ) { Shuffle(); }
		else if(input == "Cut") { Cut();     }
		k--;
	}
}

void Outcome() {
	auto center = deck.begin();
	advance(center, N/2 - 1);
	cout << deck.front() << ' ' << *center << ' ' << deck.back() << endl;
}

int main () {
	Read();
	Work();
	Outcome();
	return 0;
}
