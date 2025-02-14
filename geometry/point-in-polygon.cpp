/*
problem: check if point is in simple polygon
solution: draw a line from p to {INF, 0} and check wether the number of intersections is odd
corner: only count lowest extremity of vertex intersections 
 */

tpoint p[MAXN], d;
int n, m;

int range(tpoint p, tpoint l, tpoint r)
{
	return (min(l.x, r.x) <= p.x && p.x <= max(l.x, r.x) && min(l.y, r.y) <= p.y && p.y <= max(l.y, r.y));
}

int inter(tpoint i, tpoint j, tpoint l, tpoint r)
{
	if (j.y < i.y) swap(i, j);
	int cross1 = (l-i)^(r-i);
 	int cross2 = (l-j)^(r-j);
	int cross3 = (i-l)^(j-l);
	int cross4 = (i-r)^(j-r);
	if (!cross1 && range(i, l, r)) return 1; 
	if (!cross2 && range(j, l, r)) return 0; //only count lowest extremity
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
		qtd += inter(p[i], p[j], {INF, 0}, {0, 0});
	}
	for (int i = 0; i < n; i++) p[i] = p[i] + d;
	return (ok ? 2 : (qtd&1));
}
