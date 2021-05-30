/*
Input:
1
12 3
2 1 1 3 2 3 4 5 6 7 8 9
2 0 5
1 3 6
2 2 8

Output:
12
30

TC: update in O(logn) and range sum in O(logn) = O(Qlogn)
SC: O(n)
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

int getSum(int ind, vector<int> &fTree)
{
    ind++;
    int sum = 0;
    while (ind > 0)
    {
        sum += fTree[ind];
        ind = ind - (ind & -ind);
    }
    return sum;
}

void update(int ind, int n, int add, vector<int> &fTree)
{
    ind++;
    while (ind <= n)
    {
        fTree[ind] += add;
        ind = ind + (ind & -ind);
    }
}

void construct(int n, vector<int> &v, vector<int> &fTree)
{
    for (int i = 0; i < n; i++)
        update(i, n, v[i], fTree);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> fTree(n + 1, 0);
    construct(n, v, fTree);

    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int ind, add;
            cin >> ind >> add;
            update(ind, n, add, fTree);
        }
        else if (a == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << getSum(r, fTree) - getSum(l - 1, fTree) << endl;
        }
    }
    cout << endl;
}

int32_t main()
{
    IOS();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
