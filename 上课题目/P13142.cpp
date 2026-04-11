#include<bits/stdc++.h>
using namespace std;
int n,t,l,sss;
bool f;
string s;
string ss;
string ans;
set<string>st;
void dfs(int p,int lastn){
    if(f)return;
    if(p>l){
        if(!st.count(ans))cout<<ans<<'\n';
        f=1;
        return;
    }
    for(int i=lastn+1;i<ss.size();i++){
        ans[p]=ss[i];
        dfs(p+1,i);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        sss++;
        cin>>n>>s;
        ss=s;
        l=s.size();
        f=0;
        ans.resize(l);
        for(int i=2;i<=n;i++){
            cin>>s;
            ss+=s;
        }
        cout<<"Case #"<<sss<<":";
        dfs(0,-1);
        if(!f)cout<<"-\n";
    }
    return 0;
}