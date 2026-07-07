#include<bits/stdc++.h>
using namespace std;

const int b = 129;
const int M = 1e9 + 7;
typedef long long ll;
const int maxn = 1505;
char s[maxn];
ll Hash(char s[])
{
	int n = strlen(s + 1);
	ll S = 0;
	for(int i = 1; i <= n; i++)
		S = (S * b + s[i]) % M;
	return S;
}

int main()
{
	set<ll> S;
	int N;
	cin >> N;
	while(N--)
	{
		scanf("%s", s + 1);
		S.insert(Hash(s));
	}
	cout << S.size();
	return 0;
}