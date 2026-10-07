#include<bits/stdc++.h>
using namespace std;
/*
观察性质
	机器人当前的状态有2个：节点编号u，轮转指针p
	从这个状态出发，下一个状态是：
		如果g[u][p] == 0，则状态不变
		否则，节点变为g[u][p]，指针变为(p+1)%k
	有了走1步的状态，就可以计算走x步的状态
	为了加速，可以用倍增来实现log(x)复杂度走x步
	
	注意：因为图最多有n层，因此最多只会走n步，多余的步数会停在原地不动 
	
	对于两个机器人(x,a)和(y,b)
	它们相遇有两种可能：
		1. 在非终点相遇
		2. 在终点相遇 
	
	1. 在非终点相遇
		如果a == b
			如果h[x] == h[y]
				则接下来的每一步，它们都在同一层
				并且它们的轮转指针同步变化
				因此只要它们相遇了，之后会一直相遇
				可以用二分找到最小时间
			否则
				除非到了终点，否则它们层数永远不同，永不相遇 
		否则
			解方程h[x] + t*a == h[y] + t*b
			t = (h[y]-h[x])/(a-b)，必须是非负整数解才能相遇
			可以得到一个解t 
	2. 在终点相遇
		直接用二分找相遇的最小时间即可
		可以得到一个二分的解ans
	
	在排除-1之后，取ans和t的最小值 
	
实现
	nk < 4e5，可以考虑将u和p压缩为一个状态来节省空间 
	倍增法实现log(x)复杂度内走x步
	二分查找x走t * a步，y走t * b步之后它们是否相遇 
时间复杂度
	二分+倍增有2个log 
	O(nk * log(n) + q * (log(n))^2) 
*/
const int maxn = 2e5 + 5;
int n, k, h[maxn], g[maxn][10];
const int maxnk = 4e5 + 5;
int dp[maxnk][20];

typedef long long ll;
int qry(int i, int j, ll c)
{
	if(c > n) c = n;
	int nk = j * n + i;
	for(int b = 19; b >= 0; b--) if((c >> b) & 1)
		nk = dp[nk][b];
	
	//cout << i << " " << j << " " << c << " " <<  nk % n << " " << nk / n << endl;
	
	return nk % n;
}
int bisearch(int x, int y, int a, int b)
{
	int l = 0, r = n, ans = -1;
	while(l <= r)
	{
		ll mid = (l + r) / 2;
		if(qry(x, 0, mid * a) == qry(y, 0, mid * b))
			r = (ans = mid) - 1;
		else l = mid + 1;
	}
	return ans;
}

signed main()
{
	freopen("rotation.in", "r", stdin);
	freopen("rotation.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int q;
	cin >> n >> k >> q;
	for(int i = 0; i < n; i++) cin >> h[i];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k; j++)
		{
			cin >> g[i][j];
			g[i][j]--;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k; j++)
		{
			int nk = j * n + i;
			if(g[i][j] == -1) dp[nk][0] = nk;
			else dp[nk][0] = (j + 1) % k * n + g[i][j];
		}	
	for(int x = 1; x < 20; x++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < k; j++)
			{
				int nk = j * n + i;
				dp[nk][x] = dp[dp[nk][x - 1]][x - 1];
			}
	int x, y, a, b;
	for(int i = 1; i <= q; i++)
	{
		cin >> x >> y >> a >> b;
		x--; y--;
		
		if(a == b) cout << bisearch(x, y, a, b) << endl;
		else
		{
			int A = h[y] - h[x], B = a - b;
			if(A % B || A / B < 0)
				cout << bisearch(x, y, a, b) << endl;
			else
			{
				int t = A / B;
				int ans = bisearch(x, y, a, b);
				if(qry(x, 0, t * a) == qry(y, 0, t * b))
				{
					if(ans == -1) ans = t;
					else ans = min(ans, t);
				}
				cout << ans << endl;
			}
		}	
	}
	return 0;
}
