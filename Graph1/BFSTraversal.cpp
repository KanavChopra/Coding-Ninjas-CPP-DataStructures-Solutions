#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>>& g, vector<int>& visited, int src, int v) {
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    vector<int> output;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        output.push_back(front);
        for (int i = 0; i < v; ++i) {
            if (g[front][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return output;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v, 0));
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    vector<int> visited(v, 0);
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            vector<int> output = bfs(g, visited, i, v);
            for (const auto& i : output) {
                cout << i << " ";
            }
        }
    }
    return 0;
}