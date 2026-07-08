#include<bits/stdc++.h>
using namespace std;
const int maxn = 1.1e7 + 5;
char s[2 * maxn];
int d[2 * maxn];
int main()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1), j;
    for(int i = 2 * n, j = n; j > 0; i -= 2)
    {
        s[i] = '#';
        s[i - 1] = s[j--];
    }
    s[0] = '#';
    int ans = 1, o = 0, R = 0;
    for(int i = 1; i <= 2 * n; i++)
    {
        if(o + R >= i)
            d[i] = min(R - i, d[2 * o - i]);
        while(i + d[i] + 1 <= 2 * n && 
			i - d[i] - 1 >= 0 && 
             s[i + d[i] + 1] == s[i - d[i] - 1]) 
			 d[i]++;
        if(i + d[i] > R)
        {
        	o = i;
			R = i + d[i]; 
		}
        ans = max(ans, d[i]);
    }
    cout << ans;
    return 0;
}
