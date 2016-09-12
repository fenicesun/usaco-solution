/*
 ID:kevin_s1
 PROG:sort3
 LANG:C++    
    */ 
 
//#include <iostream> 
#include<fstream>
using namespace std;
ifstream fin("sort3.in");
ofstream cout("sort3.out");
 
int n,a[1001],b[1001],num[4][4]={0},ans=0;
 
int main()
{
    int i,j;
    fin>>n;
    for(i=1;i<=n;i++)
    {
     fin>>a[i];
     b[i]=a[i];                               
                     }
 
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    if(b[i]>b[j]) swap(b[i],b[j]);                 
 
 
    for(i=1;i<=n;i++)
    num[b[i]][a[i]]++;
 
    j=min(num[1][2],num[2][1]);
    num[1][2]-=j;
    num[2][1]-=j;
    ans+=j;
 
    j=min(num[1][3],num[3][1]);
    num[1][3]-=j;
    num[3][1]-=j;
    ans+=j;
 
    j=min(num[3][2],num[2][3]);
    num[3][2]-=j;
    num[2][3]-=j;
    ans+=j;
 
    ans+=max(num[1][2],num[2][1])*2;
 
    cout<<ans<<endl;
 
 //   system("pause");
    return 0;
 
    }
