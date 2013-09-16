#include<iostream>
#include<cmath>
using namespace std;
#define LIM 1001
int count[LIM];
int gcd(int a, int b)
{
	return (b ? gcd(b, a % b) : a);
}
int main(void)
{
	int ans, max = 0, sqrt_lim = (int) sqrt(LIM);
	for(int n = 1; n < sqrt_lim; n += 2)
		for(int m = 2; m < sqrt_lim; m += 2)
		{
			if(gcd(n, m) == 1)
			{
				int sum = 2 * m * n + m * m + n * n + abs(m * m - n * n);
				for(int s = sum; s < LIM; s += sum) 
					++count[s];
			}
		}
	for(int i = 0; i < LIM; ++i) 
		if(count[i] > max) 
			ans = i, max = count[i];

	cout<<"Answer : "<<ans<<endl;
	cin.get();
	return 0;
}
