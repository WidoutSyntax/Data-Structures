/*
Input:
4
1 6 11 5

Output:
1
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

vector<int> v;
vector<vector<bool>> DP;

void subSum(int n, int sum)
{
	for (int j = 0; j <= sum; j++)
		DP[0][j] = false;
	for (int i = 0; i <= n; i++)
		DP[i][0] = true;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (v[i - 1] <= j)
				DP[i][j] = DP[i - 1][j - v[i - 1]] || DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j];
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	int sum = 0;
	for (int i : v)
		sum += i;

	DP.resize(n + 1);
	for (int i = 0; i <= n; i++)
		DP[i].resize(sum + 1);
	subSum(n, sum);

	vector<int> sset;
	for (int j = 0; j <= sum; j++)
		if (DP[n][j] && j <= sum / 2)
			sset.push_back(j);

	int mn = INT_MAX;
	for (int i = 0; i < sset.size(); i++)
		mn = min(mn, sum - 2 * sset[i]);
	cout << mn;
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
