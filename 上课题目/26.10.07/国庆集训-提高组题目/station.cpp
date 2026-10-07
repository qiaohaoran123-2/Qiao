#include<bits/stdc++.h>
using namespace std;
/*
观察性质
	半径的2倍就是这个基站的覆盖范围，它是一个区间 
	所有基站半径之和的2倍最小，即所有基站的覆盖范围尽可能小 
	由于P和R可以任选，为了达到目标 
	每个覆盖范围的两端必定为设备（再多一些没有意义，反而会让半径更大）
	因此目标变为用K个区间覆盖N个设备，区间长度之和最小 
	反过来考虑，没被覆盖的区间一定是形如X[i+1]-X[i]的段
	找到这些段中最大的K-1个，它们把总区间切分为K段基站范围 
	总区间的长度减去这些区间即可 
实现
	对差分X[i+1]-X[i]从大到小排序即可 
时间复杂度
	O(nlog(n)) 
*/
const int maxn = 2e5 + 5;
int d[maxn];
int main()
{
	freopen("station.in", "r", stdin);
	freopen("station.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	int N, K, X;
	cin >> N >> K >> X;
	int cur, last = X; 
	for(int i = 2; i <= N; i++)
	{
		cin >> cur;
		d[i - 1] = cur - last;
		last = cur;
	}
	sort(d + 1, d + N);
	int ans = cur - X;
	for(int i = N - 1; i >= N - K + 1; i--) ans -= d[i]; 
	cout << ans;
	return 0;
} 
