#include <bits/stdc++.h>
#define double long long
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
    double operator ~() const 
    {
        return hypot(x, y);
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

struct Func
{
	int a, b;
	int val(int x)
	{
		return a*x + b;
	}
};

double triangle(tpoint a, tpoint b, tpoint c)
{
	return fabs((b-a)^(c-a));
}

double area(vector<tpoint> &v)
{
	if (v.size() < 3) return -1;
	v.push_back(v[0]);
	tpoint p = v[0];
	int resp = 0;
	for (int i = 2; i < v.size(); i++)
		resp = (resp + triangle(p, v[i], v[i-1]));
	return resp;
}

int32_t main()
{_
	int n;
	cin >> n;
	vector<tpoint> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].x >> v[i].y;
	}

	cout << area(v) << endl;
}
