// resolve logaritmo discreto com o algoritmo baby step giant step
// encontra o menor x tal que a^x = b (mod m)
// se nao tem log definido, retorna -1
// complexidade:  O(sqrt(m) * log(sqrt(m))

int dlog(int b, int a, int m) {
	if (a == 0) return b ? -1 : 1; // caso nao definido

	a %= m, b %= m;
	int k = 1, shift = 0;
	while (1) {
		int g = gcd(a, m);
		if (g == 1) break;

		if (b == k) return shift;
		if (b % g) return -1;
		b /= g, m /= g, shift++;
		k = (ll) k * a / g % m;
	}

	int sq = sqrt(m)+1, giant = 1;
	for (int i = 0; i < sq; i++) giant = (int) giant * a % m;

	vector<pair<int, int>> baby;
	for (int i = 0, cur = b; i <= sq; i++) {
		baby.emplace_back(cur, i);
		cur = (ll) cur * a % m;
	}
	sort(baby.begin(), baby.end());

	for (int j = 1, cur = k; j <= sq; j++) {
		cur = (ll) cur * giant % m;
		auto it = lower_bound(baby.begin(), baby.end(), pair(cur, MOD));
		if (it != baby.begin() and (--it)->first == cur)
			return sq * j - it->second + shift;
	}

	return -1;
}
