#include<bits/stdc++.h>
using namespace std;
/* 
1. 一共有几个数位
2. 当前填入的数字和上一个数字有没有关系
3. 前导零对结果有没有影响 zero
4. 当前数字是不是上限r的一个前缀 prefix
dp表示在当前条件下，满足题目要求的数字有几个
dfs的每一步试图在第i位填入数字x
*/
int dp[15][10][2][2], A[15];
int dfs(int i, int last, bool Z, bool P)
{
	if(i == 0) return 1;
	int& ans = dp[i][last][Z][P];
	if(ans != -1) return ans;
	ans = 0;
	int r = P ? A[i] : 9;
	for(int x = 0; x <= r; x++)
		if(Z || abs(x - last) >= 2)
			ans += dfs(i - 1, x, 
			Z && x == 0,
			P && x == r);
	return ans;
}
int solve(int r)
{
	int n = 0;
	while(r)
	{
		A[++n] = r % 10;
		r /= 10;
	}
	memset(dp, -1, sizeof(dp));
	return dfs(n, 0, 1, 1);
}
int main()
{
	int a, b;
	cin >> a >> b; 
	cout << solve(b) - solve(a - 1);
	return 0;
}