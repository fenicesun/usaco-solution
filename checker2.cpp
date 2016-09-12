/*
ID:kevin_s1
PROG:checker
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<memory.h>
using namespace std;
ifstream fin("checker.in");
ofstream fout("checker.out");
int N;
int tot=0;
int C[255];
int vis[3][255];//这个如果是用[3][14]的话，可能会产生缓冲区溢出。。我懒得试了 就开个大的。。最后还只是用了3K多Kb
void search(int cur)
{
	int i,j;
	if(cur==N) 
	{
		tot++;
		if(tot<4)
		{	
			for(int n=0;n<N-1;n++)
			    fout<<C[n]<<" ";
			fout<<C[N-1]<<endl;
		}
 
	}
	else 
		for(i=0;i<N;i++)
		{
			if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+N])//利用二维数组直接判断是否和前面的皇后冲突
			{
				C[cur]=i+1;
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+N]=1;//修改全局变量
				search(cur+1);
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+N]=0;//出口处改回来！
			}
		}
}
 
 
int main()
{
	fin>>N;
	memset(C,0,14);
	search(0);
	fout<<tot<<endl;
	return 0;
}
