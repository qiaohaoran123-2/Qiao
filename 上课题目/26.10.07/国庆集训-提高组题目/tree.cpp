#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
观察性质
	对于区间[l,r]，由于它是树的诱导子图，因此它必定是森林 
	森林连通块的数量为 节点数-边数
	
	在严格小于O(n^2)的复杂度内统计区间个数，常用的方法是
		终点r从1到n枚举 
		固定终点r，统计有多少个起点l满足条件
		
	需要记录一个数组A，其中A[l]表示区间[l,r]的节点数减边数 
	在r枚举到当前位置i时
		对于每条边(u,i)（要求u<i，可以预处理）
			若l<=u，则区间[l,i]内的边数相比于[l,i-1]多了1
			即A[1...u]做一个区间减1的操作
		同时，因为i自己是一个节点，[l,i]的节点数相比于[l,i-1]多了1 
			因此A[1...i]做一个区间加1的操作 
实现
	支持区间加减的操作，可以用线段树
	线段树的节点需要保存当前节点对应的区间里，
		有多少个元素 <= K
	
	简单的线段树支持 维护最小值 和 最小值出现的次数
	在本题中，K<=5，因此可以维护最小的5个值，和它们分别出现的次数
	
	pu的写法
		合并两个节点各自K个最小值
		仿照归并排序的写法
		合并后如果不是最小的K个值，则会被淘汰	 
	初始化：
		每个位置的节点数和边数都是0，因此 
		最小值0有1个
		剩下的最小值从n+1往上取，
		为的是pu时尽可能被淘汰 
	
时间复杂度
	n次区间加操作，n-1次区间减操作，n次查询
	其中pu的复杂度是O(K) 
	O(nKlog(n)) 
*/

const int maxn = 2e5 + 5;
int mn[maxn * 4][5], mnc[maxn * 4][5], lazy[maxn * 4];
int n, K;
int matn(int o, int v)
{
	for(int i = 0; i < K; i++) mn[o][i] += v;
	lazy[o] += v;
}
int pu(int o)
{
	int lo = 2 * o, ro = 2 * o + 1;
	int i = 0, j = 0;
	for(int k = 0; k < K; k++)
	{
		if(mn[lo][i] < mn[ro][j])
		{
			mn[o][k] = mn[lo][i];
			mnc[o][k] = mnc[lo][i];
			i++;
		}
		else if(mn[lo][i] > mn[ro][j])
		{
			mn[o][k] = mn[ro][j];
			mnc[o][k] = mnc[ro][j];
			j++;
		}
		else
		{
			mn[o][k] = mn[lo][i];
			mnc[o][k] = mnc[lo][i] + mnc[ro][j];
			i++, j++;
		}
	}	
}
int pd(int o)
{
	if(lazy[o])
	{
		matn(o * 2, lazy[o]);
		matn(o * 2 + 1, lazy[o]);
		lazy[o] = 0;
	} 
}
void bd(int o, int l, int r)
{
	if(l == r)
	{
		mn[o][0] = 0;
		mnc[o][0] = 1;
		for(int i = 1; i < K; i++) mn[o][i] = n + i;
		return;
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
		matn(o, v);
		return;
	}
	int m = (l + r) / 2;
	pd(o);
	if(L <= m) upd(o * 2, l, m, L, R, v);
	if(R > m) upd(o * 2 + 1, m + 1, r, L, R, v);
	pu(o);
}
int qry(int o, int l, int r, int L, int R)
{
	if(L <= l && r <= R)
	{
		int ans = 0;
		for(int i = 0; i < K; i++)
			if(mn[o][i] <= K) ans += mnc[o][i];
		return ans;
	}
	int m = (l + r) / 2, ans = 0;
	pd(o);
	if(L <= m) ans += qry(o * 2, l, m, L, R);
	if(R > m) ans += qry(o * 2 + 1, m + 1, r, L, R);
	return ans;
}
//调试线段树专用函数 
void print(int o, int l, int r)
{
	if(l == r)
	{
		cout << ": " << l << endl;
		for(int i = 0; i < K; i++)
			cout << "\t" << mn[o][i] << " " << mnc[o][i] << endl;
		return;
	}
	int m = (l + r) / 2, ans = 0;
	pd(o);
	print(o * 2, l, m);
	print(o * 2 + 1, m + 1, r);
}
vector<int> G[maxn];
signed main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int u, v;
	cin >> n >> K;
	for(int i = 1; i < n; i++)
	{
		cin >> u >> v;
		if(u > v) swap(u, v);
		G[v].push_back(u);
	}
	bd(1, 1, n);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		upd(1, 1, n, 1, i, 1);
		for(auto u : G[i])
			upd(1, 1, n, 1, u, -1);
		int cur = qry(1, 1, n, 1, i);
//		cout << i << " th\n";
//		print(1, 1, n);
//		cout << cur << endl;
		ans += cur;
	} 
	cout << ans;
	return 0;
}
