/*
ID:kevin_s1
PROG:nocows
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

#define MAXN 210
#define MAXK 110

//thought and method
//type:DP
//dp[i][j] = sum{dp[k][j - 1] * dp[i - 1 - k][j - 1]}
//k in {1,2, ... i - 2}
//result = dp[N][K] - dp[N][K-1]

//gobal variable====
int N, K;
int dp[MAXN][MAXK];
int result;
//==================


//function==========
void DP(){
	memset(dp, 0, sizeof(dp));	
	for(int i = 1; i <= K; i++)
		dp[1][i] = 1;
	for(int j = 1; j <= K; j++){
		for(int i = 3; i <= N; i += 2){
			for(int k = 1; k <= i - 2; k += 2){
				dp[i][j] = ((dp[i][j] + dp[k][j - 1] * dp[i - 1 - k][j - 1]) % 9901);
			}
		}
	}
	result = ((dp[N][K] - dp[N][K - 1] + 9901) % 9901);
}

//==================

int main(){
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	cin>>N>>K;
	DP();
	cout<<result<<endl;
	return 0;
}
