// problema: dado um conjunto de moedas, imprimir o número de possibilidades
// de soma dessas moedas, assim como todas as somas possíveis
 
// assunto usado para resolver: DP
 
#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
 
using namespace std;
 
int n;
 
vector<int> coins (105);
 
 
// a dp eh nas somas possiveis e qnt de moedas usadas
 
vector<int> ans;
 
void solve(){
    cin >> n;
 
    vector<vector<int>> dp (n+2, vector<int>(MAXN,0));
 
    for(int i=0; i<n; i++)
        cin >> coins[i];
 
    dp[0][0] = 1;
 
    // usando i moedas, chega na soma j (1 se sim e 0 se nao)
 
    for(int i=1; i<=n; i++){
        for(int j=0; j<=1e5; j++){
            // se sabe que eh possivel chegar na soma j
            // com menos moedas, ja atualiza
            dp[i][j] = dp[i-1][j];
 
            if(j-coins[i-1]>=0 && dp[i-1][j-coins[i-1]])
                dp[i][j] = 1;
 
        }
    }
 
    for(int i=1; i<=1e5; i++){
        if(dp[n][i])
            ans.push_back(i);
    }
 
    cout << ans.size() << endl;
 
    for(auto u : ans){
        cout << u << ' ';
    }
    
    cout << endl;
}
 
 
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}
