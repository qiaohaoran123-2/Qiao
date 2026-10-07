#include<bits/stdc++.h>
using namespace std;
/*
观察性质
	从一个空地向左看，能看到的格子数（不包含它自己）有两种情况：
	1. 它左边是边界或者#，则数量为0
	2. 它左边是空地，则数量为从左侧空地向左看，看到的空地数量+1
	这是一个动态规划的过程，需要在4个方向上做 
实现
	技巧：
	向左和向上看，需要动态规划的方向是从上到下，从左到右
	向右和向下看，需要动态规划的方向是从下到上，从右到左
	4个方向合并成1维，用方向数组dd来确定具体是哪个方向
	P[k][i][j]表示从(i,j)向方向k看去，有多少个空地 
时间复杂度
	O(NM) 
*/

const int maxn = 2000 + 5;
char c[maxn][maxn];
int P[4][maxn][maxn], dd[] = {0, -1, 0, 1, 0};
signed main()
{
	freopen("detector.in", "r", stdin);
	freopen("detector.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> (c[i] + 1);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			for(int k = 0; k < 2; k++)
			{
				int ni = i + dd[k], nj = j + dd[k + 1];
				if(ni >= 1 && ni <= N && nj >= 1 && nj <= M && 
					c[ni][nj] != '#')
					P[k][i][j] = P[k][ni][nj] + 1;
				else P[k][i][j] = 0;
			}
	for(int i = N; i >= 1; i--)
		for(int j = M; j >= 1; j--)
			for(int k = 2; k < 4; k++)
			{
				int ni = i + dd[k], nj = j + dd[k + 1];
				if(ni >= 1 && ni <= N && nj >= 1 && nj <= M && 
					c[ni][nj] != '#')
					P[k][i][j] = P[k][ni][nj] + 1;
				else P[k][i][j] = 0;
			}
	int ans = 0;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++) if(c[i][j] == '.')
		{
			int cur = 1;
			for(int k = 0; k < 4; k++) cur += P[k][i][j];
			ans = max(ans, cur);
		}
	cout << ans;
	return 0;
}
