/*
Input:
3 4
1 2 7

Output:
Sum not present
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

vector<vector<bool>> DP;
vector<int> v;

bool subSum(int n, int sum)
{
	// initialization
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

	return DP[n][sum];
}

void solve()
{
	int n, sum;
	cin >> n >> sum;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	DP.resize(n + 1);
	for (int i = 0; i < n + 1; i++)
		DP[i].resize(sum + 1, false);

	if (subSum(n, sum))
		cout << "Sum present";
	else
		cout << "Sum not present";
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
