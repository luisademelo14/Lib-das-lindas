#include <bits/stdc++.h>
#define int long long
#define MAXN (int) (1e6 + 10)
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define esq(x) (x<<1)
#define dir(x) ((x<<1)|1)
#define MOD (int) (1e9 + 7)
#define BASE 37
#define MAXL 20
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int t, n, m, arr[MAXN];
vector<int> v[10][34];

int32_t main()
{_
    cin >> t;
    for (int d = 1; d <= 9; d++)
    {
        v[d][0].resize(10, 0);
        v[d][0][d] = 1;
        for (int i = 1; i <= 33; i++)
        {
            v[d][i].resize(10, 0);
            for (int j = 1; j <= 9; j++)
            {
                if (j*3 > 10) 
                {
                    v[d][i][((j*3)%10)] += v[d][i-1][j];
                    v[d][i][((j*3)/10)] += v[d][i-1][j];
                }
                else
                    v[d][i][j*3] += v[d][i-1][j];
            }

            // for (int j = 0; j <= 9; j++)
            //     printf("v[%d][%d][%d] = %d\n", d, i, j, v[d][i][j]);
        }
    }


    while (t--)
    {
        cin >> m >> n;
        vector<int> freq(10, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        int ok = 1;
        for (int i = 1; ok && i <= 9; i++)
        {
            for (int j = i; ok && j <= 9; j++)
            {
                for (int k = j; ok && k <= 9; k++)
                {
                    int diff = 0;
                    for (int d = 1; d <= 9; d++)
                    {
                        if (freq[d] > v[i][m][d]+v[j][m][d]+k[k][m][d])
                        {
                            diff = 0;
                            break;
                        }
                        diff += abs(freq[d]-v[i][m][d]-v[j][m][d]-v[k][m][d]);
                    }

                    if (diff == 1)
                    {
                        for (int d = 1; d <= 9; d++)
                        {
                            if (freq[d]-v[i][m][d]-v[j][m][d]-v[k][m][d])
                                cout << d << endl;
                            ok = 0;
                        }
                    }
                }
            }
        }
    }
}
