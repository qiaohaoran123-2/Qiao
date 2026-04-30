#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,w[maxn],u,v,ans,c[maxn];
vector<int>g[maxn];
bool vis[maxn];
void dfs(int u){
    if(vis[u])return;
    for(auto v:g[u]){
        dfs(v);

    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)if(!vis[i]){
        dfs(i);
        ans=max(ans,c[i]);
    }
    cout<<ans;
    return 0;
}