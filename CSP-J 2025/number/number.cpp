#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],t[15],top;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)if(isdigit(s[i]))t[s[i]-'0']++;
    for(int i=9;i>=0;i--)while(t[i]--)cout<<i;
    return 0;
}