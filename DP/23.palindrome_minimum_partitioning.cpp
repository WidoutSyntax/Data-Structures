/*
Input: pawar
Output: 2
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

bool check(string str, int i, int j)
{
	while (i < j)
	{
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int minPartition(string str, int i, int j)
{
	if (i >= j)
		return 0;

	if (DP[i][j] != -1)
		return DP[i][j];
	if (check(str, i, j))
		return 0;

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++)
	{
		int left, right;
		if (DP[i][k] != -1) left = DP[i][k];
		else left = minPartition(str, i, k);
		if (DP[k + 1][j] != -1) right = DP[k + 1][j];
		else right = minPartition(str, k + 1, j);
		int temp = left + right + 1;
		ans = min(ans, temp);
	}

	return DP[i][j] = ans;
}

void solve()
{
	string str;
	cin >> str;
	cout << minPartition(str, 0, str.length() - 1);
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
