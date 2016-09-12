/*
ID:kevin_s1
PROG:cowtour
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

#define MAXN 175
const double INF = 1E15;

//gobal variable====
int N;

struct point{
	double x;
	double y;
}points[MAXN];

double Graph[MAXN][MAXN];

double result;

int Father[MAXN];
int Rank[MAXN];

double blocks[MAXN];
//==================


//function==========

int Find(int x){
	while(x != Father[x]){
		x = Father[x];
	}
	return x;
}

bool check(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x == y)
		return true;
	else
		return false;
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);
	if(x == y)
		return;
	if(Rank[x] >= Rank[y]){
		Father[y] = x;
		Rank[x] += Rank[y];
	}
	else{
		Father[x] = y;
		Rank[y] += Rank[x];
	}
}

double dist(point start, point end){
	return sqrt((end.x - start.x)*(end.x - start.x) + (end.y - start.y)*(end.y - start.y));
}

void Input(){
	cin>>N;
	for(int i = 1; i <= N; i++){
		cin>>points[i].x>>points[i].y;
		blocks[i] = -1;
		Father[i] = i;
		Rank[i] = 1;
	}
	char flg;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++){
			cin>>flg;
			if(i == j)
				Graph[i][j] = 0;
			else if(flg == '1'){
				Union(i, j);
				Graph[i][j] = dist(points[i], points[j]);
			}
			else if(flg == '0')
				Graph[i][j] = INF;
		}
}

void Floyd(){
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(k == i || k == j)
					continue;
				if(Graph[i][j] > Graph[i][k] + Graph[k][j]){
					Graph[i][j] = Graph[i][k] + Graph[k][j];
				}
			}
		}
	}
}

void print(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cout<<Graph[i][j]<<" ";
		}
		cout<<endl;
	}
}


//==================

int main(){
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	Input();
	Floyd();
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(Graph[i][j] != INF && blocks[i] < Graph[j][i])
				blocks[i] = Graph[j][i];
		}
	}
	
	result = INF;
	for(int i = 1; i <= N; i++){
		for(int j = i + 1; j <= N; j++){
			if(Graph[i][j] == INF && !check(i, j)){
				double dis = dist(points[i], points[j]);
				if(blocks[i] + dis + blocks[j] < result)
					result = blocks[i] + dis + blocks[j];
			}
		}
	}

	for(int i = 1; i <= N; i++)
		if(blocks[i] > result)
			result = blocks[i];

	printf("%.6lf\n", result);
	return 0;
}
