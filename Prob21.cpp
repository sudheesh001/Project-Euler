#include<iostream>
using namespace std;
int main()
{
	int sum = 0;
	int singles = 0;
	int da = 0;
	int db = 0;

	for(int a = 1; a < 10000; a++)
	{
		da = 0;
		db = 0;
		for(int j = 1; j < a; j++)
		{
			if(a % j == 0)
				da = da + j;
		}
		for(int k = 1; k < da; k++)
		{
			if(da % k == 0)
			db = db + k;
		}

		if(db==a && a != da)
		{
			sum = sum + a;
			if(db < 9999)
				sum = sum + a;
		}
		

	}

	cout << sum/2;
	cin >> sum;


}