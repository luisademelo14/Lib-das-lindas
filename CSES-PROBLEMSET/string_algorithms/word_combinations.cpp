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
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define lbnd lower_bound
#define ubnd upper_bound
#define debug cerr<<"\ni'm here\n"<<endl;
#define PI 3.141592653589793
 
const int mod = 1e9+7;
 
string str;
 
int n;
 
vector<int> dp (5005);
 
int is_end_of_word [1000006+5];
int trie [1000006+5][26];
int trie_nodes = 0;
 
void insert_tree(string &word){
    // o curr_node comeca na raiz da trie
    int curr_node = 0;
    for(auto c : word){
        if(!trie[curr_node][c-'a']){
            trie[curr_node][c-'a'] = ++trie_nodes;
        }
        // atualiza o vértice (vai descendo na trie)
        curr_node = trie[curr_node][c-'a'];
    }
    // terminou de inserir a string no vertice atual
    is_end_of_word[curr_node] = true;
}
 
// número de maneiras de formar a string a partir do
// char "start" da string
int count_ways(int start, string &str){
    int curr_node = 0;
    int ways = 0;
    for(int i=start; i<(int)str.size(); i++){
        if(!trie[curr_node][str[i]-'a'])
            return ways;
        curr_node = trie[curr_node][str[i]-'a'];
 
        if(is_end_of_word[curr_node])
            ways = (ways + dp[i+1]) % mod;
    }
    return ways;
}
 
void solve(){
    cin >> str;
    cin >> n;
    string word;
    for(int i=0; i<n; i++){
        cin >> word;
        insert_tree(word);
    }
    dp[str.size()] = 1;
    for(int i=(int)str.size()-1; i>=0; i--){
        dp[i] = count_ways(i, str);
    }
 
    cout << dp[0] << endl;
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
