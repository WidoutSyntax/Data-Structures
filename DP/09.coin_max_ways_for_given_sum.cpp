/*
Input:
3 5
1 2 3

Output:
5
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
vector<int> coin(MX);
vector<vector<int>> DP;

int countMaxWays(int n, int sum)
{
	for (int j = 0; j <= sum; j++)
		DP[0][j] = 0;
	for (int i = 0; i <= n; i++)
		DP[i][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (coin[i - 1] <= j)
				DP[i][j] = DP[i][j - coin[i - 1]] + DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j];
		}
	}

	return DP[n][sum];
}

void solve()
{
	int n, sum;
	cin >> n >> sum;
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	DP.resize(n + 1);
	for (int i = 0; i <= n; i++)
		DP[i].resize(sum + 1, -1);

	cout << countMaxWays(n, sum);
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
