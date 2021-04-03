#include<bits/stdc++.h>
using namespace std;

bool check(int i, int j, vector<vector<int>> &mat, vector<vector<bool>> &vis, int n, int m)
{
    if (i == n && j == m) return true;
    if (i > n || j > m) return false;
    if (i <= 0 || j <= 0) return false;
    if (mat[i][j] == 0) return false;
    if (vis[i][j]) return false;
    vis[i][j] = true;
    if (check(i + 1, j, mat, vis, n, m)) return true;
    if (check(i, j + 1, mat, vis, n, m)) return true;
    if (check(i - 1, j, mat, vis, n, m)) return true;
    if (check(i, j - 1, mat, vis, n, m)) return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n + 1, vector<int>(m + 1, -1));
    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i + 1][j + 1];
    if (check(1, 1, mat, vis, n, m)) cout << "Yes";
    else cout << "No";
    return 0;
}