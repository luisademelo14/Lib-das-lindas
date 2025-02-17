tree st[MAXN<<2], lazy[MAXN<<2];

tree merge(tree esq, tree dir)
{
	tree r;
	return r;
}

void push(int idx, int i, int j)
{
	if (lazy[idx] == 0);
	st[idx] /*operation*/ lazy[idx];
	if (i != j)
	{
		lazy[esq(idx)] /*operation*/ lazy[idx];
		lazy[dir(idx)] /*operation*/ lazy[idx];
	}

	lazy[idx] = 0;
}

void build(int idx, int i, int j)
{
	if (i == j)
	{
		st[idx] = /*initialize*/;
		return;
	}
	int mid = (i+j)/2;
	build(esq(idx), i, mid);
	build(dir(idx), mid+1, j);
	st[idx] = merge(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int pos, tree val) //point update
{
	if (i == j)
	{
		st[idx] = val;
		return;
	}
	int mid = (i+j)/2;
	if (pos <= mid) update(esq(idx), i, mid, pos, val);
	else update(dir(idx), mid+1, j, pos, val);
	st[idx] = merge(st[esq(idx)], st[dir(idx)]);
}

void update(int idx, int i, int j, int l, int r, tree val) //range update
{
	push(idx, i, j);
	if (i > r || j < l) return /*vazio*/;
	if (i >= l && j <= r)
	{
		lazy[idx] = /*val*/;
		push(idx, i, j);
		return;
	}
	int mid = (i+j)/2;
	update(esq(idx), i, mid, l, r, val);
	update(dir(idx), mid+1, j, l, r, val);
	st[idx] = merge(st[esq(idx)], st[dir(idx)]);
}

tree query(int idx, int i, int j, int l, int r)
{
	//push(idx, i, j);
	if (i > r || j < l) return /*empty*/;
	if (i >= l && j <= r) return st[idx];
	int mid = (i+j)/2;
	tree x = query(esq(idx), i, mid, l, r);
	tree y = query(dir(idx), mid+1, j, l, r);
	return merge(x, y);
}
