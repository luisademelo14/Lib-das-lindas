#include <bits/stdc++.h>
#define MAXN 200100
#define INF 1e18
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
ll a[4*MAXN], lz[4*MAXN], v[MAXN], w[MAXN];
 
void build(int node, int i, int j) {
	if (i == j) a[node] = w[i];
	else {
		int m = (i+j)/2;
		build(2*node, i, m), build(2*node+1, m+1, j);
		a[node] = max(a[2*node], a[2*node+1]);
	}
}
 
void push(int node, int i, int j) {
	a[node] += lz[node];
	if (i != j) {
		lz[2*node] += lz[node];
		lz[2*node+1] += lz[node];
	}
	lz[node] = 0;
}
 
void upd(int node, int i, int j, int ini, int fim, int val) {
	push(node, i, j);
	if (j < ini || i > fim) return;
	if (ini <= i && j <= fim) {
		lz[node] += val;
		push(node, i, j);
	}
	else {
		int m = (i+j)/2;
		upd(2*node, i, m, ini, fim, val);
		upd(2*node+1, m+1, j, ini, fim, val);
		a[node] = max(a[2*node], a[2*node+1]);
	}
}
 
ll query(int node, int i, int j, int ini, int fim) {
	push(node, i, j);
	if (j < ini || i > fim) return -INF;
	if (ini <= i && j <= fim) return a[node];
	else {
		int m = (i+j)/2;
		return max(query(2*node, i, m, ini, fim), query(2*node+1, m+1, j, ini, fim));
	}
}
 
void solve () {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		w[i] = v[i] + w[i-1];
	}
	build(1, 0, n);
	int tipo, a, b;
	for (int i = 0; i < q; i++) {
		cin >> tipo >> a >> b;
		if (tipo == 1) {
			upd(1, 0, n, a, n, b - v[a]);
			v[a] = b;
		}
		if (tipo == 2) 
			cout << max(query(1, 0, n, a, b) - query(1, 0, n, a-1, a-1), 0ll) << '\n';
	}
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int t;
    //cin >> t;
    //while(t--)
    //    solve();
    solve();
    return 0;
}
