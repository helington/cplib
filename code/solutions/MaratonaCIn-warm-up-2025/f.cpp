#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> vec, int n, long long k)
{
    int total = 0;
    int current_n = n;
    int x = 1;
    while (x > 0 && current_n > 0)
    {
        x = 0;
        for (int i = 0; i < n - current_n + 1; i++)
        {
            if (accumulate(vec.begin() + i, vec.begin() + current_n + i, 0LL) >= k)
            {
                total++;
                x++;
            }
        }
        current_n--;
    }

    cout << total << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    solve(vec, n, k);
}