#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
//技巧：模板串 + # + 待匹配串，计算它的nxt
//字符串下标从1开始 
int nxt[maxn];
char s[maxn], s1[maxn];
int main()
{
    scanf("%s%s", s1, s + 1);
    int m = strlen(s1), n = strlen(s + 1);
    s[n + 1] = '#';
    memcpy(s + n + 2, s1, m * sizeof(char));
    int j = 0;
    for(int i = 2; i <= m + n + 1; i++)
    {
        while(j && s[i] != s[j + 1]) j = nxt[j];
        if(s[i] == s[j + 1]) j++;
        nxt[i] = j;
        if(j == n) printf("%d\n", i - 2 * n);
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", nxt[i]);
    return 0;
}

/*
时间复杂度分析：
势能分析j
j++最多会被执行O(n+m)次
j最小是0，最大是n
j = nxt[j]，j会变小
最多执行 O(n+m)次 
*/ 
