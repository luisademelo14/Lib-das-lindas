#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (5e3 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int n, m, dist[MAXN], val[MAXN][210], dp[MAXN][210];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++) 
	{
		cin >> dist[i+1];
		dist[i+1] += dist[i];
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> val[i][j];

	for (int q = 1; q <= m; q++)
		for (int i = 1; i <= n; i++)
		{
			for (int q2 = 1; q2 < q; q2++)
				for (int j = i; j <= n; j++)
				   dp[i][q] = max(dp[i][q], dp[j][q2] + val[j][q2] - (dist[j] - dist[i]));	
			printf("dp[%d][%d] = %d\n", i, q, dp[i][q]);
		}
	
	int resp = 0;
	for (int i = 1; i <= n; i++)
		resp = max(resp, dp[i][m]);
	cout << resp << endl;
}
