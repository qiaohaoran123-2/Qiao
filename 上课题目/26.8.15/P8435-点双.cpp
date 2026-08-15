#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
vector<int> G[maxn];
int dfn[maxn], low[maxn], tid;     //dfs序，回溯最小点，时间戳
int s[maxn], tp; //栈，栈顶指针
vector<int> dcc[maxn]; int dc; //点双，点双数量

void tarjan(int u)
{
    dfn[u] = low[u] = ++tid;
    s[++tp] = u;
    for(auto v : G[u])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u])
            {
                dc++;
                do
                {
                    dcc[dc].push_back(s[tp]);
                }while(s[tp--] != v);
                /*
                在栈中，v和u不一定相邻，中间隔开的点满足low[v] < dfn[u]
                因此循环到v停止，而u作为割点或树根也一定是最后添加
                */
                dcc[dc].push_back(u);
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
    //特判孤立点
    if(G[u].empty()) dcc[++dc].push_back(u);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if(u == v) continue;     //自环不能添加到图中，否则特判会失败
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int u = 1; u <= n; u++) 
        if(!dfn[u]) tarjan(u);

    cout << dc << endl;
    for(int i = 1; i <= dc; i++)
    {
        cout << dcc[i].size();
        for(int j = 0; j < dcc[i].size(); j++)
            cout << " " << dcc[i][j];
        cout << endl;
    }
    return 0;
}
