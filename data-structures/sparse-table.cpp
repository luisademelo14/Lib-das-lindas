/*
	initialize table[i][0] with the a[i] value.  
 	query on interval(l, r)
 */

void build()
{
	for (int i = 1; i < 19; i++)
		for (int j = 1; j <= n; j++)
			tab[j][i] = max(tab[j][i-1], tab[j+(1<<(i-1))][i-1]);
}

int intervalo(int l, int r)
{
	return max(tab[l][maior[r-l+1]], tab[r-(1<<maior[r-l+1])][maior[r-l+1]]);
}
