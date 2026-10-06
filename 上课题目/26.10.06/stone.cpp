#include<bits/stdc++.h>
using namespace std;
/*
观察性质：

可以发现，如果重排以后的序列是$a_1~a_n，b_1~b_n$，那么损耗为、

$0+a_1*b_2+(a_1+a_2)*b_3+...+(a_1+...+a_(n-1))*b_n$

可以发现，a_n和b_1完全没有被用到

设s_i=a_1+...+a_i(不随a_i变化)

则损耗转为

$s_1*b_2+s_2*b_3+...+s_{n-1}*b_n$

$=\sum_{i=1}^{n-1} s_i \times b_{i+1}$

假如说交换a_i和a_{i+1}，则原式变为

$s_1*b_2+...+(s_i-a_i+a_{i+1})*b_{i}+s_{i+1}*b_{i+2}+...$

两式做差，得 $a_ib_{i+1}-a_{i+1}b_i$

也就是，交换两个数会导致减少$a_ib_{i+1}-a_{i+1}b_i$

如果交换的是不相邻的两个数 $a_i$ 和 $a_j$ $(i \leq j)$

贪心地想，如果$a_ib_{i+1}-a_{i+1}b_i$是正数，那么就交换这两个数字，以达到最小值
*/
int main(){
    cin.tie(0)->sync_with_stdio(false);
    return 0;
}