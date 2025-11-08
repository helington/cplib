#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

bool check(vector<vector<int> > a, int row, int col, int c) {
    for (int i = 0; i < 9; i++) {
        if (a[row][i] == c) return false;
        if (a[i][col] == c) return false;
        if
    }
}

bool solveSudoku(vector<vector<int> > a, int i = 0, int j = 0) {

}

int solve() {
    vector<vector<int> > a(9, vector<int>(9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }

    bool possible = solveSudoku(a);
    if (possible) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution" << endl;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}