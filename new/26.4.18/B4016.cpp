#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
vector<int>g[maxn];
int u,v,n,dp[maxn],ans,j_1,j_2;
void dfs(int u,int p){
    j_1=j_2=0;
    for(auto v:g[u])if(v!=p){
        dfs(v,u);
        dp[u]=dp[v]+1;
        if(dp[v]>j_1)j_2=j_1,j_1=dp[v];
        else if(dp[v]>j_2)j_2=dp[v];
    }
    ans=max(ans,j_1+j_2+2);
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}