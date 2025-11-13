#include<bits/stdc++.h>
using namespace std;
long long ans,a[5005],n;
void dfs(long long f,long long maxn,long long p,long long sum,long long lastn){
	if(p>f){
		if(sum-maxn>maxn)ans++;
		return;
	}
	for(int i=lastn+1;i<=n;i++){
		dfs(f,max(maxn,a[i]),p+1,sum+a[i],i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		dfs(i,0,1,0,0);
	}
	cout<<ans;
	return 0;
}