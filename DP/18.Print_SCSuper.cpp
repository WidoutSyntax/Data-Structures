/*
Input:
geek
eke

Ouput:
geeke
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

string Print_SCSuper(string str1, string str2, int n, int m)
{
	for (int j = 0; j <= m; j++)
		DP[0][j] = 0;
	for (int i = 0; i <= n; i++)
		DP[i][0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				DP[i][j] = 1 + DP[i - 1][j - 1];
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}

	string ans = "";
	int i = n, j = m;
	while (i > 0 && j > 0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			ans.push_back(str1[i - 1]);
			i--;
			j--;
		}
		else if (DP[i - 1][j] > DP[i][j - 1])
		{
			ans.push_back(str1[i - 1]);
			i--;
		}
		else
		{
			ans.push_back(str2[j - 1]);
			j--;
		}
	}
	while (i > 0)
		ans.push_back(str1[i - 1]), i--;
	while (j > 0)
		ans.push_back(str2[j - 1]), j--;
	reverse(ans.begin(), ans.end());

	return ans;
}

void solve()
{
	string str1, str2;
	cin >> str1 >> str2;
	int n = str1.length(), m = str2.length();

	DP.assign(n + 1, vector<int>(m + 1, -1));
	cout << Print_SCSuper(str1, str2, n, m);
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
