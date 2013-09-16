#include <iostream>
using namespace std;
bool prime(int k)
{
	if(k < 2) 
		return 0;
	if(!(k & 1) && k != 2) 
		return 0;
	for(int i = 3; ; i += 2){
		if(i * i > k) 
			return 1;
		if(!(k % i)) 
			return 0;
	}
}
int main(void)
{
	int ans, max = 0, n;
	for(int a = -999; a < 999; ++a)
		for(int b = -999; b < 999; ++b)
		{
			for(n = 0; ; ++n){
				int x = n * n + a * n + b;
				if(!prime(x)) break;
			}
			if(n > max) max = n, ans = a * b;
		}
	cout<<"Answer :"<<ans<<endl;
	cin.get();
	return 0;
}
