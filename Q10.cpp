#include <iostream>
using namespace std;


int main()
{
	long long int sum = 0;
	int* primes = new int[1000000];
	primes[0] = 2;
	int count = 1;
	int* max = 0;
	bool t = true;

	for(int i = 3; i < 2000000; i = i + 2)
	{
		t = true; 
		for(int j = 0; j < count/2; j++)
		{
			if(i % primes[j] == 0)
			{
			    t = false;
				break;
			}
			
		}
		if(t)
			{
				count++;
				primes[count-1] = i;
			}
	}


	for(int j = 0; j < count; j++)
	{
		sum = sum + primes[j];
	}

	cout << count << "\n" << sum;
	cin >> sum;	
}

