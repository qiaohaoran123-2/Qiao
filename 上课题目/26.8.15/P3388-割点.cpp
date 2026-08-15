#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 5;
vector<int> G[maxn];
int dfn[maxn], low[maxn], tid;     //dfs序，回溯最小点，时间戳
int cut[maxn], rt;
void tarjan(int u)
{
    dfn[u] = low[u] = ++tid;
    int cnt = 0; //dfs搜索树子节点数量
    for(auto v : G[u])
    {
        if(!dfn[v])
        {
            cnt++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) cut[u] = 1;
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if(u == rt && cnt == 1) cut[u] = 0;     //只有一个子节点的根，不是割点
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int u = 1; u <= n; u++) 
        if(!dfn[u]) 
        {
            rt = u;
            tarjan(u);
        }

    int cnt = 0;
    for(int u = 1; u <= n; u++) cnt += cut[u];
    cout << cnt << endl;
    for(int u = 1; u <= n; u++)
        if(cut[u]) cout << u << " ";
    return 0;
}

