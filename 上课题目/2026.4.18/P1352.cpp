#include<bits/stdc++.h>
using namespace std;
const int maxn = 6e3 + 5;
vector<int> G[maxn];
int p[maxn], r[maxn], dp[maxn][2];
void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = r[u];
    for(auto v : G[u])
    {
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    //cout << u << " " << dp[u][0] << " " << dp[u][1] << endl;
}
int main()
{
    int n, l, k;
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &r[i]);
    for(int i = 1; i < n; i++)
    {
        scanf("%d%d", &l, &k);
        p[l] = k;
        G[k].push_back(l);
    }
    int rt = 0;
    for(int i = 1; i <= n; i++) if(!p[i])
    {
        rt = i;
        break;
    }
    dfs(rt);
    cout << max(dp[rt][0], dp[rt][1]);
    return 0;
}