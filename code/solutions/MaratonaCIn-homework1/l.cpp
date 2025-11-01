#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int solve()
{
    int n, k;
    cin >> n >> k;

    int x, c;
    ll a, b;
    cin >> x >> a >> b >> c;

    vector<ll> x_vec(n);
    x_vec[0] = x;

    for (int i = 1; i < n; i++)
    {
        x_vec[i] = (a * x_vec[i - 1] + b) % c;
    }

    ll window_sum = accumulate(x_vec.begin(), x_vec.begin() + k, 0ll);
    int left = 0;
    ll xor_value = window_sum;

    for (int right = k; right < n; right++)
    {
        window_sum += x_vec[right];
        window_sum -= x_vec[left];
        xor_value ^= window_sum;
        left++;
    }

    cout << xor_value << endl;

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}