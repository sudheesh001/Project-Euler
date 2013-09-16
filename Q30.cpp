#include <iostream>
//#include "BigInt.h"
using namespace std;
int main()
{
	int result = 0;
	for (int i = 2; i < 355000; i++) 
	{
	    int sumOfPowers = 0;
	    int number = i;
	    while (number > 0) 
	    {
	        int d = number % 10;
	        number /= 10;
	 
	        int temp = d;
	        for(int j = 1; j < 5; j++){
	            temp *= d;
	        }
	        sumOfPowers += temp;
	    }
	    if (sumOfPowers == i) 
	    {
	        result += i;
	    }
	}
	cout<<result<<" is the total number\n";
	cin.get();
	return 0;
}
