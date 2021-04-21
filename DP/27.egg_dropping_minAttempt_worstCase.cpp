/*
Input: 3 5
Ouput: 3
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

int minAttempts(int eggs, int floors)
{
	if (eggs == 1)
		return floors;
	if (floors == 0 || floors == 1)
		return floors;

	if (DP[eggs][floors] != -1)
		return DP[eggs][floors];
	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++)
	{
		int temp = 1 + max(minAttempts(eggs - 1, k - 1), minAttempts(eggs, floors - k));
		mn = min(mn, temp);
	}

	return DP[eggs][floors] = mn;
}

void solve()
{
	int eggs, floors;
	cin >> eggs >> floors;
	cout << minAttempts(eggs, floors);
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
