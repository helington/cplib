#include <bits/stdc++.h>

using namespace std;

string issubtring(string t, string u)
{
    int length = t.length();

    if (t.find(u) != string::npos)
    {
        return "Yes";
    }

    int left = 0;
    bool found;
    for (int right = u.size() - 1; right < length; right++)
    {
        found = true;
        for (int t_i = left, u_i = 0; t_i <= right; u_i++, t_i++) {
            if (t[t_i] != u[u_i] && t[t_i] != '?') {
                found = false;
                break;
            }
        }
        if (found) {
            return "Yes";
        }
        left++;
    }
    return "No";
}

int solve()
{
    string t;
    cin >> t;

    string u;
    cin >> u;

    cout << issubtring(t, u) << endl;

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}