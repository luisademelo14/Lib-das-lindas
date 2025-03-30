#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

/*
problem: given n circles, find if there is an area inside the circles that doesnt contain circles. 
solution: 
 
 */

struct tpoint
{
    double x, y;

    tpoint operator +(tpoint q) const
    {
        return {x + q.x, y + q.y};
    }
    tpoint operator -(tpoint q) const
    {
        return {x - q.x, y - q.y};
    }

    bool operator<(const tpoint& q) const {
        if(x != q.x) return x<q.x;
        return y<q.y;
    }
    double operator ~() const
    {
        return x*x + y*y;
    }
    double operator *(tpoint q) const
    {
        return (x*q.x + y*q.y);
    }
    double operator ^(tpoint q) const
    {
        return (x*q.y - y*q.x);
    }
};

int n, r[MAXN];
tpoint center[MAXN];
vector<tpoint> p; 

int32_t main()
{_
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> center[i].x >> center[i].y >> r[i];
		for (int j = 1; j < i; j++)
		{
			int dist = ~(center[i]-center[j]);
			if ((r[i]+r[j])*(r[i]+r[j]) > dist) continue;
			

		}
	}
}
