#include <bits/stdc++.h>
#define int long long
#define MAXN (int)(1e6 + 10)
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

int k, n, m, a, b, vis[MAXN], comp[MAXN];
vector<int> grafo[MAXN], rev[MAXN];
stack<int> pilha;

void f(int u)
{
	vis[u] = 1;
	for (int v : grafo[u])
		if (!vis[v]) f(v);
	pilha.push(u);
}

void dfs(int u, int k)
{
	comp[u] = k;
	for (int v : rev[u])
		if (!comp[v]) dfs(v, k);
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

	for (int i = 1; i <= n; i++)
		if (!vis[i]) build(i);

	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) if (!vis[i]) f(i);

	while (!pilha.empty())
	{
		int u = pilha.top(); pilha.pop();
		if (comp[u]) continue;
		comp[u] = ++k;
		dfs(u, k);
	}
}
