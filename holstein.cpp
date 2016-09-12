/*
ID:kevin_s1
PROG:holstein
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

#define MAXV 26
#define MAXG 16
#define INF 327699


//gobal variable====
int V;
int requirement[MAXV];
int G;
int feed[MAXG][MAXV];
int result;

int ans[MAXG];
int vit[MAXV];
int res[MAXG];
//==================


//function==========
bool check(){
	bool flag = true;
	for(int i = 1; i <= V; i++){
		if(vit[i] < requirement[i])
			flag = false;
	}
	return flag;
}

void DFS(int deep, int count){
	if(deep > G + 1)
		return;
	if(check()){
		if(count < result){
			result = count;
			for(int i = 1; i <= result; i++){
				res[i] = ans[i];
			}
		}
		return;
	}
	for(int i = 1; i <= V; i++){
		vit[i] += feed[deep][i];
	}
	ans[count + 1] = deep; 
	DFS(deep + 1, count + 1);
	for(int i = 1; i <= V; i++){
		vit[i] -= feed[deep][i];
	}
	DFS(deep + 1, count);
	return;
}

//==================

int main(){
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	cin>>V;
	for(int i = 1; i <= V; i++){
		cin>>requirement[i];
	}
	cin>>G;
	for(int i = 1; i <= G; i++){
		for(int j = 1; j <= V; j++){
			cin>>feed[i][j];
		}
	}
	memset(res, 0, sizeof(res));
	memset(ans, 0, sizeof(ans));
	memset(vit, 0, sizeof(vit));
	result = INF;
	DFS(1, 0);
	cout<<result;
	for(int i = 1; i <= result; i++){
		cout<<" "<<res[i];
	}
	cout<<endl;
	return 0;
}
