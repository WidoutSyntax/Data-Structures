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

struct Trie
{
	bool isEnd;
	unordered_map<char, Trie*> mp;

	Trie()
	{
		isEnd = false;
	}
};

Trie *root;

void insert(string str)
{
	Trie *curr = root;
	for (char ch : str)
	{
		if (curr->mp.find(ch) == curr->mp.end())
			curr->mp[ch] = new Trie();
		curr = curr->mp[ch];
	}

	curr->isEnd = true;
}

bool search(string str)
{
	Trie *curr = root;
	for (char ch : str)
	{
		if (curr->mp.find(ch) == curr->mp.end())
			return false;
		curr = curr->mp[ch];
	}

	if (curr->isEnd)
		return true;
	return false;
}

void solve()
{
	root = new Trie();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		insert(str);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		string str;
		cin >> str;
		if (search(str)) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
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
