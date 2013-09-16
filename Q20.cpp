#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;


void Times(int* a, int *b, int* ab)
{
	memset(ab, 0, 800);
	for(int i = 0; i < 200; i++) // starting with the smallest digit of b
			{
				for(int j = 199; j > -1; j--) // starting with the largest digit of a
				{
					ab[i+j] = ab[i+j] + b[i]*a[j]; // multiply specific b[i] by all a[j](1-99) and store in ab

					for(int k = 0; k < 200; k++) // carry remainders and mod 10
					{	
						ab[k+1] = ab[k+1] + (ab[k]- ab[k]%10)/10;
						ab[k] = ab[k]%10;
					}
				}
			}
}

int main()
{
	int a[200] = {0};
	int b[200] = {0};
	int ab[200] = {0};
	
	a[0] = 1;
	b[0] = 2;
	Times(a,b,ab);
	memcpy(a,ab,sizeof(ab));

	for(int i = 3; i < 10; i++)
	{
	b[0] = i;
	Times(a,b,ab);
	memcpy(a,ab,sizeof(ab));
	}

	for(int i = 10; i < 101; i++)
	{
	b[0] = i % 10;
	b[1] = (i-b[0])/10;
	Times(a,b,ab);
	memcpy(a,ab,sizeof(ab));
	}
	
	
	
	int sum = 0;
	for(int i = 199; i > -1; i--)
		sum = sum + ab[i];

	cout << sum;
	cin >> b[0];
}