#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)

using namespace std;

int t, n, arr[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin >> t;
	while (t--)
	{
		int n = uniform_int_distribution<int>(1, 8)(rng);
		for (int i = 1; i <= n; i++)
			cout << uniform_int_distribution<int>(1, 100)(rng) << ' ';
		cout << endl;
	}
}
