// encontra menor distancia de x para todos os vertices
// se ao final do algoritmo d[i] = LINF, entao x nao alcanca i
// complexidade: O(m log(n))

int d[MAXN];
vector<pair<int, int>> g[MAXN]; // pair eh do tipo {vizinho, peso}

int n; // numero de vertices

void dijkstra(int v) {
	for (int i = 0; i < n; i++)
		d[i] = MOD;
	d[v] = 0;
	priority_queue<pair<ll, int>> pq;
	pq.emplace(0, v);

	while (pq.size()) {
		auto [ndist, u] = pq.top(); pq.pop();
		if (-ndist > d[u]) continue;

		for (auto [idx, w] : g[u]) if (d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.emplace(-d[idx], idx);
		}
	}
}
