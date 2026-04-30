#include<bits/stdc++.h>
using namespace std;
/*
树上背包问题：
对于每一门课，体积是1，价值是s[i]
背包容量是M

把每个子树的背包问题都解决出来
对于当前子树的根，把它所有的子节点的背包问题都解决
然后再合并 
*/
const int maxn = 305;
int dp[maxn][maxn], s[maxn];
vector<int> G[maxn]; 
void dfs(int u)
{
	dp[u][1] = s[u];
	for(auto v : G[u])
	{
		dfs(v);
		for(int j = M; j >= 1; j--)
			for(int i = 1; i + (u != 0) <= j; i++)
				dp[u][j] = max(dp[u][j], dp[u][j - i] + dp[v][i]);
		
		/*
		内层循环不能写成for(int i = 1; i <= j; i++)
			当i == j时，dp[u][j - i]表示根节点不学课程
			如果根节点不学课程，是不能允许子节点学课程的 
			不过有一个点是例外，就是0号节点 
		*/ 
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		int k;
		cin >> k >> s[i];
		G[k].push_back(i);
	}
	dfs(0);
	cout << dp[0][M];
	return 0;
}