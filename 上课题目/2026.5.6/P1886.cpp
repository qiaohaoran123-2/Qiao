#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int A[maxn];
int a1[maxn], a2[maxn];
int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	deque<int> dqmax, dqmin;
	for(int i = 1; i <= n; i++)
	{
		while(!dqmax.empty() && i - dqmax.front() >= k)
			dqmax.pop_front();
		while(!dqmax.empty() && A[dqmax.back()] <= A[i])
			dqmax.pop_back();
		dqmax.push_back(i);
		a1[i] = A[dqmax.front()]; 
		
		while(!dqmin.empty() && i - dqmin.front() >= k)
			dqmax.pop_front();
		while(!dqmin.empty() && A[dqmin.back()] >= A[i])
			dqmin.pop_back();
		dqmin.push_back(i);
		a2[i] = A[dqmin.front()];
	}
	for(int i = k; i <= n; i++) printf("%d ", a2[i]);
	printf("\n");
	for(int i = k; i <= n; i++) printf("%d ", a1[i]);
	return 0;
}

