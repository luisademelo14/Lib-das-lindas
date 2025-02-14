/*
problem: check if two segments intersect
solution: cross product
corner: when there is one point lying on the other segment then check if the point is inside the range of the segment
 */

int range(tpoint p, tpoint l, tpoint r)
{
	return (min(l.x, r.x) <= p.x && p.x <= max(l.x, r.x) && min(l.y, r.y) <= p.y && p.y <= max(l.y, r.y));
}

int inter(tpoint i, tpoint j, tpoint l, tpoint r)
{
	int cross1 = (l-i)^(r-i);
 	int cross2 = (l-j)^(r-j);
	int cross3 = (i-l)^(j-l);
	int cross4 = (i-r)^(j-r);
	if (!cross1 && range(i, l, r)) return 1;
	if (!cross2 && range(j, l, r)) return 1;
	if (!cross3 && range(l, i, j)) return 1;
	if (!cross4 && range(r, i, j)) return 1;

	return ((cross1>0)^(cross2>0))&&(((cross3>0)^(cross4>0)));	
}
