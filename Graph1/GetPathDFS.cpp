#include <iostream>
#include <queue>

using namespace std;

bool dfs(vector<vector<int>>& g, vector<int>& visited, int sv, int dv, vector<int>& output, int v) {
    if (sv == dv) {
        output.push_back(dv);
        return true;
    }
    visited[sv] = 1;
    for (int i = 0; i < v; ++i) {
        if (g[sv][i] && !visited[i]) {
            if (dfs(g, visited, i, dv, output, v)) {
                output.push_back(sv);
                return true;
            }
        }
    }
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int>> g(v, vector<int>(v));
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    int sv, dv;
    cin >> sv >> dv;
    vector<int> visited(v, 0);
    vector<int> output;
    if (dfs(g, visited, sv, dv, output, v)) {
        for (const auto& val : output) {
            cout << val << " ";
        }
    }
}