#include <bits/stdc++.h>
//#define int long long
#define MAXN (int) (1e5 + 100)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//#pragma GCC optimization ("unroll-loops")

using namespace std;

int bb(int x, int val, vector<vector<int> > &vet)
{
    int ini = 0, meio, fim = vet[x].size()-1;
    while (ini <= fim)
    {
        meio = (ini+fim)/2;
        if (vet[x][meio] <= val) ini = meio + 1;
        else fim = meio - 1;
    }

    return ini-1;
}

int32_t main()
{_
    int t;
    cin>>t;
    while (t--) {

        vector< vector<int> > vet(MAXN);
        vector<int> vis(MAXN, 0);
        int n, q, x, y, r;
        cin>>n>>q;
        for (int i=1; i<=n; i++) {
            cin>>x>>y>>r;
            x += 10;
            y += 10;
			for (int j = 1; j <= r; j++)
			{
				vet[x].emplace_back(y+j);
				vet[x].emplace_back(y-j);
				vet[x-j].emplace_back(y);
				vet[x+j].emplace_back(y);
			}	
			vet[x].emplace_back(y);
            for (int j=1; j<=r; j++) 
                for (int k=1; k*k + j*j <=r*r; k++) 
				{
					vet[x+j].emplace_back(y-k);
					vet[x-j].emplace_back(y+k);
					vet[x+j].emplace_back(y+k);
					vet[x-j].emplace_back(y-k);
				}
		}

        while (q--) {
            cin>>x>>y;
            x += 10;
            if (!vis[x])
            {
                sort(all(vet[x]));
                vis[x] = 1;
            }
            y += 10;

            int l = bb(x, y-1, vet);
            int r = bb(x, y, vet);
            if (r == -1) cout << 0 << endl;
            else cout << r - l << endl;
        }
    }
    return 0;

}
