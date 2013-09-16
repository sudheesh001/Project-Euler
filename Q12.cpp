#include<iostream>
#include<math.h>
using namespace std;
int main()
{

	int numofdivs = 0;
	int n = 1;
	int tn = 0;
	int max = 0;
	while(numofdivs < 500)
	{
		n++;
		numofdivs = 0;
		tn = n*(n+1)/2;
		for(int i = 1; i < sqrt((float)tn); i++)
		{
			if(tn % i == 0)
				numofdivs++;
		}
		numofdivs *= 2;

		if(floor(sqrt((float)tn)) == sqrt((float)tn))
			numofdivs--;

		if(numofdivs > max)
		{
			max = numofdivs;
		}
	}

	cout << "The first triangle number with over five-hundred divisors is " << tn << endl;
	cin.get();
}