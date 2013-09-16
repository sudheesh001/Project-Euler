#include<iostream>
using namespace std;
int sum(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=i;
	return sum;
}
int squares(int n)
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=(i*i);
	return sum;
}
int main()
{
	cout<<(sum(100)*sum(100))-squares(100)<<endl;
	cin.get();
	return 0;
}