#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(2e3 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int)(1e9 + 7)
#define BASE 37
#define MAXL 20
#define INF (int)(1LL<<30)
#define PI 3.14159265359
#define EPS (1e-9)
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

/*
problem: find all the edges that when taken out, make the graph not a scc anymore
solution: n*(n + m) take each vertice out of the graph and see if the remaining scc have 0 in-degree
 */

int k, n, m, a, b, flag[MAXN], grau[MAXN], vis[MAXN], comp[MAXN];
vector<int> grafo[MAXN], rev[MAXN];
stack<int> pilha;
vector<ii> resp;

void f(int u, int prob)
{
	vis[u] = 1;
	for (int v : grafo[u])
		if (!vis[v] && u != prob) f(v, prob);
	pilha.push(u);
}

void dfs(int u, int k, int prob)
{
	comp[u] = k;
	for (int v : rev[u])
		if (!comp[v] && v != prob) dfs(v, k, prob);
}

int32_t main()
{_
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		grafo[a].push_back(b);
		rev[b].push_back(a);
	}

	for (int d = n; d >= 1; d--)
	{
		if (grafo[d].size() == 1)
		{
			resp.push_back({d, grafo[d][0]});
			continue;
		}
		memset(vis, 0, sizeof vis);
		memset(grau, 0, sizeof grau);
		memset(comp, 0, sizeof comp);
		memset(flag, 0, sizeof flag);
		for (int i = 1; i <= n; i++) if (!vis[i]) f(i, d);

		k = 0;
		while (!pilha.empty())
		{
			int u = pilha.top(); pilha.pop();
			if (comp[u]) continue;
			comp[u] = ++k;
			dfs(u, k, d);
		}

		for (int i = 1; i <= n; i++) 
			if (i != d)
				for (int j : grafo[i])
					if (comp[j] != comp[i]) grau[comp[j]]++;

		for (int v : grafo[d])
			flag[comp[v]]++;

		for (int v : grafo[d])
		{
			if (grau[comp[v]] == 0 && flag[comp[v]] == 1)
				resp.push_back({d, v});
		}
	}

	cout << resp.size() << endl;
	for (auto[a, b] : resp)
		cout << a << ' ' << b << endl;
}
