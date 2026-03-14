#include<bits/stdc++.h>
#define int long long
using namespace std;
int n1,n2,t[10000005],b,stk_top,sz,n,cur,ans;
struct node{
    int a,b;
};
node a[100005];
stack<int>c;
int lb(int x){return x&(-x);}
void upd(int x,int b){
    while(x<=n){
        t[x]+=b;
        x+=lb(x);
    }
}
int query(int x){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=lb(x);
    }
    return ans;
}
inline int query(int x,int y){
    if(x>y)swap(x,y);
    return query(y)-query(x-1);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n1>>n2;
    n=n1+n2+1;
    for(int i=1;i<=n1;i++){
        cin>>b;
        c.push(b);
    }
    stk_top=n1+1;
    cur=n1+1;
    while(!c.empty()){
        upd(++sz,1);
        a[sz].a=c.top();
        a[sz].b=sz;
        c.pop();
    }
    a[++sz].a=0;
    a[sz].b=sz;
    for(int i=1;i<=n2;i++){
        cin>>b;
        upd(++sz,1);
        a[sz].a=b;
        a[sz].b=sz;
    }
    sort(a+1,a+n+1,[&](node a,node b)->bool {return a.a>b.a;});
    for(int i=1;i<n;i++){
        ans+=query(a[i].b,cur)-1;
        upd(a[i].b,-1);
        cur=a[i].b;
    }
    cout<<ans;
    return 0;
}