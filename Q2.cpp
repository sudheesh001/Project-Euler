#include<iostream>
using namespace std;
int main()
{
	int Fa = 1;
	int Fb = 2;
	int sum = 0;
	while(Fa < 4000000)
	{ 
		Fb = Fa + Fb;
		Fa = Fb - Fa;
		if(Fa % 2 == 0)
			sum+=Fa;
	}
	cout << "THE ANSWER IS...." << sum;
	cin.get();
	return 0;
}