#include<bits/stdc++.h>
using namespace std;
long long n,cnt,a[2005],res[2005],maxt,m,k,res_size,ans;
void work(long long t){
    res_size=cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=a[i]/t;
        res[i]=a[i]%t;
    }
    // cout<<1145<<endl;
    sort(res+1,res+n+1,[&](int a,int b)->bool {return a>b;});
    for(int i=1;i<=n;i++){
        if(res[i]!=0){
            res_size++;
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxt=max(maxt,a[i]);
    }
    // cout<<1<<endl;
    for(int t=1;t<=maxt;t++){
        work(t);
        // cout<<2<<endl;
        if(cnt>=m){
            ans=max(ans,t*(k));
        }
        // cout<<4<<endl;
        if(cnt<m-k){
            long long ans2=0;
            long long c=m-k-cnt;
            for(int i=1;i<=k;i++){
                ans2+=res[i+c];
            }
            ans=max(ans,ans2);
        }
        // cout<<3<<endl;
        if(cnt<m&&cnt>=m-k){
            long long ans2=0,c=cnt-m+k;
            ans2+=c*t;
            for(int i=1;i<=k-c;i++){
                ans2+=res[i];
            }
            ans=max(ans,ans2);
        }
    }
    cout<<ans;
    return 0;
}