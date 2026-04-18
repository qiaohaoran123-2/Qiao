#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;
vector<int>g[maxn];
int dp[maxn][5],n,l,k;
void dfs(int u,int p){
    dp[u][1]=1;
    for(auto v:g[u])if(v!=p){
        dfs(v,u);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>l>>k;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1]);
    return 0;
}