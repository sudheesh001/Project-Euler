#include<iostream>
using namespace std;
int f[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
bool curious(int x)
{
	int sum = 0, k = x;
	while(x) sum += f[x % 10], x /= 10;
	return sum == k;
}
int main(void)
{
	int ans = 0;
	for(int i = 3; i < 2540160; ++i)
		if(curious(i)) ans += i;
	cout<<"Answer : "<<ans<<endl;
	cin.get();
	return 0;
}
