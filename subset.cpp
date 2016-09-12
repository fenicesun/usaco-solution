/*
ID:kevin_s1
PROG:subset
LANG:C++
*/

#include<stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int result;
int sum;
long long F[40][900];
long long i,k,l,j,m,n,s;
long long edge(int x);
int mission()
{
	int i,j,k;
	for(i=2;i<=n;i++)
		for(j=0;j<=edge(i);j++)
		{
			if(j>=i)
				F[i][j]=F[i-1][j]+F[i-1][j-i];
			else if(j<i)
				F[i][j]=F[i-1][j];
		}
 
	return F[n][sum];		
}

void open()
{
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
}

long long edge(int x)
{
	return ((x+1)*x)/2;
}

int main()
{
	open();
	cin>>n;
	sum = ((n+1)*n)/2;
	if(sum&1==1)
	{
		cout<<"0"<<endl;
		return 0;
	}
	sum /= 2;
	F[1][1]=1;
	F[1][0]=1;
	result = mission();
	printf("%lld\n",result/2);
	return 0;
}
