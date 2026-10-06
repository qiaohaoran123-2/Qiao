#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,k,q,x,y,a,b,h[maxn],f[maxn][10][35],t[maxn],c[maxn],tp;
vector<int>G[maxn];
vector<int>g[maxn];
int lb(int x){return x&(-x);}
int getd(int d,int x){
    int p=0;
    while(x){
        int T=lb(x);
        d=f[d][p][63-__builtin_clzll(T)];
        p=(p+T)%k;
        x-=T;
    }
    return d;
}
signed main(){
    // freopen("rotation.in","r",stdin);
    // freopen("rotation.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++){
        G[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>G[i][j];
            g[G[i][j]].push_back(i);
            if(G[i][j]!=0)c[i]++;
        }
    }
    queue<int>qu;
    for(int i=1;i<=n;i++)if(c[i]==0)qu.push(i);
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		t[++tp]=u;
		for(auto v:g[u])if(--c[v]==0)qu.push(v);
	}
    for(int j=0;j<k;j++)for(int i=1;i<=n;i++){
        int u=t[i];
        if(G[u][j]==0)f[u][j][0]=u;
        else f[u][j][0]=G[u][j];
        for(int c=1;c<=30;c++)
            f[u][j][c]=f[f[u][j][c-1]][(j+(1ll<<(c-1ll)))%k][c-1];
    }
    while(q--){
        cin>>x>>y>>a>>b;
        if(a!=b){
            if(h[x]==h[y]){
                if(x==y)cout<<"0\n";
                else cout<<"-1\n";
                continue;
            }
            if(h[y]>h[x])swap(x,y),swap(a,b);
            int t=(h[x]-h[y])/(b-a);
            if(t<0){//永远追不上层数
                cout<<"-1\n";
                continue;
            }
            if((h[x]-h[y])%(b-a)!=0){//时间不是整数
                cout<<"-1\n";
                continue;
            }
            int cx=a*t,cy=b*t;//x和y走的次数
            int d=getd(x,cx),dd=getd(y,cy);//x和y跳完了以后的位置
            if(d==dd)cout<<t<<'\n';
            else cout<<"-1\n";
        }
        else{
            int l=0,r=n,ans=-1;
            while(l<=r){
                int m=(l+r)>>1ll;
                int d1=getd(x,m),d2=getd(y,m);
                if(d1==d2)r=(ans=m)-1;
                else l=m+1;
            }
            // if(x==1&&y==3&&a==1&&b==1)cout<<ans<<' '<<getd(x,ans)<<' '<<getd(y,ans)<<'\n';
            if(ans==-1)cout<<"-1\n";
            else{
                int c=((ans/a)+(ans%a==0?0:1))*a;
                cout<<c/a<<'\n';
            }
        }
    }
    return 0;
}
/*
8 2 5
0 0 1 1 2 2 3 3
3 4
4 3
5 6
5 6
7 8
8 7
0 0
0 0
1 2 1 1
1 2 2 2
1 6 3 1
2 5 1 3
1 3 1 1
*/