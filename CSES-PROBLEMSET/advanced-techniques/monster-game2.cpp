//#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#define int long long
#define MAXN (int) (1e6 + 10)
#define aint(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

//li-chao

struct Func
{
	int a, b;
	int val(int x) 
	{
		return a*x + b;
	}	
};
int n, ini, s[MAXN], f[MAXN], dp[MAXN], tam, idx;
Func st[MAXN<<2];

void build(int idx = 1, int i = 0, int j = MAXN-1)
{
	if (i == j)
	{
		st[idx] = {(int)1e9, (int)1e15};
		return;
	}
	int mid = (i+j)>>1;
	st[idx] = {(int)1e9, (int)1e15};
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
}

void update(Func curr, int idx = 1, int i = 0, int j = MAXN-1)
{
	int mid = (i+j)>>1;
	int meio = st[idx].val(mid) > curr.val(mid);
	int ini = st[idx].val(i) > curr.val(i);
	if (meio) swap(st[idx], curr);
	if (j-i <= 1) return;
	if (ini != meio) update(curr, esq(idx), i, mid);
	else update(curr, dir(idx), mid+1, j);
}

int query(int pos, int idx = 1, int i = 0, int j = MAXN-1)
{
	if (j-i <= 0) 
		return st[idx].val(pos);
	int mid = (i+j)>>1;
	if (pos <= mid) return min(st[idx].val(pos), query(pos, esq(idx), i, mid));
	return min(st[idx].val(pos), query(pos, dir(idx), mid+1, j));
}


int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> f[0];
	build();
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i];
	}

	update({f[0], 0});
	for (int i = 1; i <= n; i++)
	{
		dp[i] = query(s[i]);
		update({f[i], dp[i]});
	}

	cout << dp[n] << endl;
}

