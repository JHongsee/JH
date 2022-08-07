#include <bits/stdc++.h>
using namespace std;

int sum;
vector<int> num;
vector<char> op;


void read() {
    int j;
    string t, n;
    cin >> t;
    for(auto i : t) {
        if (i == '+' || i == '-') {
            op.push_back(i);
            j = stoi(n);
            num.push_back(j);
            n = "";
        }
        else { n.push_back(i); }
    }
    j = stoi(n);
    num.push_back(j);
}

void operating() {
    char prev = '+';
    sum += num[0];

    for(int i = 1; i < num.size(); i++) {
        if (prev == '+') {
            if (op[i-1] == '+') { sum += num[i]; }
            else                { sum -= num[i]; prev = '-'; }
        }
        else { sum -= num[i]; }
    }
}

void outcome() {
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    operating();
    outcome();
    return 0;
}
