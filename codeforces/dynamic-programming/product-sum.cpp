//#include <bits/stdc++.h>
#include <iostream>
#define int long long
#define MAXN (int) (1e6 + 10)
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

	int operator ==(Func q) const{
		return a == q.a && b == q.b;
	}
};
Func st[MAXN<<3], vazio = {0, (int)-1e13};
int n, a[MAXN], dp[MAXN], pref[MAXN], sum[MAXN], resp;

//cht com lichao

void build(int idx = 1, int i = -MAXN+1, int j = MAXN-1)
{
	if (i == j)
	{
		st[idx] = vazio;
		return;
	}
	int mid = (i+j)>>1;
	st[idx] = vazio;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
}

void update(Func curr, int idx = 1, int i = -MAXN+1, int j = MAXN-1)
{
	int mid = (i+j)>>1;
	int meio = st[idx].val(mid) < curr.val(mid);
	int ini = st[idx].val(i) < curr.val(i);
	if (meio) swap(st[idx], curr);
	if (j-i <= 1) return;
	if (ini != meio) update(curr, esq(idx), i, mid);
	else update(curr, dir(idx), mid+1, j);
}

int query(int pos, int idx = 1, int i = -MAXN+1, int j = MAXN-1)
{
	if (j-i <= 0) 
		return st[idx].val(pos);
	int mid = (i+j)>>1;
	if (pos <= mid) return max(st[idx].val(pos), query(pos, esq(idx), i, mid));
	return max(st[idx].val(pos), query(pos, dir(idx), mid+1, j));
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		sum[i] = sum[i-1]+a[i];
		pref[i] = pref[i-1]+(a[i]*i);
	}

	build();
	resp = pref[n];
	for (int i = n; i >= 1; i--) //j > i
	{
		dp[i] = pref[n] - a[i]*i + sum[i] + query(a[i]);
		update({i, -sum[i]});
//		for (int j = i+1; j <= n; j++)
//		{
//			dp[i] = max(dp[i], a[i]*j - sum[j-1]);
//			printf("dp[%d][%d] = %d\n", i, j, pref[n] -a[i]*i + a[i]*j - sum[j-1] + sum[i-1]);
//		}
		resp = max(resp, dp[i]);
	}

	build();
	for (int i = 1; i <= n; i++)
	{
		dp[i] = pref[n] - a[i]*i + sum[i-1] + query(a[i]);
		update({i, -sum[i-1]});
//		cout << dp[i] << endl;
//		for (int j = 1; j < i; j++)
//		{
//			dp[i] = max(dp[i], pref[n] -a[i]*i + a[i]*j - sum[j-1] + sum[i-1]);
//			printf("dp[%d][%d] = %d\n", i, j, pref[n] -a[i]*i + a[i]*j - sum[j-1] + sum[i-1]);
//
//		}
		resp = max(resp, dp[i]);
	}
	cout << resp << endl;
	
}
