P3435
	string A, B, C 
	A = B + C
	真前缀：既不是空，也不是整个字符串的前缀
	
	A =  ababab|a
	Q =  ababab|
	QQ = ababab|ababab
	
	Q的前缀能够匹配A的后缀
	A的前缀能够匹配A的后缀
	问题变成求A的nxt
	nxt[n]就是最长的
		既是A的前缀，也是A的后缀的字符串长度 
	
P4824
	whatthemomooofun
	moo
	
	whatthemo ofun
	
	whatthefun
	
	在KMP的过程中，如果出现nxt[i] == n
	则让i向回走n的距离，在这个位置继续匹配
	
P2375
	对于S[1...i]，既是它的前缀，又是它的后缀
	的最长字符串是S[1...nxt[i]]
	
	num[i]指的是这样既是前缀又是后缀的字符串有几个
	第一个满足条件的串  S[1...nxt[i]]
	第二个满足条件的串  S[1...nxt[nxt[i]]]
	
	num[i] = num[nxt[i]] + 1	
	
