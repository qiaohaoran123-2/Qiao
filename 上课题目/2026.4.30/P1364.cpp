#include<bits/stdc++.h>
using namespace std;
/*
第一遍dfs:
	医院建到根节点上的距离和
	每棵子树的居民人口总数
第二遍dfs:
	dp的根从树根开始移动，每次向子节点移动时
		子节点所在子树内，所有居民少走1步
		子树外的所有居民多走1步 
*/
const int maxn = 105;
vector<int> G[maxn];
int ANS, w[maxn], sz[maxn];
bool p[maxn];
int dfs1(int u)
{
	int ans = 0;
	sz[u] = w[u];
	for(auto v : G[u])
	{
		ans += dfs1(v);
		sz[u] += sz[v];
		ans += sz[v];
	}
	return ans;
}
int n, u, v, rt;
void dfs2(int u, int ans)
{
	ANS = min(ANS, ans);
	for(auto v : G[u])
		dfs2(v, ans - sz[v] + (sz[rt] - sz[v]));
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i] >> u >> v;
		if(u) G[i].push_back(u);
		if(v) G[i].push_back(v);
		p[u] = p[v] = i;
	}
	for(int i = 1; i <= n; i++)
		if(!p[i]) rt = i;
	int ans = dfs1(rt);
	ANS = 1e9;
	dfs2(rt, ans);
	cout << ANS;
	return 0;
}