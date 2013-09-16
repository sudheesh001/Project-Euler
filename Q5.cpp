#include <iostream>
using namespace std;
int main()
{
	int answ = 0;
	int n = 20;
	bool a = true;
	int i = n;
	while(a)
	{ 
		a = true;
		for(int j=n; j>1; j--)
		{
			if(i % j != 0)
				break;
			if(j == 2)
			{
				a=false;
				answ = i;
			}

		}
		i++;
	}
	cout << answ << " is the lcm of the first 20 natural numbers";
	cin.get();
	return 0;
}