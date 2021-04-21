/*
Input:
5
1 2 3 4 3

Output:
30
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

const int MX = 1001;
vector<vector<int>> DP(MX, vector<int>(MX, -1));

int minComputation(vector<int> &v, int i, int j)
{
	if (i >= j)
		return 0;
	if (DP[i][j] != -1)
		return DP[i][j];

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++)
	{
		int temp = minComputation(v, i, k) + minComputation(v, k + 1, j) + (v[i - 1] * v[k] * v[j]);
		ans = min(ans, temp);
	}

	return DP[i][j] = ans;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout << minComputation(v, 1, n - 1);
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
