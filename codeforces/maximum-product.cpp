//#include <bits/stdc++.h>
#include <map>
#include <iostream>
#include <deque>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define coisa tuple<int, int, int, int, int, int, int, int>

using namespace std;

int a, b, q[10][8];
deque<int> l, r;
map<coisa, int> last, dp;

int f(int idx, int dois, int tres, int cinco, int sete, int menor, int maior, int nulo)
{
	if (idx >= l.size()) return 1;
	coisa estado = {idx, dois, tres, cinco, sete, menor, maior, nulo};
	if (dp.find(estado) != dp.end()) return dp[estado];
	int resp = -1;
	for (int d = (menor ? l[idx] : 0); d <= (maior ? r[idx] : 9); d++)
	{
		int curr = ((nulo&(!d)) ? 1 : d)*f(idx+1, dois + q[d][2], tres + q[d][3], cinco + q[d][5], sete + q[d][7], menor&(d==l[idx]), maior&(d==r[idx]), nulo&(d==0));
		if (curr > resp)
		{
			resp = curr;
			last[estado] = d;
		}
	}

	return dp[estado] = resp;
}

void solve()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 1, g = 1, h = 1;
	while (a < l.size())
	{
		int dig = last[{a, b, c, d, e, f, g, h}];
		b += q[dig][2];
		c += q[dig][3];
		d += q[dig][5];
		e += q[dig][7];
		f &= (dig==l[a]);
		g &= (dig==r[a]);
		h &= (dig==0);
		a++;
		if (!h) cout << dig;
	}
	cout << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b;
	while (a)
	{
		l.push_front(a%10);
		a /= 10;
	}
	while (b)
	{
		r.push_front(b%10);
		b /= 10;
	}

	while (l.size() < r.size())
		l.push_front(0);

	int primos[] = {2, 3, 5, 7};
	for (int i = 1; i <= 9; i++)
	{
		for (int p : primos)
		{
			int x = i;
			while (x%p == 0)
			{
				q[i][p]++;
				x /= p;
			}
		}
	}

	f(0, 0, 0, 0, 0, 1, 1, 1);
	solve();
}
