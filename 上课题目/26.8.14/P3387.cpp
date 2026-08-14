#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int a[maxn];
vector<int> G[maxn];
int dfn[maxn], low[maxn], tid;    //dfs�򣬻�����С�㣬ʱ���
int s[maxn], ins[maxn], tp;       //ջ���Ƿ���ջ�ڣ�ջ��ָ��
int sid[maxn], sc;                //u����scc�ı�ţ�scc����
void tarjan(int u)
{
    dfn[u] = low[u] = ++tid;
    s[++tp] = u; ins[u] = 1;
    for(auto v : G[u])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] <= low[u])
    {
        ++sc;
        do
        {
            sid[s[tp]] = sc;
            ins[s[tp]] = 0;
        }while(s[tp--] != u);
    }
}
int A[maxn], in[maxn], d[maxn];
vector<int> H[maxn];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
    }
    for(int u = 1; u <= n; u++) 
        if(!dfn[u]) tarjan(u);
    for(int u = 1; u <= n; u++) 
    {
        A[sid[u]] += a[u];
        for(auto v : G[u]) if(sid[u] != sid[v])
        {
            H[sid[u]].push_back(sid[v]);
            in[sid[v]]++;
        }    
    }
    queue<int> q;
    for(int u = 1; u <= sc; u++) if(!in[u])
    {
        q.push(u);
        d[u] = A[u];
    }
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(auto v : H[u])
        {
            d[v] = max(d[v], d[u] + A[v]);
            if(--in[v] == 0) q.push(v);
        }
    }
    
    int ans = 0;
    for(int u = 1; u <= sc; u++) ans = max(ans, d[u]);
    cout << ans;
    return 0;
}