#include<bits/stdc++.h>
using namespace std;
int a[10][10], dp[10][70];
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int N, M;
		cin >> N >> M;
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= M; j++)
				cin >> a[i][j];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= N; i++)
		{
			for(int S = 0; S < (1 << M); S++) 
				if((S & (S >> 1)) == 0)
				{
					int x = 0;
					for(int j = 0; j < M; j++) if((S >> j) & 1)
						x += a[i][j + 1];
					for(int T = 0; T < (1 << M); T++)
						if((S & T) == 0 && 
							(S & (T << 1)) == 0 && 
							(S & (T >> 1)) == 0)
							dp[i][S] = max(dp[i][S], dp[i - 1][T] + x);		
				}						
		}
		int ans = 0;
		for(int S = 0; S < (1 << M); S++)
			ans = max(ans, dp[N][S]);
		cout << ans << endl;
	}
	return 0;
}

