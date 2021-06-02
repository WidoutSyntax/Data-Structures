/*
Input: 3 31
Ouput: 3 5 7 11 13 17 19 23 29 31
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void IOS()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void sieve_prime(int n, vector<int> &prime)
{
    vector<bool> mark(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (mark[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                mark[i] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (mark[i]) prime.push_back(i);
}

void seg_sieve(int low, int high)
{
    if (low < 2)
        low = 2;
    int limit = floor(sqrt(high)) + 1;
    vector<int> prime;
    sieve_prime(limit, prime);

    int n = high - low + 1;
    vector<int> mark(n + 1, true);

    for (int i = 0; i < prime.size(); i++)
    {
        int l = (low / prime[i]) * prime[i];
        if (l < low)
            l += prime[i];
        if (l == prime[i])
            l += prime[i];
        for (int j = l; j <= high; j += prime[i])
            mark[j - low] = false;
    }

    for (int i = low; i <= high; i++)
        if (mark[i - low])
            cout << i << " ";
}

void solve()
{
    int l, r;
    cin >> l >> r;
    seg_sieve(l, r);
    cout << endl;
}

int32_t main()
{
    IOS();
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
