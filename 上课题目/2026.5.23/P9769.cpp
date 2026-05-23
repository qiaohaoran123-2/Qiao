#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 5;
int dp[maxn], B[15];
int main()
{
	int y, n, m;
	cin >> y >> n >> m;
	for(int i = 1; i <= m; i++) cin >> B[i];
	deque<int> dq;
	dq.push_back(0);
	for(int i = 1; i <= y; i++)
	{
		dp[i] = dp[dq.front()] + 1; 	//加法的转移
		for(int j = 1; j <= m; j++) if(i % B[j] == 0 && B[j] > 1)
			dp[i] = min(dp[i], dp[i / B[j]] + 1);  	//乘法的转移
		while(!dq.empty() && dp[i] <= dp[dq.back()])
			dq.pop_back();
		while(!dq.empty() && i - dq.front() >= n)
			dq.pop_front(); 
		dq.push_back(i);
	}
	cout << dp[y];
	return 0;
}