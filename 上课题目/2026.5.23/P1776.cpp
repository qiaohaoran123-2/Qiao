#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxW = 4e4 + 5;
int dp[maxW];
int main()
{
	int n, W, v, w, m;
	cin >> n >> W;
	for(int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &v, &w, &m);
        for(int j = 0; j < w; j++) 			//分组单调队列 
        {
            deque<pair<int, int> > dq;
            for(int k = 0; k * w + j <= W; k++)
            {
                int x = dp[j + k * w] - k * v;
                while(!dq.empty() && dq.back().second <= x) dq.pop_back();
                dq.push_back({k, x});
                while(!dq.empty() && dq.front().first + m < k) dq.pop_front();
                dp[j + k * w] = max(dp[j + k * w], dq.front().second + k * v);
            }
        }
    }
	cout << dp[W];
	return 0;
}
