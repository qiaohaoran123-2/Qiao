#include<bits/stdc++.h>
using namespace std;
int A[105], B[105], d[1100];
/*
A[i]表示第i个开关一定要关上的灯
B[i]表示第i个开关一定要打开的灯 
*/
int main()
{
	int n, m, a;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		A[i] = (1 << n) - 1; 
		for(int j = 1; j <= n; j++)
		{
			cin >> a;
			if(a == 1) A[i] ^= 1 << (j - 1);
			else if(a == -1) B[i] ^= 1 << (j - 1);
		}
	}
		
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
			int v = (u & A[i]) | B[i];
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

