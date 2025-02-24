#include <bits/stdc++.h>
#define PICOS 1
#define VALES 0
#define int long long
#define MAXN (int) (3e3 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define INF (int) (1e18)

using namespace std;
struct Func
{
	int a, b;
	int val(int x)
	{
		return a*x + b;
	}
};

int n, m, pref[MAXN], arr[MAXN], peak[MAXN][MAXN], vale[MAXN][MAXN], suff[MAXN], r[MAXN], l[MAXN];

//deque<Func> retas[2];
Func st[2][MAXN<<2];

void build(int idx = 1, int i = 0, int j = MAXN-1)
{
	if (i == j)
	{
		st[1][idx] = st[0][idx] = {(int)1e9, (int)1e15};
		return;
	}
	int mid = (i+j)/2;
	st[1][idx] = st[0][idx] = {(int)1e9, (int)1e15};
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
}

void update(Func curr, int flag, int idx = 1, int i = 0, int j = MAXN-1)
{
	int mid = (i+j)/2;
	int meio = st[flag][idx].val(mid) > curr.val(mid);
	int ini = st[flag][idx].val(i) > curr.val(i);
	if (meio) swap(st[flag][idx], curr);
	if (j-i <= 1) return;
	if (ini != meio) update(curr, esq(idx), i, mid);
	else update(curr, dir(idx), mid+1, j);
}

int query(int pos, int flag, int idx = 1, int i = 0, int j = MAXN-1)
{
	if (j-i <= 0) 
		return st[flag][idx].val(pos);
	int mid = (i+j)/2;
	if (pos <= mid) return min(st[flag][idx].val(pos), query(pos, esq(idx), i, mid));
	return min(st[flag][idx].val(pos), query(pos, dir(idx), mid+1, j));
}

//void update(Func curr, int i)
//{
//	int tam = retas[i].size();
//	while (tam>1 && ((retas[i][tam-2].b-retas[i][tam-1].b)*(curr.a-retas[i][tam-2].a)) >= ((retas[i][tam-2].b-curr.b)*(retas[i][tam-1].a-retas[i][tam-2].a)))
//		retas[i].pop_back(), tam--;
// 
//	retas[i].push_back(curr);
//}
// 
//int query(int x, int i)
//{
//	while (retas[i].size()>1 && retas[i][0].val(x) >= retas[i][1].val(x))
//		retas[i].pop_front();
// 
//	return retas[i].front().val(x);
//}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pref[i] = pref[i-1] + arr[i];
		l[i] = l[i-1] + arr[i]*i;
		r[i] = r[i-1] + arr[i]*(n-i);
	}

	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++) 
			peak[i][j] = vale[i][j] = INF;
	peak[0][0] = 0;

	for (int s = 1; s <= m; s++)
	{
		build();
		update({0, 0}, PICOS);
	cout << "a" << endl;
		for (int i = 1; i <= n; i++)
		{
//			for (int j = 1; j < i; j++) //ultimo peak
//			{
//				vale[s][i] = min(vale[s][i], peak[s-1][j] + r[i-1] - r[j] - (n-i+1)*(pref[i-1] - pref[j]));
//			}
//
			vale[s][i] = r[i] - n*pref[i] + i*pref[i] - query(i, PICOS);
			update({-pref[i], n*pref[i] - r[i] + peak[s-1][i]}, PICOS);

//			printf("vale[%lld][%lld] = %lld\n", s, i, vale[s][i]);

//			for (int j = 0; j < i; j++) //ultimo vale 
//			{
//				peak[s][i] = min(peak[s][i], vale[s][j] + l[i] - l[j] - (j)*(pref[i]-pref[j]));
//			}

			update({-i, vale[s][i] + i*pref[i] - l[i]}, VALES);
			peak[s][i] = l[i] + query(pref[i], VALES);

//			printf("pico[%lld][%lld] = %lld\n\n", s, i, peak[s][i]);
		}

//		retas[0].clear();
//		retas[1].clear();
	}	

	cout << min(vale[m][n], peak[m][n]) << endl;
}
