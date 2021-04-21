/*
Input:
phqtrnilf
ilthnqrpf

Output:
Not Scrambled
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

unordered_map<string, bool> ump;

bool check(string a, string b)
{
	if (a.compare(b) == 0)
		return true;

	string key = a;
	key.push_back('#');
	key.append(b);
	if (ump.find(key) != ump.end())
		return ump[key];

	int n = a.length();
	for (int k = 1; k <= n - 1; k++)
	{
		if ((check(a.substr(0, k), b.substr(n - k)) && check(a.substr(k), b.substr(0, n - k))) \
		        || \
		        (check(a.substr(0, k), b.substr(0, k)) && check(a.substr(k), b.substr(k))))
			return ump[key] = true;
	}
	return ump[key] = false;
}

void solve()
{
	string a, b;
	cin >> a >> b;
	if (a.length() != b.length())
		cout << "Not Scrambled";
	else if (a == "" && b == "")
		cout << "Scrambled";
	else if (a == "" || b == "")
		cout << "Not Scrambled";
	else if (check(a, b))
		cout << "Scrambled";
	else
		cout << "Not Scrambled";
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
