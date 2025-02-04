int bfs()
{
	vector<int> grafo[MAXN];
	queue<int> fila;
	fila.push(1);
	int vis[MAXN];
	memset(vis, 0, sizeof vis);
	while (!fila.empty())
	{
		int u = fila.front(); fila.pop();
		vis[u] = 1;
		for (int v : grafo[u])
		{
			if (!vis[v]) 
			{
				fila.push(v);
				vis[v] = 1;
			}
		}
	}

	return 0;
}
