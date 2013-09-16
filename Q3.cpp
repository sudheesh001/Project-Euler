#include <iostream>
using namespace std;
int main()
{
	long long int num = 600851475143;

	for(int i = 2; i < num; i++)
	{
		if(num % i == 0)
		 {
			 num = num/i;
			 i= i-1;
		}
 }
 cout << "The largest prime is.. " << num;
 cin.get();
}