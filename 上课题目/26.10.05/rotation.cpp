#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
两个位置最终有可能相遇，要求这两个位置能到达的地方有共同的位置
如果一次询问的a,b不相同，且层数不同，那只可能有一个相遇点或没有相遇点
如果a,b不同，层数相同，那一定没有相遇点
如果a,b相同，层数相同，那只可能有一个相遇点或没有相遇点
如果a,b相同，层数不同，那一定没有相遇点
可以预处理出来从某个点i，指针为j，跳2^c的点在哪里
对于a,b不相同，且层数不同，如果能够相遇，时间一定是层数之差除以a,b之差
可以去尝试这个时间是不是整数，跳到的是不是一个点，使用之前预处理过的，时间O(log n)
对于a,b相同，层数相同，可以找可能相遇的那些点，然后判断是不是整数秒
找这些点的时间复杂度O(log n)

预处理实现方式：
要跳2^c次，分成两部分
先跳2^(c-1)次，跳到f[i][j][c-1]
再跳2^(c-1)次，跳到f[f[i][j][c-1]][(j+(1<<(c-1)))%k][c-1]
也就是直接跳到f[f[i][j][c-1]][(j+(1<<(c-1)))%k][c-1]
为了防止访问到没处理的地方，用dfs处理

总时间复杂度为预处理+回答，为O(nk log n +q log n)
空间复杂度为预处理需要O(nk log n)
可以通过此题
*/
const int maxn=2e5+5;
int n,k,q,x,y,a,b,h[maxn],f[maxn][10][25];
vector<int>G[maxn];
int dfs(int i,int j,int c){
    if(c==0)return G[i][j]==0?-1:G[i][j];
    int &ans=f[i][j][c];
    if(ans!=-1)return ans;
    if(dfs(i,j,c-1)==-1)return -1;
    return ans=dfs(dfs(i,j,c-1),(j+(1<<(c-1)))%k,c-1);
}
int lb(int x){return x&(-x);}
signed main(){
    freopen("rotation.in","r",stdin);
    freopen("rotation.out","w",stdout);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++){
        G[i].resize(k);
        for(int j=1;j<=k;j++)cin>>G[i][j];
    }
    memset(f,-1,sizeof(f));
    /*
    分四种情况
    如果一次询问的a,b不相同,且层数不同，那只可能有一个相遇点或没有相遇点   ok
    如果a,b不同,层数相同,那一定没有相遇点                               ok
    如果a,b相同，层数相同，那只可能有一个相遇点或没有相遇点
    如果a,b相同，层数不同，那一定没有相遇点
    */
    while(q--){
        cin>>x>>y>>a>>b;
        if(a!=b){
            if(h[x]==h[y]){
                if(x==y)cout<<"0\n";
                else cout<<"-1\n";
                continue;
            }
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
            //以下是尝试往下跳
            int d=x,dd=y;//x和y跳完了以后的位置
            int p1=0,p2=0;//转盘
            bool f=0;
            while(cx){//x跳
                int T=lb(cx);
                d=dfs(d,p1,63-__builtin_clzll(T));
                if(d==-1){
                    cout<<"-1\n";
                    f=1;
                    break;
                }
                p1=(p1+T)%k;
                cx-=T;
            }
            while(cy){//y跳
                int T=lb(cy);
                dd=dfs(dd,p2,63-__builtin_clzll(T));
                if(dd==-1){
                    cout<<"-1\n";
                    f=1;
                    break;
                }
                p2=(p2+T)%k;
                cy-=T;
            }
            if(f)continue;
            if(d==dd)cout<<t<<'\n';
            else cout<<"-1\n";
        }
        else{
            if(h[x]!=h[y]){
                cout<<"-1\n";
                continue;
            }
        }
    }
    return 0;
}