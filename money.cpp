/*
ID:kevin_s1
PROG:money
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

#define MAXN 10010


//gobal variable====
int V;
long long N;
int coins[30];
long long dp[30][MAXN];
//==================


//function==========

//==================

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	cin>>V>>N;
	int coin;
	for(int i = 1; i <= V; i++){
		cin>>coin;
		coins[i] = coin;
	}
	for(int i = 1; i <= V; i++)
		dp[0][i] = 0;
	dp[0][0] = 1;
	for(int i = 1; i <= V; i++){
		for(long long j = 0; j < coins[i]; j++){
			dp[i][j] = dp[i - 1][j];
		}
		for(long long j = coins[i]; j <= N; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
		}
	}
	cout<<dp[V][N]<<endl;
	return 0;
}
