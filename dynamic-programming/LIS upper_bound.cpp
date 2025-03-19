/*
encontrar a maior subsequência crescente
dp[l] -> menor elemento que uma LIS de tam l termina
 */

int lis(vector<int> v){
    vector<int> dp(n+1, INF);
    dp[0] = -INF;

    for(int i=1; i<=n; i++){
        int l = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if(dp[l-1] < v[i] && v[i]<dp[l]) dp[l] = v[i];
    }

    int ans = 0;
    for(int l=0; l<=n; l++){
        if(dp[l] < INF) ans = l;
    }

    return ans;
}

