#include<bits/stdc++.h>
using namespace std;
/*
观察性质
	在所有排列中找到最优的，可以考虑邻项交换法
	有两个符石(a1,b1) (a2,b2)，在当前能量是s的情况下
	如果先1后2，则损耗为
		s*b1 + (s+a1)*b2 = s*(b1+b2) + a1 * b2
	如果先2后1，则损耗为
		s*b2 + (s+a2)*b1 = s*(b1+b2) + a2 * b1
	
	如果a1 * b2 < a2 * b1，则说明先1后2的方案更好
	否则就要交换两个符石的顺序 

	任意相邻的两个符石都可以用以上规则判断大小
	根据冒泡排序的流程，等价于用上面的比较函数排序
	
	统计有多少放入的顺序，其实是统计排序结果有多少种
	只有a1 * b2 == a2 * b1的两个符石可以交换顺序而答案不变
	在排序之后，关键字相同的会被排到一起 
	因此每找到长度为x的、关键字相同的一段
	方案数就会乘上x! 
	
实现
	根据a1 * b2 < a2 * b1给符石排序
	如果二者相等，则按照编号排序（满足字典序最小）
	统计相邻的相同段，累乘方案数
时间复杂度
	排序，O(nlog(n)) 
*/

struct Stone
{
	int a, b, id;
	bool operator < (const Stone& y)
	{
		int l = a * y.b, r = b * y.a;
		if(l != r) return l < r;
		return id < y.id; 
	}
	bool operator == (const Stone& y)
	{
		return a * y.b == b * y.a;
	}
};
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
Stone A[maxn];
signed main()
{
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> A[i].a >> A[i].b;
		A[i].id = i;
	}
	sort(A + 1, A + 1 + n);
	ll s = 0, ans = 0, cnt = 1, x = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += s * A[i].b;
		s += A[i].a;
		if(i > 1 && A[i] == A[i - 1]) x++;
		else x = 1;
		cnt = cnt * x % mod;
	}
	cout << ans << " " << cnt << endl;
	for(int i = 1; i <= n; i++)
		cout << A[i].id << " ";
	return 0;
}
