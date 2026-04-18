#include<bits/stdc++.h>
using namespace std;
int n,dp[1505][5],r,c,d,rt=2000;
vector<int>g[1505];
void dfs(int u,int p){
    dp[u][1]=1;
    for(auto v:g[u])if(v!=p){
        dfs(v,u);
        dp[u][0]+=dp[v][1];
        dp[u][1]+=min(dp[v][1],dp[v][0]);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>d>>c;
        for(int i=1;i<=c;i++){
            cin>>r;
            g[d].push_back(r);
            g[r].push_back(d);
        }
    }
    dfs(0,rt);
    cout<<min(dp[0][1],dp[0][0]);
    return 0;
}