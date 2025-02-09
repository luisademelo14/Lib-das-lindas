#include <bits/stdc++.h>
 
using namespace std;
 
// complexidade O(n)
 
// centroid = vertice que, quando eh raiz da arvore, garante que nao ha
// outros vertices com subarvore de tamanho maior que n/2
// sua remocao da arvore gera apenas subtrees de tamanho <= /n/2
 
int n, subsize[200005];
 
vector<int> g[200005];
 
// calcula o tamanho da subtree enraizada em v
void dfs(int v, int pai=-1) {
	subsize[v] = 1;
    // pra cada filho, soma o tamanho da subtree no tamanho total
    // daquela subarvore
	for (int i : g[v]) if (i != pai) {
        // tem que chamar a dfs antes de somar no subsize pra 
        // garantir que o tamanho da subarvore do filho foi calculado
		dfs(i, v);
		subsize[v] += subsize[i];
	}
}
 
// calcula um centroid da arvore
int centroid(int v, int pai=-1, int tam=-1) {
	if (tam == -1) tam = subsize[v];
    // se o tamanho passa de tam/2, nao pode ser centroid e desce pros filhos
	for (int i : g[v]) if (i != pai) if (subsize[i] > tam/2)
		return centroid(i, v, tam);
	return v;
}
 
// chama as outras funcoes pra achar no maximo dois centroids 
// da arvore 
pair<int, int> centroids(int v) {
    // primeiro v que passa aqui eh a raiz da arvore (definida na solve)
	dfs(v);
	int i = centroid(v), i2 = i;
    // atualizando o segundo centroid, se houver
	for (int j : g[i]) if (2*subsize[j] == subsize[v]) i2 = j;
	// i e i2 sao os centroids (pode ser o mesmo vertice)
    return {i, i2};
}
 
void solve(){
    int a, b;
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    cout << centroids(1).first << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
