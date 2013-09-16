#include<iostream>
#include<cmath>
using namespace std;
long long ans = 0;
bool is_pentagonal(long long k){
	long long t = 1 + 24 * k, r = (long long)sqrt(t);
	return r * r == t && !((r + 1) % 6);
}
bool is_triangle(long long k)
{
	long long t = 1 + (k << 3), r = (long long)sqrt(t);
	return r * r == t;
}
int main(void)
{
	for(int k = 286; !ans; ++k)
	{
		long long a = k, x = 2 * a * a - a;
		if(is_pentagonal(x) && is_triangle(x)) ans = x;
	}
	cout<<ans<<endl;
	cin.get();
	return 0;
}
