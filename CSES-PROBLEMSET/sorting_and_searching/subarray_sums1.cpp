#include <bits/stdc++.h>
#include <unordered_map>
 
using namespace std;
typedef long long ll;
 
ll n, x;
 
vector<ll> a;
 
ll qnt_subarrays(){
    // ponteiros pra limitar os subarrays
    int start = 0;
    int end = -1; // end começa com -1, pra dar certo a aritmética dos 
                  // índices no loop indicado com (*)
    // qnt de subarrays com soma x
    ll ans = 0;
    // controle da soma atual
    ll curr_sum = 0;
    while(end<n){
        if(curr_sum == x){
            ans++;
            curr_sum -= a[start];
            start++;
        }
 
        while(end<n && curr_sum<x){ //(*)
            end++;
            curr_sum+=a[end];
        }
 
        while(start<=end && curr_sum>x){
            curr_sum-=a[start];
            start++;
        }
    }
 
    return ans;
}
 
void solve(){
    cin >> n >> x;
    a = vector<ll> (n);
 
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
 
    cout << qnt_subarrays() << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
