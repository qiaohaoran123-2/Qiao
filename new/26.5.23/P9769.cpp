#include<bits/stdc++.h>
using namespace std;
int y,n,m,b[15],dp[5000005];
deque<int>dq;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>y>>n>>m;
    for(int i=1;i<=m;i++)cin>>b[i];
    dq.push_back(0);
    for(int i=1;i<=y;i++){
        dp[i]=dp[dq.front()]+1;
        for(int j=1;j<=m;j++)if(i%b[j]==0&&b[j]!=1)dp[i]=min(dp[i],dp[i/b[j]]+1);
        while(!dq.empty()&&dp[i]<=dp[dq.back()])dq.pop_back();
        while(!dq.empty()&&i-dq.front()>=n)dq.pop_front();
        dq.push_back(i);
    }
    cout<<dp[y];
    return 0;
}