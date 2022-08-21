void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (!n) {
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << source << " " << destination << '\n';
    towerOfHanoi(n - 1, auxiliary, source, destination);
}
