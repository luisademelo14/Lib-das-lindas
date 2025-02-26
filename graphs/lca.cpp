// lowest common ancestor - binary lifting

// complexidade do pre-processamento: O(n log(n))
// complexidade de cada query: O(log(n))


// n = numero de vertices da arvore
// l = ceil(log(n))
int n, l;

vector<vector<int>> tree;

int timer;

vector<int> t_in, t_out;

vector<vector<int>> up;

void dfs(int v, int parent){
    t_in[v] = ++timer;
    // imediatamente acima
    up[v][0] = parent;

    for(int i=1; i<=l; i++)
        up[v][i] = up[up[v][i-1]][i-1];

    for(int u : tree[v]){
        if(u!=parent)
            dfs(u,v);
    }

    t_out[v] = ++timer;
}

// verifica de u eh ancestral de v
bool is_ancestor(int u, int v){
    return ((t_in[u] <= t_out[v]) && (t_out[u] >= t_out[v]));
}

// calcula o lca de u e v
int lca(int u, int v){
    if(is_ancestor(u,v))
        return u;

    if(is_ancestor(v,u))
        return v;

    for(int i=l; i>=0; i--){
        if(!is_ancestor(up[u][i], v))
            u = up[u][i];
    }

    return up[u][0];
}

void preprocess(int root){
    t_in.resize(n+1);
    t_out.resize(n+1);
    timer = 0;
    l = ceil(log2(n));

    up.assign(n, vector<int>(l+1));

    dfs(root, -1);
}

