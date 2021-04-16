/*
Input:
abcdgh
abedfhr

Output:
4
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

vector<vector<int>> DP;

int LCS(string str1, string str2, int n, int m)
{
	if (n == 0 || m == 0)
		return 0;

	if (DP[n][m] != -1)
		return DP[n][m];

	if (str1[n] == str2[m])
		return DP[n][m] = 1 + LCS(str1, str2, n - 1, m - 1);
	else
		return DP[n][m] = max(LCS(str1, str2, n, m - 1), LCS(str1, str2, n - 1, m));
}

void solve()
{
	string str1, str2;
	cin >> str1 >> str2;
	int n = str1.length(), m = str2.length();

	DP.resize(n + 1);
	for (int i = 0; i <= n; i++)
		DP[i].resize(m + 1, -1);

	cout << LCS(str1, str2, n, m);
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
