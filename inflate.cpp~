/*
ID:kevin_s1
PROG:inflate
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

#define MAXN 11000

//gobal variable====
int M, N;
int points[MAXN];
int minutes[MAXN];
int dp[MAXN];
//==================


//function==========

//==================

int main(){
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	cin>>M>>N;
	for(int i = 1; i <= N; i++){
		cin>>points[i]>>minutes[i];
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= N; i++){
		for(int j = minutes[i]; j <= M; j++){
			dp[j] = max(dp[j], dp[j - minutes[i]] + points[i]);
		}
	}
	cout<<dp[M]<<endl;
	return 0;
}
