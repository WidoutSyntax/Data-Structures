/*
Input: T^F&T
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

unordered_map<string, int> DP;

int maxWays(string str, int i, int j, bool isTrue)
{
	if (i > j)
		return false;
	if (i == j)
	{
		if (isTrue == true)
			return str[i] == 'T';
		else
			return str[i] == 'F';
	}

	string key = to_string(i);
	key.push_back('#');
	key.append(to_string(j));
	key.push_back('#');
	isTrue == true ? key.push_back('T') : key.push_back('F');
	if (DP.find(key) != DP.end())
		return DP[key];

	int ans = 0;
	for (int k = i + 1; k <= j - 1; k = k + 2)
	{
		int lT = maxWays(str, i, k - 1, true);
		int lF = maxWays(str, i, k - 1, false);
		int rT = maxWays(str, k + 1, j, true);
		int rF = maxWays(str, k + 1, j, false);

		if (str[k] == '|')
		{
			if (isTrue == true) ans += lT * rF + lF * rT + lT * rT;
			else ans += lF * rF;
		}
		else if (str[k] == '&')
		{
			if (isTrue == true) ans += lT * rT;
			else ans += lT * rF + lF * rT + lF * rF;
		}
		else if (str[k] == '^')
		{
			if (isTrue == true) ans += lT * rF + lF * rT;
			else ans += lF * rF + lT * rT;
		}
	}
	return DP[key] = ans;
}

void solve()
{
	string str;
	cin >> str;
	cout << maxWays(str, 0, str.length() - 1, true);
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
