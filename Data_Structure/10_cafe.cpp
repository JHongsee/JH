#include <bits/stdc++.h>
using namespace std;

class Customer {
public:
	int ID;
	int seat;
	Customer(int ID, int seat) : ID(ID), seat(seat) {};
};

int N, K, seat;
deque<int> seats;
deque<int> dis;
deque<Customer> customers;

void Read() {
	cin >> N >> K;
}

void set_dis() {
	int i;

	for(i = 0; i < seats.size() - 1; i++) {
		dis.push_back(seats[i+1] - seats[i]);
	}

	dis.push_back(N - (seats[i] - seats[0]));
}

int seat_find(int dis_max) {
	int i;
	for(i = 0; i < dis.size(); i++)
		if(dis[i] == dis_max) break;
	return i;
}

int next_seat() {
	int seat_num, dis_max;

	if(seats.empty())
		return 1;
	else if(seats.size() == 1)
		return ((N/2 + seats.front() - 1) % N) + 1;
	else {
		dis.clear();
		set_dis();
		dis_max  = *max_element(dis.begin(), dis.end());
		seat_num = seat_find(dis_max);
		return (((dis_max / 2) + seats[seat_num] - 1)  % N) + 1;
	}

}

deque<Customer>::iterator customer_find(int ID) {
	deque<Customer>::iterator it;

	if(!customers.empty()) {
		it = customers.begin();
		while(it != customers.end()) {
			if((*it).ID == ID) break;
			it++;
		}
	}
	else
		it = customers.end();

	return it;
}

void Welcome() {
	int ID;
	cin >> ID;

	deque<Customer>::iterator Cit = customer_find(ID);

	if(Cit == customers.end()) {
		if(customers.size() == N) return;

		seat = next_seat();
		Customer c(ID, seat);
		customers.push_back(c);
		seats.push_back(seat);
		cout << c.ID << ' ' << c.seat << endl;
	}
	else{
		deque<int>::iterator Iit;
		Iit = find(seats.begin(), seats.end(), (*Cit).seat);
		seats.erase(Iit);
		customers.erase(Cit);
	}

	sort(seats.begin(), seats.end());
}

int main() {
	Read();
	while(K) {
		Welcome();
		K--;
	}
	return 0;
}
