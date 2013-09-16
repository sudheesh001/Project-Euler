#include<iostream>
#include<cmath>
using namespace std;
int ans = 0, p[5000];
bool is_pentagonal(int k)
{
	int t = 1 + 24 * k, r = (int)sqrt(t);
	return r * r == t && !((r + 1) % 6);
}
int main(void)
{
	for(int i = 1; !ans; i++)
	{
		p[i] = (3 * i * i - i) >> 1;
		for(int j = i; !ans && --j; )
		{
			int diff = p[i] - p[j], sum = p[i] + p[j];
			if(is_pentagonal(diff) && is_pentagonal(sum)) 
				ans = diff;
		}
	}
	cout<<ans<<endl;
	cin.get();
	return 0;
}
