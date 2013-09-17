#include<iostream>
using namespace std;
int main(void)
{
	long long ans = 0;
	for(int i = 1; i < 1001; ++i){
		long long c = i, r = i;
		for(int j = 1; j < i; ++j) r = (r * c) % 10000000000LL; 
		ans = (ans + r) % 10000000000LL;
	}
	cout<<ans<<endl;
	cin.get();
	return 0;
}
