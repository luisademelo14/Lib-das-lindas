#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define MAX_N 100005
 
int n;
 
vector<int> subsize (MAX_N);
 
// calcula o tamanho da subtree enraizada em v
void dfs(int v, int pai, vector<int> (&g)[MAX_N]) {
	subsize[v] = 1;
    // pra cada filho, soma o tamanho da subtree no tamanho total
    // daquela subarvore
	for (int i : g[v]) if (i != pai) {
        // tem que chamar a dfs antes de somar no subsize pra 
        // garantir que o tamanho da subarvore do filho foi calculado
		dfs(i, v, g);
		subsize[v] += subsize[i];
	}
}
 
// calcula um centroid da arvore
int centroid(int v, int pai, int tam, vector<int> (&g)[MAX_N]) {
	if (tam == -1) tam = subsize[v];
    // se o tamanho passa de tam/2, nao pode ser centroid e desce pros filhos
	for (int i : g[v]) if (i != pai) if (subsize[i] > tam/2)
		return centroid(i, v, tam, g);
	return v;
}
 
// chama as outras funcoes pra achar no maximo dois centroids 
// da arvore 
pair<int, int> centroids(int root, vector<int> (&g)[MAX_N]) {
    // primeiro v que passa aqui eh a raiz da arvore (definida na solve)
	dfs(root, -1, g);
	int i = centroid(root, -1, -1, g);
    int i2 = i;
    // atualizando o segundo centroid, se houver
	for (int j : g[i]) if (2*subsize[j] == subsize[root]) i2 = j;
	// i e i2 sao os centroids (pode ser o mesmo vertice)
    return {i, i2};
}
 
 
map <vector<int>, int> mp;
int ind = 0;
// para ver se sao isomorficas
int encode(int v, int pai, vector<int> (&g)[MAX_N]){
    vector<int> time;
    for(auto u : g[v]){
        if(u!=pai){
            time.push_back(encode(u, v, g));
        }
    }
    sort(time.begin(), time.end());
    if(!mp.count(time))
        mp[time] = ind++;
    return mp[time];
}
 
 
void solve(){
    mp.clear();
    subsize.clear();
    ind = 0;
    cin >> n;
    vector<int> g1 [MAX_N];
    vector<int> g2 [MAX_N];
    int a, b;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        g1[a].push_back(b);
        g1[b].push_back(a);
    }
 
    for(int i=1; i<n; i++){
        cin >> a >> b;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }
 
    int encode1 = encode(1, -1, g1);
 
    int encode2 = encode(1, -1, g2);
 
    if(encode1==encode2){
        cout << "YES" << endl;
    }
 
    else{
        cout << "NO" << endl;
    }
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
