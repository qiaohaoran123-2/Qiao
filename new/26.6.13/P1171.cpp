#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,dp[maxn][25],a[25][25];
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    for(int i=2;i<(1<<n);i++){
        for(int j=0;j<n;j++)if((i>>j)&1){
            int t=i^(1<<j);
            for(int k=0;k<n;k++)if((t>>k)&1)dp[i][j]=min(dp[i][j],dp[t][k]+a[k][j]);
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[(1<<n)-1][i]+a[i][0]);
    }
    cout<<ans;
    return 0;
}