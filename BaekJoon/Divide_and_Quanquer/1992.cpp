#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<char>> tree;

void read() {
    string t;
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> t;
        vector<char> v(t.begin(), t.end());
        tree.push_back(v);
    }
}

bool is_all_z(int a, int b, int c, int d) {
    for(int i = a; i < b; i++) {
        for(int j = c; j < d; j++) {
            if (tree[i][j] == '1') { return false; }
        }
    }
    return true;
}

bool is_all_o(int a, int b, int c, int d) {
    for(int i = a; i < b; i++) {
        for(int j = c; j < d; j++) {
            if (tree[i][j] == '0') { return false; }
        }
    }
    return true;
}

void operating(int a, int b, int c, int d) {
    if      (is_all_o(a, b, c, d)) { cout << 1; return; }
    else if (is_all_z(a, b, c, d)) { cout << 0; return; }

    cout << "(";
    operating(   a   , (b+a)/2,    c   , (d+c)/2);
    operating(   a   , (b+a)/2, (d+c)/2,    d   );
    operating((b+a)/2,    b   ,    c   , (d+c)/2);
    operating((b+a)/2,    b   , (d+c)/2,    d   );
    cout << ")";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    operating(0, N, 0, N);
    return 0;
}
