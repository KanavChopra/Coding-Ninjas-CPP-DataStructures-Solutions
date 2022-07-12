#include <iostream>
#include <vector>

using namespace std;

void isConnected(vector<vector<int> >& g, int v, int sv, vector<bool>& visited) {
    visited[sv] = true;
    for (int i = 0; i < v; ++i) {
        if (g[sv][i] && !visited[i]) {
            isConnected(g, v, i, visited);
        }
    }
}
int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<int> > g(v, vector<int>(v, 0));
    for (int i = 0; i < e; ++i) {
        int f, s;
        cin >> f >> s;
        g[f][s] = 1;
        g[s][f] = 1;
    }
    vector<bool> visited(v, false);
    isConnected(g, v, 0, visited);
    bool flag = false;
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            flag = true;
            cout << "false" << '\n';
            break;
        }
    }
    if (!flag) {
        cout << "true" << '\n';
    }
    return 0;
}
