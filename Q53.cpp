#include <iostream>
using namespace std;
int main(void)
{
	int ans = 0;
	for(int i = 23; i < 101; ++i)
		for(int d = 1, n = i, v = 1; n > i / 2; n--, d++)
			if((v = v*n/d) > 1000000)
			{ 
				ans += (i + 1) - (d<<1); 
				break; 
			}
	cout<<ans<<endl;
	cin.get();
	return 0;
}
