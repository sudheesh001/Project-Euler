#include<iostream>
#include<fstream>
using namespace std;
#define MAX(a,b) ((a) > (b)? (a):(b))
int ans = 0, m[15][15];
int main(void)
{
	/*
	for(int i = 0; i < 15; ++i)
		for(int j = 0; j <= i; ++j) scanf("%d", &m[i][j]);
	*/
	ifstream fin("number2.txt");
	int num;
	int i=0,j=0;
	while(fin>>num)
	{
		if(j<=i && i<15)
			m[i][j++]=num;
		if(j==i)
		{
			i++;
			j=0;
		}
	}
	fin.close();
	for(int i = 1; i < 15; ++i)
		for(int j = 0; j <= i; ++j)
			if(!j) 
				m[i][j] += m[i - 1][j];
			else 
			if(j == i) 
				m[i][j] += m[i - 1][j - 1];
			else 
				m[i][j] += MAX(m[i - 1][j], m[i - 1][j - 1]);

	for(int i = 0; i < 15; ++i) 
		if(m[14][i] > ans) ans = m[14][i];
		
	cout<<"Answer : "<<ans<<endl;
	cin.get();
	return 0;
}
