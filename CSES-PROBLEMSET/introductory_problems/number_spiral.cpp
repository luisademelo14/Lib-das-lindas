#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
 
void solve(){
    int t;
    ll x, y;
    cin >> t;
    while(t--){
        cin >> y >> x;
        if(y>=x && y%2==0){
            cout << y * y - (x-1) << '\n';
        }
        else if(y>=x && y%2!=0){
            cout << (y-1) * (y-1) + x << '\n';
        }
        else if(x>y && x%2==0){
            cout << (x-1) * (x-1) + y << '\n';
        }
        else if(x>y && x&2!=0){
            cout << x * x - (y-1) << '\n';
        }
    }
}
 
int main(){
    solve();
    return 0;
}
