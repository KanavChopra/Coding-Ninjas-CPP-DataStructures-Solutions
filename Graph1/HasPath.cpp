#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> adj[], vector<int>& visited, int sv, int dv) {
    if (sv == dv) {
        return true;
    }
    visited[sv] = 1;
    for (auto& nbr : adj[sv]) {
        if (!visited[nbr]) {
            if (dfs(adj, visited, nbr, dv)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int sv, dv;
    cin >> sv >> dv;
    vector<int> visited(v, 0);
    if (dfs(adj, visited, sv, dv)) {
        cout << "true" << '\n';
    } else {
        cout << "false" << '\n';
    }
    return 0;
}