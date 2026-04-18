#include<bits/stdc++.h>
using namespace std;
int n,dp[10005][5],u,v,r[10005];
vector<int>g[10005];
void dfs(int u,int p){
    dp[u][1]=r[u];
    for(auto v:g[u])if(v!=p){
        dfs(v,u);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][1],dp[v][0]);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>r[i];
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<min(dp[1][1],dp[1][0]);
    return 0;
}