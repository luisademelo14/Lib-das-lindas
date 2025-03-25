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

int32_t main()
{_
	double r, a, b, c; // raio + reta  
	double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
	if (c*c > r*r*(a*a+b*b)+EPS)
		puts ("no points");
	else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
		puts ("1 point");
		cout << x0 << ' ' << y0 << '\n';
	}
	else {
		double d = r*r - c*c/(a*a+b*b);
		double mult = sqrt (d / (a*a+b*b));
		double ax, ay, bx, by;
		ax = x0 + b * mult;
		bx = x0 - b * mult;
		ay = y0 - a * mult;
		by = y0 + a * mult;
		puts ("2 points");
		cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
	}
}
