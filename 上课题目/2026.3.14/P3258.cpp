#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int d[maxn],s[maxn],ans,a[maxn];
int n,m,f[maxn][25],u,v,dep[maxn];
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
    for(int j=20;j>=0;j--)if(f[u][j]!=f[v][j])u=f[u][j],v=f[v][j];
    return f[u][0];
}
int dfs2(int u,int p){
    for(auto v:g[u])if(v!=p)d[u]+=dfs2(v,u);
    return d[u];
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<n;i++){
        int l=lca(a[i],a[i+1]);
        d[a[i]]++;
        d[a[i+1]]++;
        d[l]--;
        if(f[l][0])d[f[l][0]]--;
    }
    dfs2(1,0);
    for(int i=2;i<=n;i++)d[a[i]]--;
    for(int i=1;i<=n;i++)cout<<d[i]<<'\n';
    return 0;
}