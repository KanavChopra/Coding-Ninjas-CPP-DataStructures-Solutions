#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


vector<int> bfs(vector<vector<int>>& g, vector<int>& visited, int sv, int dv, int v) {
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;
    unordered_map<int, int> parent;
    bool flag = false;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (int i = 0; i < v; ++i) {
            if (g[front][i] && !visited[i]) {
                visited[i] = 1;
                q.push(i);
                parent[i] = front;
                if (i == dv) {
                    flag = true;
                    break;
                }
            }
        }
    }
    vector<int> output;
    if (!flag) {
        return {};
    } else {
        int currVertex = dv;
        output.push_back(currVertex);
        while (currVertex != sv) {
            currVertex = parent[currVertex];
            output.push_back(currVertex);
        }
    }
    return output;
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
    vector<int> output = bfs(g, visited, sv, dv, v);
    if (!output.empty()) {
        for (const auto& val : output) {
            cout << val << " ";
        }
    }
    return 0;
}