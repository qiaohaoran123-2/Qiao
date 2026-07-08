KMP 字符串匹配
	输入 待匹配串 T，模板串 S
	问S在T中的什么位置出现过
	
	T[1...n] S[1...m]
	
	T[i...i+m-1] = S[1...m]
	称S在T中i的位置出现过
	
for(int i = 1; i + m - 1 <= n; i++)
{
	bool flag = 1;
	for(int j = 1; j <= m; j++)
		if(T[i + j - 1] != S[j]) flag = 0;
	if(flag) cout << i << " ";
}

失配函数 nxt[1...n]
	
	对于S的每一个前缀  S[1...i]
	找到它的一个最长的后缀 S[j...i] 
	使得它同时也是S的前缀
	此时nxt[i] = i - j + 1 
	
T aaaabaaaab	
aaaaa
S[1...4]  aaaa
aaa是最长的后缀，同时也是S的前缀

T aaaabaaab
S aaaaa
   aaaa
   
   
 
