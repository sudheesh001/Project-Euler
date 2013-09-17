#include <iostream>
using namespace std;
#define MAX 1000000
#define SQMAX 1000
#define SUM_MAX 1000000
int ans = 0, pl[100000];
bool p[MAX];
int main(void)
{
	int c = 1, t = 0;
	for(int i = 0; i < MAX; ++i)
		p[i] = 1;
	p[0] = p[1] = 0;
	pl[0] = 2;
	for(int i = 4; i < MAX; i += 2)
		p[i] = 0;
	for(int i = 3; i < SQMAX; i += 2)
		if(p[i])
		{
			pl[c++] = i;
			for(int j = i * i; j < MAX; j += i) 
				p[j] = 0;
		}
	for(int i = SQMAX + !(SQMAX & 1); i < MAX; i += 2)
		if(p[i]) 
			pl[c++] = i;
	pl[c] = 1000000;
	for(int i = 0; i < c; i)
		for(int s = pl[i++], j = i; s < SUM_MAX; s += pl[j++])
			if(p[s] && (j - i) > t) 
				t = j - i, ans = s;
	cout<<ans<<endl;
	cin.get();
	return 0;
}
