#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,s,f[maxn][25],u,v,dep[maxn],a,b,c,d,in[maxn],out[maxn];
vector<int>g[maxn];
void dfs(int u,int p){
    f[u][0]=p;
    dep[u]=dep[p]+1;
    for(int j=1;j<=20;j++)f[u][j]=f[f[u][j-1]][j-1];
    for(auto v:g[u])if(v!=p)dfs(v,u);
}
int lca(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    int d=abs(dep[u]-dep[v]);
    for(int j=20;j>=0;j--)if((d>>j)&1)v=f[v][j];
    if(u==v)return u;
    for(int j=20;j>=0;j--)
        if(f[u][j]!=f[v][j])u=f[u][j],v=f[v][j];
    return f[u][0];
}
bool asdf(int c,int d){
}
bool F(int c,int l,int r){
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    while(m--){
        cin>>a>>b>>c>>d;
        int l=lca(a,b),L=lca(c,d);
    }
    return 0;
}