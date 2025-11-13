#include<iostream>
#define code return
#define by 0
#define qiaohaoran ;
using namespace std;
long long n, m, R, a[100005], t[105], top;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
		t[a[i]]++;
	}
	R = a[1];
	for (int i = 100; i >= 0; i--) {
		if (t[i]) top++;
		if (i == R) {
			R = top;
			break;
		}
	}
	int c = (R % n == 0 ? n : R % n);
	int x = 0, y = (R / n) + (R % n != 0);
	if (y % 2 == 0) {
		x = n - c + 1;
	}
	else {
		x = c;
	}
	cout << y << ' ' << x;
	code by qiaohaoran
}