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

#define MAXN 110

//gobal variable====
int N;
int owner[MAXN][MAXN];
int visited[MAXN];
int controls[MAXN];

int MAXINDEX;
int hash[MAXN];
//==================


//function==========

void DFS(int i){
	visited[i] = 1;
	for(int j = 1; j <= MAXINDEX; j++){
		controls[j] += owner[i][j];
	}
	for(int j = 1; j <= MAXINDEX; j++){
		if(controls[j] > 50 && !visited[j]){
			DFS(j);
		}
	}
	return;
}



//==================

int main(){
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	cin>>N;
	int A, B, share;
	memset(hash, 0, sizeof(hash));
	MAXINDEX = 0;
	for(int i = 1; i <= N; i++){
		cin>>A>>B>>share;
		owner[A][B] = share;
		MAXINDEX = max(MAXINDEX, max(A, B));
		hash[A] = 1;
		hash[B] = 1;
	}
	for(int i = 1; i <= MAXINDEX; i++){
		memset(controls, 0, sizeof(controls));
		memset(visited, 0, sizeof(visited));
		DFS(i);
		for(int j = 1; j <= MAXINDEX; j++){
			if(i != j && controls[j] > 50 && hash[i] && hash[j]){
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	
	return 0;
}
