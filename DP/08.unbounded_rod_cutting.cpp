/*
Input:
8
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20

Output:
22
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

const int MX = 100005;
vector<int> len(MX), price(MX);
vector<vector<int>> DP;

int maxProfit(int n)
{
	for (int j = 0; j <= n; j++)
		DP[0][j] = 0;
	for (int i = 0; i <= n; i++)
		DP[i][0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (len[i - 1] <= j)
				DP[i][j] = max(price[i - 1] + DP[i][j - len[i - 1]], DP[i - 1][j]);
			else
				DP[i][j] = DP[i - 1][j];
		}
	}

	return DP[n][n];
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> len[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];

	DP.resize(n + 1);
	for (int i = 0; i <= n; i++)
		DP[i].resize(n + 1, -1);

	cout << maxProfit(n);
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
