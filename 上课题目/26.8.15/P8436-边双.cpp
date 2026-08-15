#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
struct Edge
{
    int v, id;     //终点，边的编号
};
vector<Edge> G[maxn];
int dfn[maxn], low[maxn], tid;
int s[maxn], tp;
vector<int> dcc[maxn]; int dc;

void tarjan(int u, int p)
{
    dfn[u] = low[u] = ++tid;
    s[++tp] = u;
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
            if(low[v] > dfn[u])
            {
                dc++;
                do
                {
                    dcc[dc].push_back(s[tp]);
                }while(s[tp--] != v);
            }
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
    for(int u = 1; u <= n; u++)
        if(!dfn[u]) 
        {
            tarjan(u, 0);
            dc++;
            while(tp) dcc[dc].push_back(s[tp--]);
        }
            
    
    cout << dc << endl;
    for(int i = 1; i <= dc; i++)
    {
        cout << dcc[i].size();
        for(auto u : dcc[i]) cout << " " << u;
        cout << endl;
    }
    return 0;
}
