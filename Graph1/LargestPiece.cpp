bool isValid(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}
int dfs(vector<vector<int>>& cake, vector<vector<int>>& visited, int x, int y, int n) {
    visited[x][y] = 1;
    int count = 1;
    int dXdY[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < 4; ++i) {
        int newX = x + dXdY[i][0];
        int newY = y + dXdY[i][1];
        if (isValid(newX, newY, n) && cake[newX][newY] == 1 && !visited[newX][newY]) {
            count += dfs(cake, visited, newX, newY, n);
        }
    }
    return count;
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int biggestPieceSize = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cake[i][j] == 1 && !visited[i][j]) {
                biggestPieceSize = max(biggestPieceSize, dfs(cake, visited, i, j, n));
            }
        }
    }
    return biggestPieceSize;
}