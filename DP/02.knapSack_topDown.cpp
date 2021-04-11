/*
Input:
3 4
1 2 3
4 5 1

Output:
3
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
vector<vector<int>> DP;
vector<int> val(MX), wt(MX);

int knapSack(int n, int W)
{
	for (int i = 0; i < n + 1; i++)
		DP[i][0] = 0;
	for (int j = 0; j < W + 1; j++)
		DP[0][j] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (wt[i - 1] <= j)
				DP[i][j] = max(val[i - 1] + DP[i - 1][j - wt[i - 1]], DP[i - 1][j]);
			else
				DP[i][j] = DP[i - 1][j];
		}
	}
	return DP[n][W];
}

void solve()
{
	int n, W;
	cin >> n >> W;
	for (int i = 0; i < n; i++)
		cin >> val[i];
	for (int i = 0; i < n; i++)
		cin >> wt[i];

	DP.resize(n + 1);
	for (int i = 0; i < n + 1; i++)
		DP[i].resize(W + 1, 0);

	cout << knapSack(n, W);
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
