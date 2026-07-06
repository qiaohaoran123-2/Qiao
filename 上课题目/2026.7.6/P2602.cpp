#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
1. 一共有几个数位
2. 当前填入的数字和上一个数字有没有关系
3. 前导零对结果有没有影响 zero
4. 当前数字是不是上限r的一个前缀 prefix
*/
int dp[10][15][2][2], A[15];
/*
dp[x][i][Z][P]
dp表示：填入数字到第i位时，（第i位上的数字还没确定，需要枚举） 
	x在第i位到第1位一共出现了多少次
	分成2部分计算：
		从第i-1位到第1位，递归计算
		第i位：填入x时，x会多出现几次 
*/
//R表示此次计算的上界 
int dfs(int x, int i, bool Z, bool P, int R)
{
	if(i == 0) return 0;
	int& ans = dp[x][i][Z][P];
	if(ans != 0) return ans;
	int r = P ? A[i] : 9;
	for(int y = 0; y <= r; y++)
	{
		bool nP = P && y == r;
		ans += dfs(x, i - 1, Z && y == 0, nP, R);
		if(y == x && !(y == 0 && Z))
		{
			int p10 = pow(10, i - 1);
			if(nP) ans += R % p10 + 1;
			else ans += p10;
		}
	}
	return ans;
}
int solve(int x, int r)
{
	int n = 0, R = r;
	while(r)
	{
		A[++n] = r % 10;
		r /= 10;
	}
	memset(dp, 0, sizeof(dp));
	return dfs(x, n, 1, 1, R);
}
signed main(){
	int a, b;
	cin >> a >> b;
	for(int x = 0; x <= 9; x++)
		cout << solve(x, b) - solve(x, a - 1) << " ";
	return 0;
}