#include <bits/stdc++.h>
using namespace std;

int K, N;
long long pivot, le, ri;
vector<int> line;

void read() {
    int t;
    cin >> K >> N;

    for(int i = 0; i < K; i++) {
        cin >> t;
        line.push_back(t);
    }
    sort(line.begin(), line.end());
    le = 1; ri = line[K-1];
}

int counting(int p) {
    int cnt = 0;
    for(auto l : line) { cnt += l / p; }

    return cnt;
}

void operating() {
    while(le <= ri) {
        pivot = (le + ri) / 2;
        if (counting(pivot) < N) { ri = pivot - 1; }
        else                     { le = pivot + 1; }
    }
    pivot = (le + ri) / 2;
}

void outcome() {
    cout << pivot << "\n";
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
