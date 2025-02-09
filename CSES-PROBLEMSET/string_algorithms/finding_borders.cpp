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
 
const ll mod = 1e9+7;
 
const ll p1 = 31;
 
const ll p2 = 37;
 
// o tamanho do polinomio do hash é o tamanho da string
 
ll pow1[1000006];
ll pow2[1000006];
 
ll preff_hash1 = 0;
ll suff_hash1 = 0;
ll preff_hash2 = 0;
ll suff_hash2 = 0;
 
// pre-computando as potencias dos primos que sao usados no hash
void calc_pow(int n){
    pow1[0] = 1;
    pow2[0] = 1;
    for(int i=1; i<n; i++){
        pow1[i] = (pow1[i-1] * p1)%mod;
        pow2[i] = (pow2[i-1] * p2)%mod;
    }
}
 
void calc_hash(string &str, int n){
    // vai aumentando o polinomio do hash de um em um 
    // vai comparando os hashs na medida que calcula
    for(int i=0; i<n-1; i++){
        // tomar cuidado pra nao ficar zer (somar 1)
        ll char1 = str[i]-'a'+1;
        ll char2 = str[n-i-1]-'a'+1;
 
        preff_hash1 = (preff_hash1 + (char1*pow1[i]))%mod;
        preff_hash2 = (preff_hash2 + (char1*pow2[i]))%mod; 
        suff_hash1 = (suff_hash1*p1 + char2)%mod; 
        suff_hash2 = (suff_hash2*p2 + char2)%mod;
 
        if(preff_hash1==suff_hash1 && preff_hash2==suff_hash2)
            cout << i+1 << ' '; 
    }
}
 
void solve(){
    string str;
    cin >> str;
 
    int n = (int)str.size();
 
    calc_pow(n);
 
    calc_hash(str, n);
 
    cout << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
