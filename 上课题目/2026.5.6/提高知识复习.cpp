最短路
	多源最短路Floyd
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				
	单源最短路Dijkstra
	struct Edge
	{
		int v, w; 	//边的终点、边权
					//最短路的终点，最短路长度
		bool operator < (const Edge& b) const
		{
			return w > b.w;
		}
	};
	int d[maxn];
	bool vis[maxn];
	vector<Edge> G[maxn];
	
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	priority_queue<Edge> pq;
	pq.push({s, 0});
	while(!pq.empty())
	{
		int u = pq.top().v; pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto e : G[u])
		{
			Edge v = {e.v, d[u] + e.w};
			if(v.w < d[v.v])
			{
				d[v.v] = v.w;
				pq.push(v);
			}
		}
	}
	
并查集
	int p[maxn]; //初始化p[i] = i
	int getP(int x)
	{
		if(x == p[x]) return x;
		return p[x] = getP(p[x]);
	}
	void lnk(int x, int y) {p[getP(x)] = getP(y);}
	bool lnk(int x, int y)
	{
		x = getP(x); y = getP(y);
		if(x == y) return 0;
		p[x] = y;
		return 1;
	}
	带权并查集
	种类并查集
	
最小生成树
	Kruskal算法
	·	对边按照边权从小到大排序
		在并查集内依次加入边
		
二叉搜索树set和map
	set<int> S;		数字按照中序遍历从小到大，不能重复 
		插入x				S.insert(x)
		删除x				S.erase(x)
		查找有没有x 		S.count(x)
		二分，找>=x的最小元素 auto p = S.lower_bound(x)
			p是迭代器
			p == S.end()说明这个元素不存在
			如果存在，cout << *p;
		前一个迭代器prev(p) 
		后一个迭代器next(p)
	map<int, int> M		键-值，键不能重复 
		M[x] = y
		auto p = M.lower_bound(x)
		p->first表示键
		p->second表示值
		
ST表
	查询区间最大值，不能有更新操作
	dp[i][j]表示起点是i，长度是1<<j区间的最大值
	for(int i = 1; i <= n; i++) scanf("%d", &dp[i][0]);
	for(int j = 1; (1 << j) <= n; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
			
	查询[l,r]的最大值
	int k = log2(r - l + 1);
	cout << max(dp[l][k], dp[r - (1 << k) + 1][k]);
	
树状数组
	标号是x的区间对应(x - lb(x), x]
	int lb(int x) {return x & -x;} 		//lowbit函数，取出x二进制的最低位的1
	void upd(int x, int v)	//更新，在A[x]上加上v 
	{ 
		while(x < maxn)
		{
			A[x] += v;
			x += lb(x);
		}
	}
	int qry(int x) 			//查询A[1...x]的前缀和 
	{
		int ans = 0;
		while(x > 0)
		{
			ans += A[x];
			x -= lb(x);
		}
		return ans;
	}
	
线段树
	查询区间和，更新区间加 
	int A[maxn], lazy[maxn];
	void matn(int o, int l, int r, int v)
	{
		A[o] += (r - l + 1) * v;
		lazy[o] += v; 
	}
	void pu(int o)
	{
		A[o] = A[2 * o] + A[2 * o + 1]; 
	}
	void pd(int o, int l, int r)
	{
		if(lazy[o])
		{
			int m = (l + r) / 2;
			matn(2 * o, l, m, lazy[o]);
			matn(2 * o + 1, m + 1, r, lazy[o]);
			lazy[o] = 0;
		}
	}
	void bd(int o, int l, int r)
	{
		if(r <= l)
		{
			A[o] = a[l];
			return 0; 
		}
		int m = (l + r) / 2;
		bd(o * 2, l, m);
		bd(o * 2 + 1, m + 1, r);
		pu(o);
	}
	void upd(int o, int l, int r, int L, int R, int v)
	{
		if(L <= l && r <= R)
		{
			matn(o, l, r, v);
			return; 
		}
		pd(o, l, r);
		int m = (l + r) / 2;
		if(L <= m) upd(2 * o, l, m, L, R, v);
		if(R > m) upd(2 * o + 1, m + 1, r, L, R, v);
		pu(o); 
	}
	int qry(int o, int l, int r, int L, int R)
	{
		if(L <= l && r <= R) return A[o];
		pd(o, l, r);
		int m = (l + r) / 2, ans = 0;
		if(L <= m) ans += qry(2 * o, l, m, L, R);
		if(R > m) ans + qry(2 * o + 1, m + 1, r, L, R);
		return ans;
	}
	
最近公共祖先LCA
	int f[maxn][20], dep[maxn];
	void dfs(int u, int p)
	{
		dep[u] = dep[p] + 1;
		f[u][0] = p;
		for(int j = 1; j < 20; j++)
			f[u][j] = f[f[u][j - 1]][j - 1];
		for(auto v : G[u]) if(v != p)
			dfs(v, u);
	}
	int lca(int u, int v)
	{
		if(dep[u] < dep[v]) swap(u, v);
		int k = dep[u] - dep[v];
		for(int j = 0; j < 20; j++) if((k >> j) & 1)
			u = f[u][j];
		if(u == v) return u;
		for(int j = 19; j >= 0; j--)
			if(f[u][j] != f[v][j])
			{
				u = f[u][j];
				v = f[v][j];
			}
		return f[u][0];
	}
	
树的直径和重心
	直径：
		做法1：两遍dfs，第一遍找任意起点u的最远点a，第二遍找a的最远点b，a到b就是直径
		做法2：树上dp，dp[u]表示从u出发向下走能最远走的距离
			把最远距离和第二远的距离加起来，就是经过u的最长路径
	重心：换根DP
	
树上DP
	从叶子到根的DP
	树上背包
	换根DP	
