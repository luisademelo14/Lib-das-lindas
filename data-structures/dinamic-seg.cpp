#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
 
using namespace std;
 
struct tree 
{
	int sum, esq, dir;
};
 
vector<tree> st, lazy;
int op, a, b, c, n, q, arr[MAXN];
 
int novo(int val = 0)
{
	tree r = {val, -1, -1};
	st.push_back(r);
	lazy.push_back(r);
	return st.size() - 1;
}
 
void push(int idx, int i, int j)
{
	if (lazy[idx].sum == 0) return;
	st[idx].sum += (j-i+1)*lazy[idx].sum;
	if (i != j)
	{
		if (lazy[idx].esq == -1) lazy[idx].esq = novo();
		if (lazy[idx].dir == -1) lazy[idx].dir = novo();
		lazy[st[idx].esq].sum += lazy[idx].sum;
		lazy[st[idx].dir].sum += lazy[idx].sum;
	}

	lazy[idx].sum = 0;
}
 
void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = {arr[i], -1, -1};
		return;
	}
	int mid = (i+j)/2;
	if (st[idx].esq == -1) st[idx].esq = novo();
	if (st[idx].dir == -1) st[idx].dir = novo();
	build(st[idx].esq, i, mid);
	build(st[idx].dir, mid+1, j);
	st[idx].sum = st[st[idx].esq].sum + st[st[idx].dir].sum;
}
 
//void update(int idx, int i, int j, int pos, tree val) //point update
//{
//	if (i == j)
//	{
//		st[idx] = val;
//		return;
//	}
//	if (st[idx].esq == -1) st[idx].esq = novo();
//	if (st[idx].dir == -1) st[idx].dir = novo();
//	int mid = (i+j)/2;
//	if (pos <= mid) update(st[idx].esq, i, mid, pos, val);
//	else update(st[idx].dir, mid+1, j, pos, val);
//	st[idx].sum = merge(st[st[idx].esq], st[st[idx].dir]).sum;
//}
 
void update(int idx, int i, int j, int l, int r, tree val) //range update
{
	if (i > r || j < l) return;
	push(idx, i, j);
	if (i >= l && j <= r)
	{
		lazy[idx].sum = val.sum;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)/2;
	if (st[idx].esq == -1) st[idx].esq = novo();
	if (st[idx].dir == -1) st[idx].dir = novo();
	update(st[idx].esq, i, mid, l, r, val);
	update(st[idx].dir, mid+1, j, l, r, val);
	st[idx].sum = st[st[idx].esq].sum + st[st[idx].dir].sum;
}
 
int query(int idx, int i, int j, int l, int r)
{
	if (i > r || j < l) return 0/*empty*/;
	push(idx, i, j);
	if (i >= l && j <= r) return st[idx].sum;
	if (st[idx].esq == -1) st[idx].esq = novo();
	if (st[idx].dir == -1) st[idx].dir = novo();
	int mid = (i+j)/2;
	int x = query(st[idx].esq, i, mid, l, r);
	int y = query(st[idx].dir, mid+1, j, l, r);
	return x+y;
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	novo();	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(0, 1, n);
	while (q--)
	{
		cin >> op >> a;
		if (op == 1 && cin >> b >> c) update(0, 1, n, a, b, {c, -1, -1});
		else cout << query(0, 1, n, a, a) << endl;
	}
}
