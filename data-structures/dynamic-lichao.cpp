struct Func
{
	int a, b;
	int val(int x) 
	{
		return a*x + b;
	}	
};

struct tree
{
	Func g;
	int esq, dir;
};


vector<tree> st;

int novo()
{
	tree r = {{(int)1e9, (int)(1e15)}, -1, -1};
	st.push_back(r);
	return st.size() - 1;
}

void update(Func curr, int idx = 0, int i = 0, int j = MAXN-1)
{
	int mid = (i+j)>>1;
	int meio = st[idx].g.val(mid) > curr.val(mid);
	int ini = st[idx].g.val(i) > curr.val(i);
	if (meio) swap(st[idx].g, curr);
	if (j-i <= 1) return;
	if (st[idx].esq == -1) st[idx].esq = novo();
	if (st[idx].dir == -1) st[idx].dir = novo();
	if (ini != meio) update(curr, st[idx].esq, i, mid);
	else update(curr, st[idx].dir, mid+1, j);
}

int query(int pos, int idx = 0, int i = 0, int j = MAXN-1)
{
	if (j-i <= 0) 
		return st[idx].g.val(pos);
	int mid = (i+j)>>1;
	if (st[idx].esq == -1) st[idx].esq = novo();
	if (st[idx].dir == -1) st[idx].dir = novo();
	if (pos <= mid) return min(st[idx].g.val(pos), query(pos, st[idx].esq, i, mid));
	return min(st[idx].g.val(pos), query(pos, st[idx].dir, mid+1, j));
}
