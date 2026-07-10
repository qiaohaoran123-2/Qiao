数论
	整除 |
		a | b  	a整除b  b % a == 0
		除 除以  以……除
		4除8   8除以4   用4来切分8
		
		下面a > 0, b > 0, c > 0
		a|a 自反性 
			满足自反性的关系运算
			== >= <=
		如果a != b，a|b 说明 b不整除a
			反对称性 
		如果 a|b  b|c 那么 a|c
			传递性 
		
		如果a是质数，a|(mn)，那么a|m或者a|n
		6|(4*9)
	
	同余
		如果a%m == b%m
		就称a和b同余（在模m意义下）
		同余满足自反性、对称性、传递性
		0 <= a%m < m 
		
		(a+b)%m = (a%m + b%m) % m
		减法取模 (a%m + m - b%m) % m
		a*b%c = ((a%m)*(b%m)) % m，注意溢出
	
	gcd与lcm（最大公约数 与 最小公倍数）
		对于a,b > 0
		如果d|a 并且d|b，称d是a和b的公约数
		把a和b的所有公约数从小到大排成一排
		d1 d2 ... dn
		d1 == 1，dn是gcd(a,b)
		di | dn
		
		对于a,b > 0
		如果a|d 并且d|b，称d是a和b的公倍数
		把a和b的所有公倍数从小到大排成一排
		d1 d2 ... dn
		d1 = lcm(a,b) ，某个di == a*b
		di = i * d1，即d1 | di
		
		假设a>=b>0
		如果d|a, d|b，那么d|(a-b)
		如果a - 2b >= 0， 那么d|(a-2b)
		...
		如果a - kb >= 0，那么d|(a-kb)
		k最大是[a/b]，此时a-kb = a%b
		gcd(a,b) == gcd(b, a%b)
		
		证明__gcd(a,b)时间复杂度是log(max(a,b))
		第一步：如果a < b
			此时gcd(a,b) == gcd(b,a)，转第二步
		第二步：如果a >= b
			gcd(a,b) == gcd(b, a%b)
			如果a >= 2b，问题规模缩小了至少一半
			如果2b > a >= b，此时a%b = a-b 
			gcd(a,b) == gcd(b, a-b) = gcd(a-b,?)
				经过2步，问题规模缩小了至少一半
				
		公式lcm(a,b) * gcd(a,b) == a * b的证明
		从质因数分解的角度来看gcd和lcm
		
		void defac(int n)
		{
			for(int i = 2; i * i <= n; i++)
				while(n % i == 0)
				{
					cout << i << " ";
					n /= i;
				}
			if(n != 1) cout << n << " "; 
		}
		
		max(a,b) + min(a,b) == a + b
