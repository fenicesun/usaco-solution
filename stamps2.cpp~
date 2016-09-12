/*
ID:kevin_s1
PROG:stamps
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

#define MAXN 55
#define MAXK 220
#define INF 9999999

//gobal variable====
int K, N;
int stamps[MAXN];

int dp[2000000];
int result;
//==================


//function==========

//==================

int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	cin>>K>>N;
	for(int i = 1; i <= N; i++){
		cin>>stamps[i];	
	}
	dp[0] = 1;
	
	for(int i = 1; i <= 2000000; i++){
		dp[i] = INF;
		int min = INF;
		for(int j = 1; j <= N; j++){
			if(min > dp[i - stamps[j]])
				min = dp[i - stamps[j]];
		}
		dp[i] = min + 1;
		if(dp[i] > K){
			result = i - 1;
			break;
		}
	}
	cout<<result - 1<<endl;
	return 0;
}
