#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int nxt[31*maxn][2],tid,a[maxn],u,v,w,n,ans=0;
struct node{int v,w;};
vector<node>g[maxn];
void dfs(int u,int p){
    for(auto [v,w]:g[u])if(v!=p){
        a[v]=a[u]^w;
        dfs(v,u);
    }
}
void insert(int a){
    int r=0;
    for(int i=30;i>-1;i--){
        int& nr=nxt[r][(a>>i)&1];
        if(nr)nr=++tid;
        r=nr;
    }
}
int find(int a){
	int r=0,ans=0;
	for(int i=30;i>-1;i--){
        int x=(a>>i)&1;
		if(nxt[r][1-x]){
			ans|=1<<i;
			r=nxt[r][1-x];
		}
		else r=nxt[r][x];
	}
	return ans;
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0);
    // for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    // cout<<'\n';
    for(int i=1;i<=n;i++)insert(a[i]);
    for(int i=1;i<=n;i++)ans=max(ans,find(a[i]));
    cout<<ans;
    return 0;
}