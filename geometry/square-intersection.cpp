/*
problem: check if two squares intersect (one parallel to x and other 45 degrees)
solution: check if any two segments intersect or if one contains the other
 */

tpoint p[4], pp[4]; 
int n;
int range(tpoint p, tpoint l, tpoint r)
{
	return (min(l.x, r.x) <= p.x && p.x <= max(l.x, r.x) && min(l.y, r.y) <= p.y && p.y <= max(l.y, r.y));
}

int inter(tpoint i, tpoint j, tpoint l, tpoint r, int flag)
{
	if (j.y < i.y) swap(i, j);
	int cross1 = (l-i)^(r-i);
 	int cross2 = (l-j)^(r-j);
	int cross3 = (i-l)^(j-l);
	int cross4 = (i-r)^(j-r);
	if (!cross1 && range(i, l, r)) return 1; 
	if (!cross2 && range(j, l, r)) return flag; //only count lowest extremity
	if (!cross3 && range(l, i, j)) return 1;
	if (!cross4 && range(r, i, j)) return 1;

	return ((cross1>0)^(cross2>0))&&(((cross3>0)^(cross4>0)));	
}

int inside(tpoint d)
{
	int qtd = 0, ok = 0;
	for (int i = 0; i < n; i++) p[i] = p[i] - d;
	for (int i = 0, j=n-1; i < n; i++, j = (i-1+n)%n)
	{
		if (!(p[i]^p[j]) && range({0, 0}, p[i], p[j])) ok = 1; //boundary
		if (p[i].y == 0 && p[j].y == 0) continue;
		qtd += inter(p[i], p[j], {INF, 0}, {0, 0}, 0);
	}
	for (int i = 0; i < n; i++) p[i] = p[i] + d;
	return (ok ? 2 : (qtd&1));
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
	for (int i = 0; i < 4; i++) cin >> pp[i].x >> pp[i].y;
	n = 4;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (inter(p[i], p[(i-1+n)%n], pp[j], pp[(j-1+n)%n], 1)) //if any two segments have intersection 
			{
				cout << "YES" << endl;
				return 0;
			}

	int ok = 1;
	for (int i = 0; i < n; i++)
		ok &= inside(pp[i]); //if all points are inside p
	swap(p, pp);
	if (ok)
	{
		cout << "YES" << endl;
		return 0;
	}

	ok = 1;
	for (int i = 0; i < n; i++)
		ok &= inside(pp[i]); //if all point are inside pp

	if (ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}
