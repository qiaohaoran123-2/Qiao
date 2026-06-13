#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,dp[maxn][25],a[25][25];
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=1;
    for(int i=2;i<=(1<<n+1)-1;i++){
        for(int j=0;j<n;j++)if((i<<j)&1){
            int t=i;
        }
    }
    return 0;
}