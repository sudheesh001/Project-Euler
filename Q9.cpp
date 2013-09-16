#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	for(a=1;a<=1000;a++)
	{
		for(b=1;b<=1000;b++)
		{
			for(c=1;c<=1000;c++)
			{
				if((c*c)==(a*a)+(b*b))
				{
					//This is a pythogoram triplet ! Yay
					if(a+b+c==1000)
					{
						cout<<"Product of "<<a<<","<<b<<","<<c<<","<<a*b*c<<endl;
					}
				}
			}
		}
	}
	cin.get();
	return 0;
}