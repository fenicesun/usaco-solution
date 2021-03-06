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
#include <queue>

using namespace std;

#define MAXN 55
#define MAXK 205
#define MAXV 2000020

//gobal variable====
int K, N;
int stamps[MAXN];
int hash[MAXV];
int result;

queue<int> sum;
//==================


//function==========
void DFS(int i, int sum){
	if(i == K)
		return;
	for(int j = 1; j <= N; j++){
		int tmp = sum + stamps[j];
		hash[tmp] = 1;
		DFS(i + 1, tmp);
	}
	return;
}



//==================

int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	cin>>K>>N;
	for(int i = 1; i <= N; i++){
		cin>>stamps[i];
	}
	memset(hash, 0, sizeof(hash));
	sort(stamps + 1, stamps + N + 1);
	DFS(0, 0);
	for(int i = 1; i < MAXV; i++){
		if(hash[i] == 0){
			result = i - 1;
			break;
		}
	}
	cout<<result<<endl;
	return 0;
}
