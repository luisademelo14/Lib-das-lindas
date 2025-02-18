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
 
int dp[19][2][2][10][2], quant[19][2][2][10][2], a, b;
deque<int> l, r;
 
ii f(int idx, int menor, int maior, int prev, int zero_front)
{
	if (idx >= l.size()) return {0ll, 1ll};
	int &resp = dp[idx][menor][maior][prev+1][zero_front];
	if (~resp) return {resp, quant[idx][menor][maior][prev+1][zero_front]};
	resp = 0;
	for (int d = (menor ? l[idx] : 0); d <= (maior ? r[idx] : 9); d++)
	{
		auto[s, q] = f(idx+1, menor&(d==l[idx]), maior&(d==r[idx]), d, zero_front&(d==0));
        if(d!=prev || zero_front){
            resp += d*q + s;
            quant[idx][menor][maior][prev+1][zero_front] += q;
        }
	}
	return {resp, quant[idx][menor][maior][prev+1][zero_front]};
}
 
void solve(){
    cin >> a >> b;        
    int resp = 0;
    l.clear();
    r.clear();
    while (a)
    {
        l.push_front(a%10);
        a /= 10;
    }
    while (b)
    {
        r.push_front(b%10);
        b /= 10;
    }
    while (l.size() < r.size()) l.push_front(0);
    memset(dp, -1, sizeof dp);
    memset(quant, 0, sizeof quant);
    ii p1 = f(0, 1, 1, -1, 1);
    cout << p1.second << endl;
        
    
}
 
 
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
}
