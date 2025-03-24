#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (100)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int q, grau[MAXN], dist[MAXN], last[MAXN], arr[MAXN], n, m, a, b, c;
vector<ii> grafo[MAXN];
vector<int> path;

int dfs(int u)
{
	if (dist[u]) return dist[u];
	dist[u] = arr[u];
	for (auto[v, w] : grafo[u])
	{
		int curr = dfs(v) + arr[u] + w;
		if (dist[u] > curr) continue; 
		if (dist[u] == curr) q = 1;
		last[u] = v;
		dist[u] = max(dist[u], curr); 
	}

	return dist[u];
}

int32_t main()
{_
	while (cin >> n >> m)
	{
		char coma;
		for (int i = 1; i <= n; i++)
		{
			grau[i] = 0;
			cin >> arr[i];
			if (i != n) cin >> coma;
		}

		while (m--)
		{
			cin >> a >> b >> c;
			grafo[a+1].push_back({b+1, c});
			grau[b+1]++;
		}

		int maior = 0, quant = 0, u = 0;
		for (int i = 1; i <= n; i++)
		{
			memset(dist, 0, sizeof dist);
			if (grau[i]) continue;
			q = 0;
			path.clear();
			int curr = dfs(i);
			if (maior > curr) continue;
			else if (maior == curr) quant = 1;
			else quant = q;
			maior = curr;
			u = i;
		}

		cout << maior;
		if (quant) cout << ",M" << endl;
		else
		{
			while (u)
			{
				cout << "," << u-1;
				u = last[u];
			}
			cout << endl;
		}
		path.clear();
		for (int i = 1; i <= n; i++) 
		{
			grafo[i].clear();
			last[i] = 0;
			grau[i] = 0;
		}
	}
}
