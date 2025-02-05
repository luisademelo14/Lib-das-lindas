Func st[MAXN<<2];

void build(int idx = 1, int i = 0, int j = MAXN-1)
{
	if (i == j)
	{
		st[idx] = {(int)1e9, (int)1e15};
		return;
	}
	int mid = (i+j)>>1;
	st[idx] = {(int)1e9, (int)1e15};
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
}

void update(Func curr, int idx = 1, int i = 0, int j = MAXN-1)
{
	int mid = (i+j)>>1;
	int meio = st[idx].val(mid) > curr.val(mid);
	int ini = st[idx].val(i) > curr.val(i);
	if (meio) swap(st[idx], curr);
	if (j-i <= 1) return;
	if (ini != meio) update(curr, esq(idx), i, mid);
	else update(curr, dir(idx), mid+1, j);
}

int query(int pos, int idx = 1, int i = 0, int j = MAXN-1)
{
	if (j-i <= 0) 
		return st[idx].val(pos);
	int mid = (i+j)>>1;
	if (pos <= mid) return min(st[idx].val(pos), query(pos, esq(idx), i, mid));
	return min(st[idx].val(pos), query(pos, dir(idx), mid+1, j));
}
