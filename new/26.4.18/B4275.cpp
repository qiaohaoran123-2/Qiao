#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+5;
vector<int>g[maxn];
bool G[maxn];
int dp[maxn][5],r[maxn],n,l,k,rt;
void dfs(int p){
    dp[p][1]=r[p];
    for(auto u:g[p]){
        dfs(u);
        dp[p][0]+=max(dp[u][0],dp[u][1]);
        dp[p][1]+=dp[u][0];
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>l>>r[l];
        g[k].push_back(l);
    }
    dfs(0);
    cout<<max(dp[0][0],dp[0][1]);
    return 0;
}