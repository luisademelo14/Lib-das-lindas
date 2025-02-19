#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (2e5 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<long long, long long>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
 
using namespace std;
 
 
void solve(){
    int n;
    cin >> n;
    vector<int> a (n+2);
 
    for(int i=1; i<=n; i++)
        cin >> a[i];
 
    stack <int> next_smaller;
 
    for(int i=1; i<=n; i++){
        int curr = a[i];
 
        while(!next_smaller.empty() && a[next_smaller.top()]>=curr)
            next_smaller.pop();
        
        if(next_smaller.empty())
            cout << 0 << ' ';
        
        else
            cout << next_smaller.top() << ' ';
        
        next_smaller.push(i);
    }
 
    cout << endl;
    
}
 
 
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}
