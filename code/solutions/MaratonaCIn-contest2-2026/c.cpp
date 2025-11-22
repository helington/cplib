#include <bits/stdc++.h>

using namespace std;

int solve() {
    bool found = false;
    string resp;

    int l_bound = 0;
    int r_bound = pow(10, 9);
    int hit = pow(10, 9) / 2;

    while (!found) {
        cout << "? " << hit << endl;
        cin >> resp;
        if (resp == "YES") {
            l_bound = hit + 1;
            hit = l_bound + (r_bound - l_bound) / 2;
        } else {
            r_bound = hit;
            hit = l_bound + (r_bound - l_bound) / 2;
        }

        if (r_bound == l_bound) {
            found = true;
        }
    }

    cout << "! " << hit << endl;

    return 0;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}