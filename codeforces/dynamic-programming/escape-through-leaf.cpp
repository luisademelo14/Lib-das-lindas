//#include <bits/stdc++.h>
#include <iostream> 
#include <vector>
#define int long long
#define MAXN (int) (2e2 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

struct Func
{
	int a, b;
	int val(int x)
	{
		return a*x + b;
	}
};
Func st[MAXN<<3];
int n, a[MAXN], b[MAXN], dp[MAXN];
vector<int> v, grafo[MAXN];
ii pos[MAXN];

void build(int idx = 1, int i = -MAXN+1, int j = MAXN-1)
{
	if (i == j)
	{
		st[idx] = {(int)0, (int)1e15};
		return;
	}
	int mid = (i+j)/2;
	st[idx] = {(int)0, (int)1e15};
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
}

void add(Func curr, int idx, int i, int j)
{
	int mid = (i+j)/2;
	int meio = st[idx].val(mid) > curr.val(mid);
	int ini = st[idx].val(i) > curr.val(i);
	if (meio) swap(st[idx], curr);
	if (j-i <= 1) return;
	if (ini != meio) add(curr, esq(idx), i, mid);
	else add(curr, dir(idx), mid+1, j);
}

int query(int pos, int idx = 1, int i = -MAXN+1, int j = MAXN-1)
{
	if (j-i <= 0) 
		return st[idx].val(pos);
	int mid = (i+j)/2;
	if (pos <= mid) return min(st[idx].val(pos), query(pos, esq(idx), i, mid));
	return min(st[idx].val(pos), query(pos, dir(idx), mid+1, j));
}

void update(Func curr, int l, int r, int idx = 1, int i = -MAXN+1, int j = MAXN-1)
{
	if (i > r || j < l) return;
	if (i >= l && j <= r)
	{
		add(curr, idx, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(curr, l, r, esq(idx), i, mid);
	update(curr, l, r, dir(idx), mid+1, j);
}

void build_dfs(int u, int p = 0)
{	
	v.push_back(u);
	pos[u].first = v.size()-1;
	for (int v: grafo[u])	
		if (v != p) build_dfs(v, u);
	v.push_back(u);
	pos[u].second = v.size()-1;
}

int dfs(int u, int p = 0)
{
	for (int v : grafo[u])
		if (v != p) dfs(v, u);

	dp[u] = 1e9;
	for (int i = pos[u].first+1; i < pos[u].second; i++)
	{
		dp[u] = min(dp[u], query(a[v[i]]));
		update({b[u], dp[u]}, pos[u].first, pos[u].second);
	}
	printf("dp[%d] = %d\n", u, dp[u]);
	return dp[u] = (dp[u]==1e9 ? 0 : dp[u]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}

	build();
	build_dfs(1);
	dfs(1);
	for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
	cout << endl;
}
