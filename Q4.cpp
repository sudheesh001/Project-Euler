#include <iostream>
using namespace std;
int main()
{
	int answ = 1;
	int hundredthousand = 1;
	int tenthousand = 0;
	int thousand = 0;
	int hundred = 0;
	int ten = 0;
	int one = 0;
	int k = 0;
	for(int i = 999; i > 100; i--)
	{
		for(int j = 999; j > 100 ; j--)
		{ 
			k = i*j;
			hundredthousand = i*j/100000;
			k = i*j - hundredthousand*100000;
			tenthousand = k/10000;
			k = k - tenthousand*10000;
			thousand = k/1000;
			k = k - thousand*1000;
			hundred = k/100;
			k = k - hundred*100; 
			ten = k/10;
			k = k - ten*10;
			one = k;
			if(hundredthousand == one && tenthousand==ten && thousand==hundred)
			{	
				if(i*j > answ)
					answ = i*j;	
				break;
			}
		}
	}			
	cout << answ;
	cin.get();
}