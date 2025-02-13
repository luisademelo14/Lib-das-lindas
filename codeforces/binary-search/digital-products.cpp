//#include <bits/stdc++.h>
#include <set>
#include <iostream>
#include <map>
#define int long long
#define MAXN (int) (18)
#define INF (int) (1e18) 
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define coisa tuple<int, int, int, int, int, int>

using namespace std;

/*
problem: find the number of diferent multiplications of the digits of numbers in range [1, d]
solve: brute all multiplications (54**4) and for each find the smallest number then binary search for n
 */

int t, n;
set<int> s;

int f(int num)
{
	int base = 1, resp = 0, idx = 0;
	for (int i = 9; i >= 2; i--)
	{
		while (num%i == 0 && idx < 19)
		{
			resp += base*i;
			base *= 10;
			num /= i;
			idx++;
		}
	}
	if (idx > 18) return 0;
	return resp;	
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	s.insert(10);
	for (int i = 0, d = 1; i <= 3*MAXN && d <= INF; i++, d*=2)
		for (int j = 0, c = 1; j <= 2*MAXN && c*d <= INF; j++, c*=3)
			for (int k = 0, b = 1; k <= MAXN && b*c*d <= INF; k++, b*=5)
				for (int l = 0, a = 1; l <= MAXN && a*b*c*d <= INF; l++, a*=7)
					s.insert(f(a*b*c*d));

	cin >> t;
	while (t--)
	{
		cin >> n;
		auto it = s.upper_bound(n);
		cout << distance(s.begin(), it) << endl;
	}
}
