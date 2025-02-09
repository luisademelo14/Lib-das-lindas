#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vc;
typedef vector <string> vs;
typedef vector <pair<int, int>> vpii;
typedef vector <pair<char, int>> vpci;
typedef pair <int, int> pii;
typedef map <int, int> mii;
typedef map <char, int> mci;
typedef map <string, int> msi;
typedef set <int> si;
typedef set <char> sc;
typedef set <string> ss;
 
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define lbnd lower_bound
#define ubnd upper_bound
#define debug cerr<<"\ni'm here\n"<<endl;
#define PI 3.141592653589793
 
const int mod = 1e9+7;
 
// usar z-function para resolver (achar o padrão na string)
 
// lembrar que z[i] = tamanho do maior prefixo que começa em i e bate com o 
// prefixo da string inteira
 
// para a resposta final: percorrer o vetor z e ver quando z[i]==pattern.size()
// nesse caso, incrementa 1 na resposta
 
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
 
 
 
void solve(){
    string p, str;
    cin >> str >> p;
 
    string total = p+'#'+str;
 
    ll ans = 0;
 
    vector<int> z = z_function(total);
 
    for(int i=0; i<(int)total.size(); i++){
        if(z[i]==(int)p.size())
            ans++;
    }
 
    cout << ans << endl;
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
