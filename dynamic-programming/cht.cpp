//cht menor reta
deque<Func> retas;

void update(Func curr)
{
	int tam = retas.size();
	while (tam>1 && ((retas[tam-2].b-retas[tam-1].b)*(curr.a-retas[tam-2].a)) >= ((retas[tam-2].b-curr.b)*(retas[tam-1].a-retas[tam-2].a)))
		retas.pop_back(), tam--;
 
	retas.push_back(curr);
}
 
int query(int x)
{
	while (retas.size()>1 && retas[0].val(x) >= retas[1].val(x))
		retas.pop_front();
 
	return retas.front().val(x);
}

