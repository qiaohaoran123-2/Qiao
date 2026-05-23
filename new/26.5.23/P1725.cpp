#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r,b[200005],dp[5000005],ans=INT_MIN;
deque<int>dq;
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++)cin>>b[i];
    // for(int i=0;i<=n;i++)cout<<b[i]<<" ";
    // cout<<endl;
    for(int i=0;i<=n;i++){
        if(i==0)dp[i]=0;
        else if(dq.empty())dp[i]=-2e8;
        else dp[i]=dp[dq.front()]+b[i];
        if(i-l+1>=0){
            while(!dq.empty()&&dp[i-l+1]>=dp[dq.back()])dq.pop_back();
            dq.push_back(i-l+1);
        }
        while(!dq.empty()&&dq.front()<i-r+1)dq.pop_front();
        if(i+r>n)ans=max(ans,dp[i]);
    }
    // for(int i=0;i<=n;i++)cout<<dp[i]<<' ';
    // cout<<'\n';
    cout<<ans;
    return 0;
}