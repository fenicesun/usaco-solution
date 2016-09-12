/*
ID:kevin_s1
PROG:clocks
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

//gobal variable====
#define INF 999999
int _clock[4][4];
int mintimes;
int ans[10000];
//==================


//function==========
void input(){
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			cin>>_clock[i][j];
		}
	}
}

int pre(int x){
	if(x == 3)
		return 12;
	return (x - 3) % 12;
}

int next(int x){
	if(x == 9)
		return 12;
	return (x + 3) % 12;
}

bool check(){
	bool flag = true;
	for(int i = 1; i <= 3; i++){
		for(int j = 1; j <= 3; j++){
			if(_clock[i][j] != 12){
				flag = false;
			}
		}
	}
	return flag;
}

void DFS(int step,int result[]){
	if(step > mintimes)
		return;
	if(check()){
		if(step < mintimes){
			mintimes = step;
			for(int i= 0; i < mintimes; i++)
				ans[i] = result[i];
			return;
		}
		return;
	}
	//move 1
	result[step] = 1;
	_clock[1][1] = next(_clock[1][1]);
	_clock[1][2] = next(_clock[1][2]);
	_clock[2][1] = next(_clock[2][1]);
	_clock[2][2] = next(_clock[2][2]);
	DFS(step + 1, result);
	_clock[2][2] = pre(_clock[2][2]);
	_clock[2][1] = pre(_clock[2][1]);
	_clock[1][2] = pre(_clock[1][2]);
	_clock[1][1] = pre(_clock[1][1]);
	//move 2
	result[step] = 2;
	_clock[1][1] = next(_clock[1][1]);
	_clock[1][2] = next(_clock[1][2]);
	_clock[1][3] = next(_clock[1][3]);
	DFS(step + 1, result);
	_clock[1][3] = pre(_clock[1][3]);
	_clock[1][2] = pre(_clock[1][2]);
	_clock[1][1] = pre(_clock[1][1]);
	//move 3
	result[step] = 3;
	_clock[1][2] = next(_clock[1][2]);
	_clock[1][3] = next(_clock[1][3]);
	_clock[2][2] = next(_clock[2][2]);
	_clock[2][3] = next(_clock[2][3]);
	DFS(step + 1, result);
	_clock[2][3] = pre(_clock[2][3]);
	_clock[2][2] = pre(_clock[2][2]);
	_clock[1][3] = pre(_clock[1][3]);
	_clock[1][2] = pre(_clock[1][2]);
	//move 4
	result[step] = 3;
	_clock[1][1] = next(_clock[1][1]);
	_clock[2][1] = next(_clock[2][1]);
	_clock[3][1] = next(_clock[3][1]);
	DFS(step + 1, result);
	_clock[3][1] = pre(_clock[3][1]);
	_clock[2][1] = pre(_clock[2][1]);
	_clock[1][1] = pre(_clock[1][1]);

	//move 5
	result[step] = 5;
	_clock[1][2] = next(_clock[1][2]);
	_clock[2][1] = next(_clock[2][1]);
	_clock[2][2] = next(_clock[2][2]);
	_clock[2][3] = next(_clock[2][3]);
	_clock[3][2] = next(_clock[3][2]);
	DFS(step + 1, result);
	_clock[3][2] = pre(_clock[3][2]);
	_clock[2][3] = pre(_clock[2][3]);
	_clock[2][2] = pre(_clock[2][2]);
	_clock[2][1] = pre(_clock[2][1]);
	_clock[1][2] = pre(_clock[1][2]);

	//move 6
    result[step] = 6;
	_clock[1][3] = next(_clock[1][3]);
	_clock[2][3] = next(_clock[2][3]);
	_clock[3][3] = next(_clock[3][3]);
	DFS(step + 1, result);
	_clock[3][3] = pre(_clock[3][3]);
	_clock[2][3] = pre(_clock[2][3]);
	_clock[1][3] = pre(_clock[1][3]);
	//move 7
	
	result[step] = 7;
	_clock[2][1] = next(_clock[2][1]);
	_clock[2][2] = next(_clock[2][2]);
	_clock[3][1] = next(_clock[3][1]);
	_clock[3][2] = next(_clock[3][2]);
	DFS(step + 1, result);
	_clock[3][2] = pre(_clock[3][2]);
	_clock[3][1] = pre(_clock[3][1]);
	_clock[2][2] = pre(_clock[2][2]);
	_clock[2][1] = pre(_clock[2][1]);

	//move 8
	
	result[step] = 8;
	_clock[3][1] = next(_clock[3][1]);
	_clock[3][2] = next(_clock[3][2]);
	_clock[3][3] = next(_clock[3][3]);
	DFS(step + 1, result);
	_clock[3][3] = pre(_clock[3][3]);
	_clock[3][2] = pre(_clock[3][2]);
	_clock[3][1] = pre(_clock[3][1]);

	//move 9
	result[step] = 9;
	_clock[2][2] = next(_clock[2][2]);
	_clock[2][3] = next(_clock[2][3]);
	_clock[3][2] = next(_clock[3][2]);
	_clock[3][3] = next(_clock[3][3]);
	DFS(step + 1, result);
	_clock[3][3] = pre(_clock[3][3]);
	_clock[3][2] = pre(_clock[3][2]);
	_clock[2][3] = pre(_clock[2][3]);
	_clock[2][2] = pre(_clock[2][2]);

	return;
}


//==================

int main(){
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	int result[10000];
	input();
	mintimes = INF;
	DFS(0, result);
	for(int i = 0; i < mintimes; i++){
		cout<<ans[i];
		if(i != mintimes - 1)
			cout<<" ";
	}
	
	return 0;
}
