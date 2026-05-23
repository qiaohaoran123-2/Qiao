单调队列优化DP

能够使用单调队列进行优化的DP的特点：

状态转移方程有类似这样的形式：

dp[i] = max(dp[i - L] ... dp[i - R])

P9769
	目标：从0变成y的最少操作次数
	
	操作：
		1. x加上[1..n]中的某个数字
		2. x乘上输入的m个数字其中一个
		
	状态：dp[i]表示从0修改到i的最少操作次数

	上一步操作：
		加法：min(dp[i - 1] ... dp[i - n]) + 1
		乘法：min(dp[i / B[1]] ... dp[i / B[m]]) + 1

	dp[0] = 0

	时间复杂度：O((n + m) * y)

	加法的转移可以用单调队列优化

	队首要取出最小值，因此是单调增的单调队列

	处理队尾：保证单调增 
		while(!dq.empty() && dp[i] <= dp[dq.back()])
			dq.pop_back(); 
	处理队首：保证区间长度不超过n 
		while(!dq.empty() && i - dq.front() >= n)
			dq.pop_front();

	时间复杂度优化为：O(m * y)

P1725
	dp[i]表示走到第i个格子，能获得的最大冰冻指数
	dp[i] = max(dp[i - R] ... dp[i - L]) + A[i]

	max(dp[i - R] ... dp[i - L])用单调队列维护

	if(i + R > N)，说明i可以作为到达对岸前的最后一步
		dp[i]就要统计到答案中 


	要为计算dp[i+1]做准备，单调队列中的下标范围应该是
		[i+1-R, i+1-L]
	在第i轮for循环的最后，
		应该放入下标i+1-L（需要用到下标范围的最后一个数字）
		对于单调队列中下标在i+1-R左边的，都要出队 

	for(int i = 0; i <= N; i++)
	{
		if(i == 0) dp[i] = 0;
		else if(dq.empty()) dp[i] = -2e8;
		else dp[i] = dp[dq.front()] + A[i];
		if(i + 1 - L >= 0)
		{
			while(!dq.empty() && dp[i + 1 - L] >= dp[dq.back()])
				dq.pop_back();
			dq.push_back(i + 1 - L);
		}
		while(!dq.empty() && dq.front() < i+1-R)
			dq.pop_front();
		if(i + R > N) ans = max(ans, dp[i]);
	}

P1776
	多重背包问题，一个物品的数量是有限个
		物品数量是1个：01背包
		物品数量是无限个：完全背包

	dp[i][j]表示拿前i种物品，容量达到j时的最大价值 
	for(int i = 1; i <= n; i++) 		//i表示第i种物品 
		for(int k = 0; k <= m[i]; k++)  //第i种物品取k个 
			for(int j = k * w[i]; j <= W; j++)  //体积为j 
				dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);


	dp[i][j] = max
		dp[i - 1][j - 0 * w[i]] + 0 * v[i]
		dp[i - 1][j - 1 * w[i]] + 1 * v[i]
		dp[i - 1][j - 2 * w[i]] + 2 * v[i]
		dp[i - 1][j - 3 * w[i]] + 3 * v[i]
		...
		dp[i - 1][j - m[i] * w[i]] + m[i] * v[i]


	以具体的数字为例，w[i] = 2, v[i] = 3, j = 10, m[i] = 4

	dp[10] = max
		dp[10]
		dp[8] + 3
		dp[6] + 6
		dp[4] + 9
		dp[2] + 12

	需要取最大值的状态：相邻两个状态之间相差w[i]

dp[10] 		dp[2]+12	dp[4]+9		dp[6]+6		dp[8]+3 	dp[10]
dp[12] 					dp[4]+12 	dp[6]+9 	dp[8]+6 	dp[10]+3 	dp[12]

dp[10]-15 	dp[2]-3		dp[4]-6		dp[6]-9		dp[8]-12 	dp[10]-15
dp[12]-18 				dp[4]-6 	dp[6]-9 	dp[8]-12 	dp[10]-15 	dp[12]-18

	计算dp[k * w[i] + j]
	单调队列中，存放的是 dp[k * w[i] + j] - k * v[i]
 
	k的范围从0到 k * w[i] + j <= W

	分组单调队列 