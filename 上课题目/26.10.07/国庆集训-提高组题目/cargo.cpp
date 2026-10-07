#include<bits/stdc++.h>
using namespace std;
/*
观察性质
	对于选出的K个货物，如果知道其最大附加价值V
	则剩余K-1个货物在附加价值不超过V的情况下
	贪心选尽可能大的基础价值
实现
	对附加价值x排序
	从第K小的附加价值V[K]开始，
	对于第i个物品，每次找到[1...i-1]中最大的K-1个W
	可以用优先队列维护
	可能溢出，因此用long long
时间复杂度
	O(nlog(n)) 
*/
const int maxn = 5e5 + 5;
struct Good
{
	int W, V;
	bool operator < (const Good& b)
	{
		return V < b.V;
	}
};
Good A[maxn];
int main()
{
	freopen("cargo.in", "r", stdin);
	freopen("cargo.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	typedef long long ll;
	int N, K;
	cin >> N >> K;
	for(int i = 1; i <= N; i++) cin >> A[i].W >> A[i].V; 
	sort(A + 1, A + 1 + N);
	priority_queue<int, vector<int>, greater<int> > pq;
	ll ans = 0, S = 0;
	for(int i = 1; i < K; i++)
	{
		pq.push(A[i].W);
		S += A[i].W;
	}
	for(int i = K; i <= N; i++)
	{
		//cout << S << " " << A[i].W << " " << A[i].V << endl;
		ans = max(ans, S + A[i].W + A[i].V);
		pq.push(A[i].W);
		S += A[i].W;
		S -= pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
} 
