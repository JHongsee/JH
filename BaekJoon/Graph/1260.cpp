#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<vector<int>> graph;

void read() {
    int a, b;
    vector<int> v;
    cin >> N >> M >> V;

    for(int i = 0; i <= N; i++) { graph.push_back(v); }

    for(int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(auto &v : graph) { sort(v.begin(), v.end()); }
}

void DFS() {
    int v;
    vector<int> visited;
    stack<int> S;
    S.push(V);

    while(!S.empty()) {
        int i;
        v = S.top();
        if (find(visited.begin(), visited.end(), v) == visited.end()) { cout << v << " "; }
        visited.push_back(v);

        for(i = 0; i < graph[v].size(); i++) {
            if (find(visited.begin(), visited.end(), graph[v][i]) != visited.end()) { continue; }
            S.push(graph[v][i]); break;
        }

        if (i == graph[v].size()) { S.pop(); }
    }
    cout << "\n";
}

void BFS() {
    int v;
    queue<int> Q;
    vector<int> visited;
    Q.push(V);

    while(!Q.empty()) {
        v = Q.front();
        Q.pop();
        if (find(visited.begin(), visited.end(), v) != visited.end()) { continue; }

        visited.push_back(v);
        cout << v << " ";

        for(auto i : graph[v]) { Q.push(i); }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    DFS();
    BFS();
    return 0;
}
