#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000000 + 7;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> grid(n);
    vector<vector<ll>> DP(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        DP[i] = vector<ll>(n, 0);
    }

    if (grid[0][0] == '*')
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        DP[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (DP[i][j] == -1)
                {
                    continue;
                }
                if (i + 1 < n)
                {
                    if (grid[i + 1][j] == '*')
                    {
                        DP[i + 1][j] = 0;
                    }
                    else
                    {
                        DP[i + 1][j] += DP[i][j];
                        DP[i][j] %= MOD;

                    }
                }
                if (j + 1 < n)
                {
                    if (grid[i][j + 1] == '*')
                    {
                        DP[i][j + 1] = 0;
                    }
                    else
                    {
                        DP[i][j + 1] += DP[i][j];
                        DP[i][j] %= MOD;
                    }
                }

            }
        }
    }

    cout << ((DP[n-1][n-1] >= 0) ? DP[n-1][n-1]%MOD : 0) << endl;
    // cout << DP[n - 1][n - 1] %MOD  << endl;
}
