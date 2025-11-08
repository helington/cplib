#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

bool less_than(string a, string b) {
    if (a + b < b + a) {
        return true;
    } else {
        return false;
    }
}

int partition(vector<string> &v, int low, int high) {
    string pivot = v[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (v[j] == pivot or less_than(v[j], pivot)) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void sort_strings(vector<string> &v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);

        sort_strings(v, low, pi - 1);
        sort_strings(v, pi + 1, high);
    }
}

int solve() {
    int n; cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort_strings(a, 0, n - 1);

    string s = "";
    for (int i = 0; i < n; i++) s += a[i];

    cout << s << endl;

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}