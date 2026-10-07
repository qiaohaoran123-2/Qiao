#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=8e5+5;
int n,k,u,v,t[maxn][10],t2[maxn][10],lz[maxn],ans;
vector<int>G[maxn];
int an[10],an1[10];
void sum(int p1,int p2){
    int a=1,b=1;
    for(int i=0;i<k;i++){
        int &a1=an[i],&a2=an1[i];
        if(t[p1][a]<t[p2][b]){
            a1=t[p1][a];
            a2=t2[p1][a++];
        }
        else if(t[p1][a]==t[p2][b]){
            a1=t[p1][a];
            a2=t2[p1][a++]+t2[p2][b++];
        }
        else{
            a1=t[p2][b];
            a2=t2[p2][b++];
        }
    }
}
void pu(int p){
    int a=1,b=1,p1=p<<1,p2=(p<<1)+1;
    for(int i=0;i<k;i++){
        int &a1=t[p][i],&a2=t2[p][i];
        if(t[p1][a]<t[p2][b]){
            a1=t[p1][a];
            a2=t2[p1][a++];
        }
        else if(t[p1][a]==t[p2][b]){
            a1=t[p1][a];
            a2=t2[p1][a++]+t2[p2][b++];
        }
        else{
            a1=t[p2][b];
            a2=t2[p2][b++];
        }
    }
}
void matn(int p,int v){
    for(int i=0;i<k;i++)t[p][i]+=v;
    lz[p]+=v;
}
void bd(int p,int l,int r){
    if(l==r){
        t[p][0]=0;
        t2[p][0]=1;
        for(int i=1;i<k;i++)t[p][i]=n+i;
        return;
    }
    int m=(l+r)>>1;
    bd(p<<1,l,m);
    bd((p<<1)+1,m+1,r);
    pu(p);
}
void pd(int p){
    matn(p<<1,lz[p]);
    matn((p<<1)+1,lz[p]);
    lz[p]=0;
}
void upd(int p,int l,int r,int L,int R,int v){
    if(L<=l&&r<=R){
        matn(p,v);
        return;
    }
    if(lz[p])pd(p);
    int m=(l+r)>>1;
    if(m>=L)upd(p<<1,l,m,L,R,v);
    if(m<R)upd((p<<1)+1,m+1,r,L,R,v);
    pu(p);
}
int qry(int p,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        int ans=0;
        for(int i=0;i<k;i++)if(t[p][i]<=k)ans++;
        return ans;
    }
    if(lz[p])pd(p);
    int m=(l+r)>>1,ans=0;
    if(m>=L)ans=qry(p<<1,l,m,L,R);
    if(m<R)ans+=qry((p<<1)+1,m+1,r,L,R);
    return ans;
}
int q(int L,int R){return qry(1,1,n,L,R);}
void up(int L,int R,int v){upd(1,1,n,L,R,v);}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        if(u>v)swap(u,v);
        G[v].push_back(u);
    }
    bd(1,1,n);
    for(int r=1;r<=n;r++){
        up(1,r,1);
        for(auto u:G[r])if(u<r)up(1,u,-1);
        int c=q(1,r);
        // cout<<c<<'\n';
        ans+=c;
    }
    cout<<ans;
    return 0;
}
/*
7 2
1 4
4 2
2 6
4 3
3 5
5 7
*/