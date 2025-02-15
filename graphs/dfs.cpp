// complexidade do algoritmo: O(n+m)

vector<int> g [MAXN]; // grafo como lista de adj

int n; // numero de vertices

vector<bool> visited(MAXN);

// funcao recursiva que passa por todos os vertices que
// estao conectados
void dfs(int v){
    visited[v] = true;
    for(int u : g[v]){
        if(!visited[u])
            dfs(u);
    }
}
