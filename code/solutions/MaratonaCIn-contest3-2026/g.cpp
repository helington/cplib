#include <bits/stdc++.h>

#define ll long long int

#define endl '\n'

using namespace std;

int solve() {
    int n; cin >> n;
    string s; cin >> s;

    int great_string = 1;
    int counter = 1;
    char past_char = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] != past_char) {
            if (great_string < counter) {
                great_string = counter;
            }
            counter = 1;
        }
        else {
            counter++;
        }
    }

    cout << great_string << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
