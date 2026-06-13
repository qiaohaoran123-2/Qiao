#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[10][10],dp[10][70];
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=(1<<m);j++)if(j&(j+1)==0){

            }
        }
    }
    return 0;
}