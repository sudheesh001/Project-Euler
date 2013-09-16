#include <iostream>
using namespace std;
char v[350];
void multi(int q) 
{ 
    int c = 0, i; 
	for(i = 0; v[i]; ++i)
	{
		c = ( (v[i] - '0') * q + c );
		v[i] = '0' + c % 10;
		c /= 10;
    } 
    while(c) 
    { 
    	v[i++]='0'+(c%10); 
    	c /= 10; 
    }
	v[i] = 0;
} 
int main(void)
{
	int ans = 0;
	v[0] = '1'; 
	v[1] = 0;
	for(int i = 0; i < 1000; ++i) 
		multi(2);
	for(int i = 0; v[i]; ++i) 
		ans = ans + v[i] - '0';
	cout<<"Answer : "<<ans<<endl;
	cin.get();
	return 0;
}
