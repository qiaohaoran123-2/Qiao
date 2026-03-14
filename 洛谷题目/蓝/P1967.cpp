#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{int a,b;};
struct node{int u,v,w;};
const int minn=5e4+5,minm=1e4+5;
int n,m,p[minm],C[minm],f[minm][25],dep[minm],c[minm][25],q,x,y;
node a[minn];
vector<Node>g[minn];
bool cmp(node a,node b){return a.w>b.w;}
int getp(int x){return p[x]==x?x:p[x]=getp(p[x]);}
void link(int x,int y){
    if(C[x]<C[y])swap(x,y);
    int px=getp(x),py=getp(y);
    C[px]+=C[py];
    p[py]=px;
}
void dfs(int u,int p,int w){
    f[u][0]=p;
    c[u][0]=w;
    dep[u]=dep[p]+1;
    for(int j=1;j<=20;j++)f[u][j]=f[f[u][j-1]][j-1],c[u][j]=min(c[f[u][j-1]][j-1],c[u][j-1]);
    for(auto [v,w]:g[u])if(v!=p)dfs(v,u,w);
}
Node lca(int u,int v){
    int ans=9e18;
    if(dep[u]>dep[v])swap(u,v);
    int d=abs(dep[u]-dep[v]);
    for(int j=20;j>=0;j--)if((d>>j)&1)ans=min(ans,c[v][j]),v=f[v][j];
    if(u==v)return {u,ans};
    for(int j=20;j>=0;j--)if(f[u][j]!=f[v][j])ans=min(ans,c[v][j]),ans=min(ans,c[u][j]),u=f[u][j],v=f[v][j];
    if(u!=v)ans=min(ans,c[u][0]),ans=min(c[v][0],ans);
    return {f[u][0],ans};
}
bool vis[minm];
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)p[i]=i,C[i]=1;
    for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++)if(getp(a[i].u)!=getp(a[i].v)){
        g[a[i].u].push_back({a[i].v,a[i].w});
        g[a[i].v].push_back({a[i].u,a[i].w});
        link(a[i].u,a[i].v);
    }
    for(int i=1;i<=n;i++)if(!vis[getp(i)])dfs(i,0,-1),vis[getp(i)]=1;
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<lca(x,y).b<<'\n';
    }
    return 0;
}