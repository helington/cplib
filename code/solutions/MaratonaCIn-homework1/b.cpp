#include <bits/stdc++.h>

using namespace std;

int solve()
{
    int n;
    cin >> n;

    deque<int> a;
    deque<int> b;
    deque<int> c;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }

    deque<string> s;
    bool impossible = false;
    while (c.size() != n && impossible == false)
    {
        if (c.empty() == true)
        {
            if (a.back() == 1)
            {
                a.pop_back();
                c.push_front(1);
                s.push_back("A C");
            }
            else
            {
                b.push_front(a.back());
                a.pop_back();
                s.push_back("A B");
            }
        }
        else if (a.empty() == false
            && a.back() == c.front() + 1)
        {
            c.push_front(a.back());
            a.pop_back();
            s.push_back("A C");
        }
        else if (b.front() == c.front() + 1)
        {
            c.push_front(b.front());
            b.pop_front();
            s.push_back("B C");
        }
        else if (a.empty() == false)
        {
            b.push_front(a.back());
            a.pop_back();
            s.push_back("A B");
        }
        else
        {
            impossible = true;
        }
    }

    if (impossible == true)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << s.size() << endl;
        for (auto i : s)
        {
            cout << i << endl;
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}