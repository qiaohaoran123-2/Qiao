#include<bits/stdc++.h>
using namespace std;
int a[105][15], d[1100];
int main()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	memset(d, -1, sizeof(d));
	int s = (1 << n) - 1;
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i = 1; i <= m; i++)
		{
			int v = 0;
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j] == 1) ;
				else if(a[i][j] == -1) v |= (1 << (j - 1)); 
				else
				{
					int b = (u >> (j - 1)) & 1;
					v |= (b << (j - 1));
				}
			}
			if(d[v] == -1)
			{
				d[v] = d[u] + 1;
				q.push(v);
			} 
		}
	}
	cout << d[0];
	return 0;
}

