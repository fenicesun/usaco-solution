/*
ID:kevin_s1
PROG:numtri
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <cmath>

using namespace std;
#define MAXN 1001

//gobal variable====
int R;
int tri[MAXN][MAXN];
int dp[MAXN][MAXN];
//==================
//dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j]

//function==========

//==================

int main(){
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	memset(dp,0,sizeof(dp));
	memset(tri,0,sizeof(tri));
	cin>>R;
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= i; j++){
			cin>>tri[i][j];
		}
	}
	dp[1][1] = tri[1][1];
	for(int i = 1; i <= R; i++){
		for(int j = 1; j <= i; j++){
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}
	}
	int maxnum = 0;
	for(int i = 1; i <= R; i++){
		if(dp[R][i] > maxnum )
			maxnum = dp[R][i];
	}
	cout<<maxnum<<endl;
	
	return 0;
}
