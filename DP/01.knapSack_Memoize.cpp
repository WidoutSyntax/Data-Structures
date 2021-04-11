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
	if (n == 0 || W == 0)
		return 0;
	if (DP[n][W] != -1)
		return DP[n][W];

	// Weight of an element is less than or equal to knapSack
	// Either include it or exclude it
	if (wt[n - 1] <= W)
		return DP[n][W] = max(val[n - 1] + knapSack(n - 1, W - wt[n - 1]), knapSack(n - 1, W));
	else
		return DP[n][W] = knapSack(n - 1, W);
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
		DP[i].resize(W + 1, -1);

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
