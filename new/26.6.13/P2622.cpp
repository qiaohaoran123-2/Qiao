#include<bits/stdc++.h>
#define int unsigned
using namespace std;
const int maxn=(1<<12)+5;
int n,m,a[105][15],d[maxn];
queue<int>q;
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)for(int j=0;j<n;j++)cin>>a[i][j];
    memset(d,-1,sizeof(d));
    d[(1<<n)-1]=0;
    q.push((1<<n)-1);
    bool f=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=1;i<=m;i++){
            int v=0;
            for(int j=0;j<n;j++){
                int cur=u&(1<<j);
                if(a[i][j]==1)cur=0;
                if(a[i][j]==-1)cur=1;
                v|=cur<<j;
            }
            if(d[v]==-1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    cout<<d[0];
    return 0;
}