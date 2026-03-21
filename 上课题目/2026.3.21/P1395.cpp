#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
int n,u,v,c[maxn],ans,ans2,k[maxn];
vector<int>g[maxn];
int dfs(int u,int p){
    int C=1;
    for(auto v:g[u])if(v!=p){
        int Cv=dfs(v,u);
        C+=Cv;
        c[u]=max(c[u],Cv);
    }
    c[u]=max(c[u],n-C);
    return C;
}
void dfs2(int u,int p){
    cout<<u<<'\n';
    for(auto v:g[u])if(v!=p){
        cout<<v<<' ';
        k[v]=k[u]+1;
        dfs(v,u);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans=1;
    dfs(1,0);
    for(int i=1;i<=n;i++)ans=c[i]<c[ans]?i:ans;
    dfs2(ans,0);
    // for(auto v:g[2])cout<<v<<' ';
    // cout<<'\n';
    for(int i=1;i<=n;i++)ans2+=k[i];
    cout<<ans<<' '<<ans2;
    return 0;
}