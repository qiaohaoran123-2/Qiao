#include<bits/stdc++.h>
#define code return
#define by 0
#define qiaohaoran ;
using namespace std;
int a[500005],x[500005],n,dp[500005],k;
unordered_map<int,int>b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    b[0]=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x[i]=x[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        int c=x[i]^k;
        if(b.count(c))dp[i]=max(dp[b[c]]+1,dp[i]);
        b[x[i]]=i;
    }
    cout<<dp[n];
    code by qiaohaoran
}