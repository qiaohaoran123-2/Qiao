#include<bits/stdc++.h>
using namespace std;
int n,m,k,s[305],dp[305][305];
vector<int>g[305];
void dfs(int u){
    dp[u][1]=s[u];
    for(auto v:g[u]){
        dfs(v);
        for(int j=m;j>=1;j--)for(int i=1;u==0?i<=j:i<j;i++)
            dp[u][j]=max(dp[u][j],dp[u][j-i]+dp[v][i]);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k>>s[i];
        g[k].push_back(i);
    }
    dfs(0);
    cout<<dp[0][m];
    return 0;
}