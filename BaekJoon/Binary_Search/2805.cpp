#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long le, ri, pivot;
vector<long long> tree;

void read() {
    long long t;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> t;
        tree.push_back(t);
    }
    le = 1; ri = *max_element(tree.begin(), tree.end());
    pivot = (le + ri) / 2;
}

long long get_len(long long p) {
    long long cnt = 0;
    for(auto t : tree) {
        if (t - p > 0) { cnt += t-p;}
    }
    return cnt;
}

void operating() {
    while(le <= ri) {
        if (get_len(pivot) < M) { ri = pivot-1; }
        else                    { le = pivot+1; }
        pivot = (le + ri) / 2;
    }
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
