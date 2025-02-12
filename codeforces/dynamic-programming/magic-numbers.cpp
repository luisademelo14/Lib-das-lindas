#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

/*
problem: find how many numbers have d only in even positions and is divisible by m in range[a, b]
solution: digit dp
 */

int m, d, a, b, dp[2001][2000][1<<3];
string l, r;

int f(int idx, int mod, int menor, int maior, int nulo)
{
	if (idx == -1) return mod == 0;
	return dp[idx][mod][menor*4 + maior*2 + nulo];
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> d >> l >> r;

	for (int mod = 0; mod < m; mod++)
		for (int mask = 0; mask < 8; mask++)
			dp[l.size()][mod][mask] = (mod == 0);

	int base = 1;
	for (int idx = l.size()-1; idx >= 0; idx--)
	{
		l[idx] -='0';
		r[idx] -='0';
		for (int mod = m-1; mod >= 0; mod--)
		{
			for (int mask = 0; mask < (1<<3); mask++)
			{
				int menor = ((mask&4)!=0), maior = ((mask&2)!=0), nulo = ((mask&1)!=0);
				if (nulo && mod) continue;
				if (idx&1)
				{
					if (maior && d > r[idx]) continue; 
					if (menor && d < l[idx]) continue;
					dp[idx][mod][mask] = f(idx+1, (mod*10 + d)%m, menor&(d==l[idx]), maior&(d==r[idx]), nulo&(d==0));
				}
				else
				{
					for (int i = (menor ? l[idx] : 0); i <= (maior ? r[idx] : 9); i++)
					{
						if (!d && nulo);
						else if (i == d) continue;
						dp[idx][mod][mask] = (dp[idx][mod][mask] + f(idx+1, (mod*10 + i)%m, menor&(i==l[idx]), maior&(i==r[idx]), nulo&(i==0))) % MOD;
					}
				}

			}
		}
	}
	cout << f(0, 0, 1, 1, 1) << endl;
}
