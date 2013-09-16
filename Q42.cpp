#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
char word[64];
int main(void)
{
	int ans = 0, value;
	char word[20];
	ifstream f("words.txt");
	while(f>>word)
	{
		char *p = word;
		value = 0;
		while(*p) 
			value += *p++ - 'A' + 1;
		int test = (value << 3) + 1, root = (int)sqrt(test);
		ans += root * root == test;
	}
	cout<<ans<<endl;
	cin.get();
	return 0;
}
