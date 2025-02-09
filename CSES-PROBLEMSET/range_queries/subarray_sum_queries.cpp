#include <bits/stdc++.h>
 
#define MAXN 200100
 
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
struct t{
	ll pre, suf, tot, ans;
};
 
t a[4*MAXN];
ll v[MAXN];
 
void build(int node, int i, int j) {
	if (i == j) {
		a[node].pre = a[node].suf = a[node].ans = max(0ll, v[i]);
		a[node].tot = v[i];
	}
	else {
		int m = (i+j)/2;
		build(2*node, i, m);
		build(2*node+1, m+1, j);
		a[node].pre = max(a[2*node].pre, a[2*node].tot + a[2*node+1].pre);
		a[node].suf = max(a[2*node].suf + a[2*node+1].tot, a[2*node+1].suf);
		a[node].tot = a[2*node].tot + a[2*node+1].tot;
		a[node].ans = max({a[node].pre, a[node].suf, a[2*node].ans, a[2*node+1].ans, a[2*node].suf + a[2*node+1].pre});
	}
}
 
void upd(int node, int i, int j, int pos) {
	if (i == j) {
		a[node].pre = a[node].suf = a[node].ans = max(0ll, v[i]);
		a[node].tot = v[i];
	}
	else {
		int m = (i+j)/2;
		if (pos <= m) upd(2*node, i, m, pos);
		else upd(2*node+1, m+1, j, pos);
		a[node].pre = max(a[2*node].pre, a[2*node].tot + a[2*node+1].pre);
		a[node].suf = max(a[2*node].suf + a[2*node+1].tot, a[2*node+1].suf);
		a[node].tot = a[2*node].tot + a[2*node+1].tot;
		a[node].ans = max({a[node].pre, a[node].suf, a[2*node].ans, a[2*node+1].ans, a[2*node].suf + a[2*node+1].pre});
	}
}
 
void solve(){ 
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> v[i];
	build(1, 1, n);
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x] = y;
		upd(1, 1, n, x);
		cout << a[1].ans << '\n';
	}
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
