#include<iostream>
using namespace std;
char d[20];
bool f(int k)
{
	int p = 0, x = k;
	while(k) d[p++] = k % 10 + '0', k /= 10;
	for(int i = 0; i < p/2; ++i) if(d[i] != d[p-i-1]) return 0;
	p = 0;
	while(x) d[p++] = (x & 1) + '0', x >>= 1;
	for(int i = 0; i < p/2; ++i) if(d[i] != d[p-i-1]) return 0;
	return 1;
}

int main(void)
{
	int ans = 0;
	for(int i = 0; i < 1000000; ++i)
		if(f(i)) ans += i;
	cout<<"Answer : "<<ans<<endl;
	cin.get();
	return 0;
}
