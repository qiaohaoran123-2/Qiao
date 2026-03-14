#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
vector<int> G[maxn];
const int maxL = 1e6 + 5;
int idx, dep[maxn], s[maxn], dp[maxL][25];
void dfs(int u, int p)
{
    s[u] = ++idx;
    dp[idx][0] = u;
    dep[u] = dep[p] + 1;
    for(auto v : G[u]) if(v != p)
    {
        dfs(v, u);
        dp[++idx][0] = u; 
    }
}
int lca(int u, int v)
{
    u = s[u]; v = s[v];
    if(u > v) swap(u, v);
    int k = log2(v - u + 1);
    int L = dp[u][k], R = dp[v - (1 << k) + 1][k];
    return dep[L] < dep[R] ? L : R;
}
int main()
{
    int N, M, S, u, v;
    cin >> N >> M >> S;
    for(int i = 1; i < N; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(S, 0);
        
    for(int j = 1; j <= 20; j++)
        for(int i = 1; i + (1 << j) - 1 <= idx; i++)
        {
            int L = dp[i][j - 1], R = dp[i + (1 << (j - 1))][j - 1];
            dp[i][j] = dep[L] < dep[R] ? L : R;
        } 
    for(int i = 1; i <= M; i++)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}