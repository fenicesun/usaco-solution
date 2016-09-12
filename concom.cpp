/*
ID:kevin_s1
PROG:concom
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

#define MAXN 100

//dp[i][j] = sum{dp[k][j]}  dp[i][k] > 50

//gobal variable====
int N;
int owner[MAXN][MAXN];
int maxindex;
int hash[MAXN];

int visited[MAXN];
int tmp1;
//==================


//function==========

void DFS(int x){
	visited[x] = 1;
	for(int i = 1; i <= maxindex; i++){
		if(!visited[i] && owner[x][i] > 50){
			owner[tmp1][i] = 51;
			DFS(i);
		}
	}
	return;
}

void solve(){
	for(int i = 1; i <= maxindex; i++){
		memset(visited, 0, sizeof(visited));
		tmp1 = i;
		DFS(i);
	}
}

void floyd(){
	for(int i = 1; i <= maxindex; i++){
		for(int j = 1; j <= maxindex; j++){
			for(int k = 1; k <= maxindex; k++){
				if(owner[i][k] > 50 && (i != j) && (i != k) && (j != k)){
					if(owner[k][j] <= 50)
						owner[i][j] += owner[k][j] ;
				}
			}
		}
	}
}


//==================

int main(){
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	cin>>N;
	int i, j, share;
	maxindex = 0;
	memset(owner, 0, sizeof(owner));
	memset(hash, 0, sizeof(hash));
	for(int k = 1; k <= N; k++){
		cin>>i>>j>>share;
		owner[i][j] = share;
		maxindex = max(maxindex, max(i, j));
		hash[i] = 1;
		hash[j] = 1;
	}
	solve();
	floyd();
	for(int i = 1; i <= maxindex; i++){
		for(int j = 1; j <= maxindex; j++){
			if(owner[i][j] > 50 && (hash[i] == 1) && (hash[j] == 1) && i != j)
				cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
