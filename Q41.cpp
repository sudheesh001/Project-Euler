#include<iostream>
#include<math.h>
#include "BigInt.h"
using namespace std;
int main()
{
	BigInt B = "31524";
	int* primes = PrimeList(5761454);
	int answ = 0;
	bool keepGoing = true;
	for(int i = 5761453; keepGoing; i--)
	{
		if(primes[i] > 7654321)
			continue;
		BigInt B = primes[i];
		if(B.isPandigitalY(B.size()))
		{
			answ = B.bToi();
			keepGoing = false;
		}
	}

	cout << answ;
	cin >> answ;
	
}