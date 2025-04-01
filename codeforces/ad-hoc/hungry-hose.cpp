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

int t, n, tot;

int32_t main()
{_
	cin >> t;
	while (t--)
	{
		cin >> n >> tot;
		vector<ii> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i].first;
		for (int i = 0; i < n; i++)
			cin >> v[i].second;

		int curr = 0, resp = 0, tempo = 0;
		sort(all(v));
		priority_queue<int> pq;
		for (int i = 0; i < n; i++)
		{
			tempo += v[i].second;
			pq.push(v[i].second);
			curr++;
			while (tempo + v[i].first > tot && !pq.empty())
			{
				curr--;
				tempo -= pq.top();
				pq.pop();
			}

			if (tempo + v[i].first <= tot) resp = max(resp, curr);
		}

		cout << resp << endl;
	}
}
