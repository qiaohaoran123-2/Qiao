#include<bits/stdc++.h>
using namespace std;
int n,u,v,p[100005],d[100005],a,ans;
vector<int>g[100005];
void dfs(int u,int f){
    p[u]=f;
    for(auto v:g[u])if(v!=f){
        d[v]=d[u]+1;
        dfs(v,u);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)a=d[i]>d[a]?i:a;
    // cout<<a<<'\n';
    d[a]=0;
    dfs(a,0);
    // for(int i=1;i<=n;i++)cout<<p[i]<<' ';
    // cout<<'\n';
    // for(int i=1;i<=n;i++){for(auto u:g[i])cout<<u<<' ';cout<<'\n';}
    for(int i=1;i<=n;i++)ans=max(ans,d[i]);/*cout<<d[i]<<' ';*/
    cout<<ans;
    return 0;
}