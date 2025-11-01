#include <bits/stdc++.h>

#define endl '\n'

using namespace  std;

string find_ancestor(vector<string> s, int n) {
    bool found;
    for (int i = 0; i < n; i++) {
        found = true;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (s[j].find(s[i]) == string::npos) {
                    found = false;
                    break;
                }
            }
        }
        if (found) {
            return s[i];
        }
    }
    return "Not found";
}

int solve() {
    int n;
    cin >> n;

    vector<string> s(n);
    string t;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    cout << find_ancestor(s, n) << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}