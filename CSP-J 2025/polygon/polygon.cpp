#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],dp[5005][5005],ans,s=1;
//dp[i][j]表示前i个木棍，选中其中一些，长度总和是j的情况下有多少方案
//dp[i][j]=
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        s=s*2%mod;
        for(int j=5000;j>=0;j--){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i])dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
        }
        for(int j=0;j<=a[i];j++)
            ans=(ans+dp[i-1][j])%mod;
    }
    cout<<(s+mod-ans-1)%mod;
    return 0;
}