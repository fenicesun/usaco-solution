/*
ID:kevin_s1
PROG:calfflac
LANG:C++
*/
 
#include<stdio.h>
#include<ctype.h>
#include<vector>
 
using namespace std;
 
vector <int> f[2];
 
int n,m,ans,ts,te,pos[20001];
 
char s[20001],c[20001];
 
int main()
{
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	int i,j,k;
	while(scanf("%c",&s[n++])!=EOF)
	{
		if(isalpha(s[n-1]))
		{
			c[m]=tolower(s[n-1]);
			pos[m++]=n-1;
		}
	}
	f[0].push_back(0);
	for(i=1,k=true;i<m;i++,k=!k)
	{
		f[k].clear();
		for(j=0;j<f[!k].size();j++)
		{
			if(c[i]==c[i-f[!k][j]-1])
			{
				f[k].push_back(f[!k][j]+2);
			}
		}
		f[k].push_back(1);
		f[k].push_back(0);
		if(f[k][0]>ans)
		{
			ans=f[k][0];
			ts=pos[i-f[k][0]+1];
			te=pos[i];
		}
	}
	printf("%d\n",ans);
	for(i=ts;i<=te;i++)
	{
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}

