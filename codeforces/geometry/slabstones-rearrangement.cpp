#include <bits/stdc++.h>
#define int unsigned long long
#define MAXN 1000 
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define INF (1ULL<<33)
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

/*
problem: given n rectancles with no intersection, what is the minimum area you can have by sliding them on x axis.
solution: brute or topo-sort
 
 
 */

struct tpoint
{
    int x, y;
};

int t, n, d, grau[MAXN], pos[MAXN];
pair<tpoint, tpoint> arr[MAXN];

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		vector<int> grafo[MAXN];
		memset(grau, 0, sizeof grau);
		memset(arr, 0, sizeof arr);
		cin >> n >> d;
		int mmx = 0, mx = INF, my = INF, mmy = 0;
		for (int i = 1; i <= n; i++)
		{
			int a1, a2, b1, b2;
			cin >> a1 >> b1 >> a2 >> b2;
			arr[i] = {{a1, b1}, {a2, b2}};
			pos[i] = a2-a1;
			mx = min(mx, arr[i].first.x);
			mmx = max(mmx, arr[i].second.x);
			my = min(my, arr[i].first.y);
			mmy = max(mmy, arr[i].second.y);

			for (int j = 1; j < i; j++)
			{
				auto a = arr[i], b = arr[j];
				if (a.first.y >= b.second.y || b.first.y >= a.second.y) continue;
				if (a.first.x < b.first.x) grafo[i].push_back(j), grau[j]++;
				else grafo[j].push_back(i), grau[i]++;
			}
		}	

		int old = (mmx-mx), novo = 0;
		queue<int> fila;
		for (int i = 1; i <= n; i++)
			if (!grau[i]) fila.push(i);

		while (!fila.empty())
		{
			int u = fila.front(); fila.pop();
			novo = max(novo, pos[u]);
			for (int v : grafo[u])
			{
				if (!grau[v]) continue;
				grau[v]--;
				pos[v] = max(pos[v], pos[u] + arr[v].second.x - arr[v].first.x + d);
				if (!grau[v]) fila.push(v);
			}
		}

		if (old < novo) cout << 0 << endl;
		else cout << (int)(mmy - my)*(old - novo) << endl;
	}
}
