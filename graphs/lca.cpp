// lowest common ancestor - binary lifting

// complexidade do pre-processamento: O(n log(n))
// complexidade de cada query: O(log(n))


// n = numero de vertices da arvore
// l = ceil(log(n))

int n, l;


vector<vector<ii>> tree;
int timer;
vector<int> t_in (MAXN);
vector<int> t_out (MAXN);
vector<vector<int>> up;
vector<int> level (MAXN);

void dfs(int u, int p){
    t_in[u] = ++timer;
    int temp = 0;


    for(auto x : tree[u]){
        if(x.first==p && u!=0){
            temp = x.second;
            break;
        }
    }

    level[u] = level[p] + temp;
    up[u][0] = p;
    for (int i = 1; i < l; i++)
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i].first;
        if (v != p) dfs(v, u);
    }

    t_out[u] = ++timer;
}

// verifica se u é ancestral de v
bool is_ancestor(int u, int v){
    return (t_in[u] <= t_in[v] && t_out[u] >= t_out[v]);
}

// calcula o lca de u e v
int lca(int u, int v){

    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = 21; i >= 0; i--){
        if (!is_ancestor(up[v][i], u))
            v = up[v][i]; 
    }

    return up[v][0];
}

void preprocess(int root) {
    t_in.resize(MAXN);
    t_out.resize(MAXN);
    timer = 0;
    l = ceil(log2(n));
    up.assign(MAXN, vector<int>(22, 0)); 

    dfs(root, 0);
}
