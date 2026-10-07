#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
观察性质
	当两个控制域有重合位置时，这两个控制域的并集内
		任何数字都可以移动到想去的位置
		这可以通过把其中一个数字移动到重合的位置，再移动到任意的位置上来实现
	因控制域i实际上可以把[i-Ri+1,i+Ri-1]的所有数字重排
		注意上下标不要越界 
	如果用dp[i]表示把A[1...i]排好序的最小代价
		如果A[i]本身就在应该在的位置，则dp[i] = dp[i-1] 
		如果存在一个控制域是[j,i]，代价为C
			则转移可以是dp[i] = min dp[k] + C，其中j <= k < i
			这里dp[k]要求至少有一个控制域覆盖了k，它额外需要一个状态
	重新定义dp[i][j]
		把A[1...i]排好序的情况下 
		dp[i][0]表示A[1...i]恰好就是最小的i个数时的最小代价 
		dp[i][1]表示至少一个控制域覆盖了i的最小代价
	初始化dp为INF无穷大，dp[0][0] = 0 
	转移方程为：
	对于位置i
		A[i]本身就在应该在的位置，则dp[i][0] = dp[i-1][0]
		如果存在一个控制域是[j,i]，代价为C
			则dp[i][1] = min dp[k][1] + C，其中j <= k < i
			注意：dp[i][1] 还可以用dp[j-1][0] + C更新
				表示1~j-1的数字不需要交换到后面去，也能完成排序 
			dp[i][0] 用 dp[i][1]更新 
实现
	判断每个A[i]是否就在它排序后应该在的位置上
		可以通过带下标的排序来判断 
	对控制域的终点从小到大排序，也可以用存图的方式把终点相同的区间保存到一个表内 
	动态规划
	查询 min dp[k][1]为区间最小值，可以用ST表 
	可能溢出，因此用long long 
时间复杂度
	O(nlog(n)) 
*/
const int maxn = 1e5 + 5;
struct Range
{
	int u, C;
};
vector<Range> G[maxn];
int dp[maxn][2], C[maxn];
pair<int, int> A[maxn];
int f[maxn][20];
int qry(int l, int r)
{
	int k = log2(r - l + 1);
	return min(f[l + (1 << k) - 1][k], f[r][k]);
}
signed main()
{
	freopen("anchor.in", "r", stdin);
	freopen("anchor.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A + 1, A + 1 + N);
	
	for(int i = 1; i <= N; i++) cin >> C[i];
	int R;
	for(int i = 1; i <= N; i++)
	{
		cin >> R;
		int l = max(1ll, i - R + 1), r = min(N, i + R - 1);
		if(l >= r) continue;
		G[r].push_back({l, C[i]});
	}
	
	const int INF = 0x3f3f3f3f3f3f3f3f;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	int maxId = 0; 
	for(int i = 1; i <= N; i++)
	{
		for(auto x : G[i])
		{
			dp[i][1] = min(dp[i][1], qry(x.u, i - 1) + x.C);
			dp[i][1] = min(dp[i][1], dp[x.u - 1][0] + x.C);
		}
		maxId = max(maxId, A[i].second);
		if(maxId <= i)
		{
			if(A[i].second == i) dp[i][0] = dp[i - 1][0];
			dp[i][0] = min(dp[i][0], dp[i][1]);
		}
		
		f[i][0] = dp[i][1];
		for(int j = 1; i - (1 << j) + 1 >= 1; j++)
			f[i][j] = min(f[i][j - 1], f[i - (1 << (j - 1))][j - 1]);
	}
	if(dp[N][0] == INF) cout << -1;
	else cout << dp[N][0];
	return 0;
}
