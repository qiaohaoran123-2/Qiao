#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=16005;
int r[maxn],n,u,v,dp[maxn],ans=INT_MIN;
vector<int>g[maxn];
void dfs(int u,int p){
    dp[u]=r[u];
    for(auto v:g[u])if(v!=p){
        dfs(v,u);
        dp[u]+=max(0ll,dp[v]);
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)ans=max(dp[i],ans);
    // for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
    // cout<<dp[1];
    cout<<ans;
    return 0;
}