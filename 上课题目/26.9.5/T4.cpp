#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,u,v,p[maxn],tm[maxn*4],tc[maxn*4],lz[maxn*4];
void pu(int p){
    tm[p]=min(tm[p<<1],tm[(p<<1)+1]);
    tc[p]=(tm[p]==tm[p<<1]?tc[p<<1])+(tm[p]==tm[(p<<1)+1]?tc[(p<<1)+1]);
}
void matn(int p,int v){
    lz[p]+=v;
    tm[p]+=v;
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
int main(){
    cin.tie(0)->sync_with_stdio(false);
    return 0;
}