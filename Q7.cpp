#include <iostream>
using namespace std;
int main()
{
	int i=2;int count=1;
	while(1 && count<=10001)
	{
		int k=2;int found=0;
		while(k<i && found==0)
		{
			if(i%k==0)
				found=1;
			k++;
		}
		if(found==0)
		{
			cout<<i<<" "<<count<<endl;
			count++;
		}
		i++;
	}
	//cout<<i<<" "<<count<<endl;
	cin.get();
	return 0;
}