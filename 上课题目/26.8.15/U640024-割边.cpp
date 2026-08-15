#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;
struct Edge
{
    int v, id;     //终点，边的编号
};
vector<Edge> G[maxn];
int dfn[maxn], low[maxn], tid;
int cut[maxm];

void tarjan(int u, int p)
{
    dfn[u] = low[u] = ++tid;
    int cnt = 0;
    /*
    统计有几次会回到父节点
    只有一次回到父节点，说明这是个树边，不能更新low
    多次回到父节点，说明这是重边，可以更新low
    */
    for(auto e : G[u])
    {
        int v = e.v;
        cnt += v == p;
        if(!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) cut[e.id] = 1;
        }
        else if(v != p || cnt > 1) low[u] = min(low[u], dfn[v]);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if(u == v) continue;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    for(int u = 1; u <= n; u++) if(!dfn[u]) tarjan(u, 0);

    int cnt = 0;
    for(int i = 1; i <= m; i++) if(cut[i])
    {
        cout << i << endl;
        cnt++;
    }
    if(!cnt) cout << "no";
    return 0;
}
