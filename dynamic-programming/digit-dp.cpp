//sum of digits of all numbers in range [a, b]
int dp[10][2][2], quant[10][2][2], a, b;
deque<int> l, r;

ii f(int idx, int menor, int maior)
{
	if (idx >= l.size()) return {0ll, 1ll};
	int &resp = dp[idx][menor][maior];
	if (~resp) return {resp, quant[idx][menor][maior]};
	resp = 0;
	for (int d = (menor ? l[idx] : 0); d <= (maior ? r[idx] : 9); d++)
	{
		auto[s, q] = f(idx+1, menor&(d==l[idx]), maior&(d==r[idx]));
		resp += d*q + s;
		quant[idx][menor][maior] += q;
	}
	return {resp, quant[idx][menor][maior]};
}

int digit_dp(int a, int b)
{
	int resp = 0;
	l.clear();
	r.clear();
	while (a)
	{
		l.push_front(a%10);
		a /= 10;
	}
	while (b)
	{
		r.push_front(b%10);
		b /= 10;
	}
	while (l.size() < r.size()) l.push_front(0);
	memset(dp, -1, sizeof dp);
	memset(quant, 0, sizeof quant);
	ii p = f(0, 1, 1);
	return p.first;
}
