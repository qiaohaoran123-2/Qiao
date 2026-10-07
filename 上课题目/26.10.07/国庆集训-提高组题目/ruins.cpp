#include<bits/stdc++.h>
using namespace std;
#define int long long 
/*
观察性质
	从贪心角度出发，一旦探险家遇到一个未收集的能量源，
	则会立刻收集它，而不会刻意留着等待以后去收集
	因此收集过的能量源必定是一段连续的区间[i,j]，并且此时
	探险家停留在i或者j，而不可能是中间的某处
	
	因此可以定义状态dp[i][j][k]
	表示从
		[i,j]区间的能量都收集完
		并且探险家位于i(k==0)或j(k==1)时
	的状态出发，到收集完全部能量源，所需的最小初始能量 
	
	注意：由于探险家最后停在i（或j）处，这里的能量对
		探险家完成这个收集过程没有任何帮助 
	
	题目求每个dp[i][i][0] 
	
实现
	初始化dp[1][N][0] = dp[1][N][1] = 0 
	
	计算顺序：按照收集区间从大到小计算
	从i,j,0出发（探险家位于i处），可以走到i-1,j,0或者i,j+1,1
	从i,j,0走到i-1,j,0的长度是x[i]-x[i-1]
		这样所需要的总能量为ES = x[i] - x[i-1] + dp[i-1][j][0]
		如果x[i]处的能量v[i] >= ES，则不需要额外的初始能量
		否则初始能量就是ES-v[i]
	其他情况可以类似讨论 
		
	如果没有任何能量，从中间某处降落，先向左后向右也要走3*10^9的距离
	因此用long long避免溢出 
时间复杂度
	O(N^2) 
*/

const int maxn = 3000 + 5;
int dp[maxn][maxn][2], x[maxn], v[maxn];
const int INF = 1e18; 
signed main()
{
	freopen("ruins.in", "r", stdin);
	freopen("ruins.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> x[i] >> v[i];
	dp[1][N][0] = dp[1][N][1] = 0;
	int cur, ES;
	for(int l = N - 1; l >= 1; l--)
		for(int i = 1; i + l - 1 <= N; i++)
		{
			int j = i + l - 1;
			dp[i][j][0] = dp[i][j][1] = INF;
			if(i > 1)
			{
				ES = x[i] - x[i - 1] + dp[i - 1][j][0];
				cur = max(0ll, ES - v[i]);
				dp[i][j][0] = min(dp[i][j][0], cur);
				
				ES = x[j] - x[i - 1] + dp[i - 1][j][0];
				cur = max(0ll, ES - v[j]);
				dp[i][j][1] = min(dp[i][j][1], cur);
			}
			if(j < N)
			{
				ES = x[j + 1] - x[i] + dp[i][j + 1][1];
				cur = max(0ll, ES - v[i]);
				dp[i][j][0] = min(dp[i][j][0], cur);
				
				ES = x[j + 1] - x[j] + dp[i][j + 1][1];
				cur = max(0ll, ES - v[j]);
				dp[i][j][1] = min(dp[i][j][1], cur);
			}
		}
	for(int i = 1; i <= N; i++)
		cout << dp[i][i][0] << " ";
	return 0;
}
