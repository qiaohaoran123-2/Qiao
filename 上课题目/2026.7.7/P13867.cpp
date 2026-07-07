#include<bits/stdc++.h>
using namespace std;
const int b = 129;
const int M = 1e9 + 7;
typedef long long ll;
const int maxn = 1e5;
char s[maxn];
ll S[maxn], B[maxn];
int n;
void Init()
{
	n = strlen(s + 1);
	B[0] = 1; 
	for(int i = 1; i <= n; i++)
	{
		S[i] = (S[i - 1] * b + s[i]) % M;
		B[i] = B[i - 1] * b % M;
	}	
}

ll Hash(int l, int r)
{
	return (S[r] + M - S[l - 1] * B[r - l + 1] % M) % M;
}
bool check(int mid)
{
	//检测长度为mid的子串的哈希值是否有只出现了一次的
	unordered_map<ll, int> C;
	int ans = 0; 	//仅出现了1次的哈希值有几个 
	for(int i = 1; i + mid - 1 <= n; i++)
	{
		ll h = Hash(i, i + mid - 1);
		if(C.find(h) == C.end()) ans++;
		else if(C[h] == 1) ans--;
		C[h]++;
	} 
	return ans;
}
int main()
{
	scanf("%s", s + 1);
	Init();
	int l = 1, r = n, ans = n;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(check(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	unordered_map<ll, int> C;
	for(int i = 1; i + ans - 1 <= n; i++)
		C[Hash(i, i + ans - 1)]++;
	for(int i = 1; i + ans - 1 <= n; i++)
		if(C[Hash(i, i + ans - 1)] == 1)
		{
			for(int j = i; j < i + ans; j++)
				printf("%c", s[j]);
			break;
		}	
	return 0;
}