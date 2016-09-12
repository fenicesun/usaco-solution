/*
ID:kevin_s1
PROG:castle
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
#include <queue>	
#include <cmath>

using namespace std;

#define MAXM 100


//gobal variable====
int M,N;
int direct[4][2] = {{-1, 0},{1, 0},{0, 1},{0, -1}};
//north, south, east, west
int castle[MAXM][MAXM];
int visited[MAXM][MAXM];
int visited2[MAXM][MAXM];
int visited3[MAXM][MAXM];
int hasWall[MAXM][MAXM][4];
int cnt, maxarea;
int _count;
//==================


//function==========

void Dec(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			int wall = castle[i][j];
			if(wall >= 8){
				hasWall[i][j][1] = 1;
				wall = wall - 8;
			}
			if(wall >= 4){
				hasWall[i][j][2] = 1;
				wall = wall - 4;
			}
			if(wall >= 2){
				hasWall[i][j][0] = 1;
				wall = wall - 2;
			}
			if(wall >= 1){
				hasWall[i][j][3] = 1;
				wall = wall - 1;
			}
		}
	}
}


void DFS(int x, int y, int type){
	if(x < 1 || x > N || y < 1 || y > M)
		return;
	if(visited[x][y] != 0)
		return;
	visited[x][y] = type;
	visited2[x][y] = type;
	_count++;
	if(_count > maxarea){
		maxarea = _count;
	}
	for(int d = 0; d < 4; d++){
		if(hasWall[x][y][d] == 0){
			int xx = x + direct[d][0];
			int yy = y + direct[d][1];
			DFS(xx, yy, type);
		}
	}
	return;
}

void DFS1(int x, int y, int type, int color){
	if(x < 1 || x > N || y < 1 || y > M)
		return;
	if(visited[x][y] != type)
		return;
	if(visited3[x][y] == 1)
		return;
	visited[x][y] = color;
	visited3[x][y] = 1;
	for(int d = 0; d < 4; d++){
		if(hasWall[x][y][d] == 0){
			int xx = x + direct[d][0];
			int yy = y + direct[d][1];
			DFS1(xx, yy, type, color);
		}
	}
	return;
}

void print(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
}

void print2(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cout<<visited2[i][j]<<" ";
		}
		cout<<endl;
	}
}
//==================

int main(){
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	cin>>M>>N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin>>castle[i][j];
		}
	}
	memset(hasWall, 0, sizeof(hasWall));
	memset(visited, 0, sizeof(visited));
	memset(visited2, 0, sizeof(visited2));
	memset(visited3, 0, sizeof(visited3));
	Dec();
	cnt = 0;
	maxarea = 0;
	int type = 1;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(visited[i][j] == 0){
				_count = 0;
				DFS(i, j, type);
				cnt++;
				DFS1(i, j, type, _count);
				type++;
			}
		}
	}
	cout<<cnt<<endl;
	cout<<maxarea<<endl;
	//print2();
	//print();
	//enum the wall
	int mmaxarea = 0;
	int tx = 0, ty = 0, dir = 0;
	for(int x = 1; x <= N; x++){
		for(int y = M; y >= 1; y--){
			for(int d = 0; d < 4; d++){
				if(hasWall[x][y][d] == 1){
					int xx = x + direct[d][0];
					int yy = y + direct[d][1];
					if(xx >= 1 && xx <= N && yy >= 1 && yy <= M){
						if((visited[x][y] + visited[xx][yy]) > mmaxarea && (visited2[x][y] != visited2[xx][yy])){
							mmaxarea = visited[x][y] + visited[xx][yy];
							tx = x;
							ty = y;
							dir = d;
						}
						if((visited[x][y] + visited[xx][yy]) == mmaxarea && (visited2[x][y] != visited2[xx][yy])){
							if(y < ty){
								tx = x;
								ty = y;
								dir = d;
							}
							if(y == ty && x > tx){
								tx = x;
								ty = y;
								dir = d;
							}
						}
					}
				}
			}
		}
	}
	cout<<mmaxarea<<endl;
	if(dir == 1){
		tx = tx + 1;
		dir = 0;
	}
	if(dir == 3){
		ty = ty - 1;
		dir = 2;
	}
	cout<<tx<<" "<<ty<<" ";
	if(dir == 0)
		cout<<"N"<<endl;
	if(dir == 2)
		cout<<"E"<<endl;
	return 0;
}
