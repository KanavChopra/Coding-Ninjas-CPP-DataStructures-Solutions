bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}
bool dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y, int sourceX, int sourceY, char needColor, int n, int m) {
    if (!isValid(x, y, n, m)) {
        return false;
    }
    if (board[x][y] != needColor) {
        return false;
    }
    if (visited[x][y]) {
        return true;
    }
    visited[x][y] = true;
    int dXdY[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < 4; ++i) {
        int newX = x + dXdY[i][0];
        int newY = y + dXdY[i][1];
        if (isValid(newX, newY, n, m) && (board[newX][newY] == needColor) && !(newX == sourceX && newY == sourceY)) {
            if (dfs(board, visited, newX, newY, x, y, needColor, n, m)) {
                return true;
            }
        }
    }
    return false;
}
bool hasCycle(vector<vector<char>> &board, int n, int m) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                if (dfs(board, visited, i, j, -1, -1, board[i][j], n ,m)) {
                    return true;
                }
            }
        }
    }
    return false;
}