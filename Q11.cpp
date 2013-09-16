#include<iostream>
#include<fstream>
using namespace std;
#define max(a,b) ((a) > (b)? (a):(b))
int ans = 0, m[20][20];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
void mult(int x, int y, int d, int dir, int val)
{
	if(d == 3)
	{
		ans = max(ans, val);
		return;
	}
	if(!d) for(int i = 0; i < 8; ++i)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 0 || ny < 0 || nx > 19 || ny > 19) 
			continue;
		mult(nx, ny, d + 1, i, val * m[nx][ny]);
	} 
	else 
	{
		int nx = x + dx[dir], ny = y + dy[dir];
		if(!(nx < 0 || ny < 0 || nx > 19 || ny > 19))
			mult(nx, ny, d + 1, dir, val * m[nx][ny]);
	}
}
int main(void)
{
	ifstream fin("number.txt");
	int num;
	int i=0,j=0;
	while(fin>>num)
	{
		if(j<20)
			m[i][j++]=num;
		if(j==20)
		{
			i++;
			j=0;
		}
	}
	fin.close();
	for(int i = 0; i < 20; ++i) 
		for(int j = 0; j < 20; ++j) 
			mult(i, j, 0, -1, m[i][j]);
	cout<<"Answer : "<<ans<<endl;
	cin.get();
	return 0;
}