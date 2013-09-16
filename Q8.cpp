#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *a;
    a=fopen("Long.txt","r");
    char s[1001];
    fscanf(a,"%s",s);
char p[6];

int i=0,x,prdmax=1,m,n;
while(s[i]!='\0')
{
    p[0]=s[i];
    p[1]=s[i+1];
    p[2]=s[i+2];
    p[3]=s[i+3];
    p[4]=s[i+4];
    p[5]='\0';

    x=atoi(p);
    n=x;
    int prd=1;
    while(x!=0)
    {
        int q=x%10;
        prd*=q;
        x/=10;
    }

    if(prd>prdmax)
    {
        prdmax=prd;
        m=n;
    }
    i++;
}

printf("Numbers are: %d\n Largest product is: %d",m,prdmax);
int nn;scanf("%d",nn);
fclose(a);
}