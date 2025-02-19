#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

/*
problem: given an array of n slimes, each with size a[i] and q queries, each with x[i], how many slimes can you eat?
solution: find the first number with msb equal to msb(x), then make the xor and do it again
bb + sparce table to find it and this is done log times
 */

int n, arr[MAXN], psa[MAXN], q, t, tab[MAXN][20], maior[MAXN];

int intervalo(int l, int r)
{
	return max(tab[l][maior[r-l+1]], tab[r-(1<<maior[r-l+1])][maior[r-l+1]]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	int base = 0;
	for (int i = 0; i < MAXN; i++)
	{
		if (1<<(base+1) <= i) base++;
		maior[i] = base;
	}

	while (t--)
	{
		cin >> n >> q;
		for (int i = 1; i <= n; i++) 
			cin >> arr[i];

		for (int i = n; i >= 1; i--)
		{
			psa[i] ^= psa[i+1]^arr[i];
			for (int j = 30; j >= 0; j--)
				if (arr[i] >= (1<<j))
				{
					tab[i][0] = j;
					break;
				}
		}

		for (int i = 1; i < 19; i++)
			for (int j = 1; j <= n; j++)
				tab[j][i] = max(tab[j][i-1], tab[j+(1<<(i-1))][i-1]);

		while (q--)
		{
			int y, x, bit, idx = n;
			cin >> y;
			x = y;

			for (int i = 30; i >= 0; i--) if (x >= (1<<i)) {bit = i; break;}
			while (idx > 0 && arr[idx] <= x) //log
			{
				if (tab[idx][0] == bit) 
				{
					x = y^psa[idx];
					for (int i = bit; i >= 0; i--) if (x >= (1<<i)) {bit = i; break;}
					idx--;
				}
				else
				{
					int val, ini = 1, meio, fim = idx-1;
					while (ini <= fim) //log
					{
						meio = (ini+fim)/2;
						if (intervalo(meio, idx) >= bit) ini = meio + 1;
						else fim = meio - 1;
					}

					idx = fim;
					x = y^psa[idx+1];
				}
			}
			cout << n-max(0ll, idx) << ' ';
		}
		cout << endl;
		for (int i = 1; i <= n; i++) arr[i] = tab[i][0] = psa[i] = 0;
	}
}

