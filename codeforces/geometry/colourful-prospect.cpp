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
#define EPS 1e-9
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

/*
problem: given three circles return how many components there are
solution: circle-circle intersection
 
 */

int intersection(int r1, int x1, int y1, int r2, int x2, int y2)
{
	//circle 1 in origin
	if (r1 > r2) swap(r1, r2), swap(x1, x2), swap(y1, y2);
	x2 -= x1;
	y2 -= y1;


	int c = x2*x2 + y2*y2 + r1*r1 - r2*r2; 
	int r = r1, a = -2*x2, b = -2*y2;// c = x2*x2 + y2+y2 + r1*r1 - r2*r2; // raio + reta

	//double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);
	//cout << c*c/(a*a + b*b) << endl;
	if (c*c >= r*r*(a*a+b*b))
		return 0;
	else if (x1 + r1 <= x2 + r2 && x1 - r1 >= x2 - r2 && y1 + r1 <= y2 + r2 && y1 - r1 <= y2 - r2)
		return 0;
	else
		return 1;

//	else {
//		double d = r*r - c*c/(a*a+b*b);
//		double mult = sqrt (d / (a*a+b*b));
//		double ax, ay, bx, by;
//		ax = x0 + b * mult;
//		bx = x0 - b * mult;
//		ay = y0 - a * mult;
//		by = y0 + a * mult;
//		puts ("2 points");
//		cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
//	}
}

int32_t main()
{_
	int qtd = 0, n, r[3], x[3], y[3];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
		for (int j = 0; j < i; j++)
			qtd += intersection(r[i], x[i], y[i], r[j], x[j], y[j]);
		cout << qtd << endl;
	}

	if (!qtd) cout << n + 1 << endl;
	else if (qtd <= 1) cout << n + 2 << endl;
	else if (qtd <= 2) cout << n + 3 << endl;
	else cout << n + 5 << endl;
}
