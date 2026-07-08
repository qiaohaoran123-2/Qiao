
const int maxn = 1e6 + 5;
char s1[maxn], s2[maxn];
int nxt[maxn];

int m = strlen(s1 + 1);
int n = strlen(s2 + 1);

nxt[1] = 0;
int j = 0;
for(int i = 2; i <= n; i++)
{
	while(j && s2[i] != s2[j + 1]) j = nxt[j];
	if(s2[i] == s2[j + 1]) j++;
	nxt[i] = j;
}

int j = 0;
for(int i = 2; i <= m; i++)
{
	while(j && s1[i] != s2[j + 1]) j = nxt[j];
	if(s1[i] == s2[j + 1]) j++;
	if(j == n) cout << i - j + 1 << endl;
}

对于S[1...i]，找到它最长的前缀S[1...j]
使得S[1...j]同时也是S[1...i]的后缀
nxt[i] = j 

1. aaaab 		0 1 2 3 0
2. baaaa		0 0 0 0 0
3. abcabcabc 	0 0 0 1 2 3 4 5 6
4. abcbabcba 	0 0 0 0 1 2 3 4 5

周期串，由同一个字符串拼接多次得到 
S = abababab
S = abcabcabc
S = dcbadcbadcba

S = abababa 

最小周期：最短的能够拼成S的字符串
非周期串的最小周期就是字符串本身 

怎样利用nxt计算字符串的最小周期
	n - nxt[n]是可能的最小周期
	如果n - nxt[n]能整除n，那它就是最小周期
	否则它不是周期串 






ababc  	 0 0 1 2 0

循环 i = 2, j = 0
	nxt[2] = 0 
循环 i = 3, j = 0
	 j = 1
	 nxt[3] = 1
循环 i = 4, j = 1
	 j = 2
	 nxt[4] = 2
循环 i = 5, j = 2
	j = nxt[j] = 1
	j = nxt[j] = 0
	nxt[5] = 0

ababc
  ababc
  	ababc
	 
