/*
ID:kevin_s1
PROG:maze1
LANG:C++
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <cmath>

using namespace std;

#define INF 9999999
#define MAXH 110
#define MAXW 50
#define MAXHH 250
#define MAXWW 100

//gobal variable====
int H, W;
int HH, WW;
string maze[MAXHH];
int G[MAXH][MAXW];
int Gtmp[MAXH][MAXW];
int wall[MAXH][MAXW][4];

struct entry{
	int x, y;
};

vector<entry> entrys;
int result;
int visited[MAXH][MAXW];

int direct[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
queue<entry> que;
//==================


//function==========
void print(){
	/*
	for(int i = 0; i < HH; i++){
		for(int j = 0; j < WW; j++){
			cout<<maze[i][j];
		}
		cout<<endl;
	}
	*/
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			cout<<Gtmp[i][j]<<"|"<<G[i][j]<<" ";
		}
		cout<<endl;
	}
}

void BFS(entry start){
	que.push(start);
	G[start.x][start.y] = 1;
	visited[start.x][start.y] = 1;
	while(!que.empty()){
		entry top = que.front();
		que.pop();
		for(int i = 0; i < 4; i++){
			if(wall[top.x][top.y][i] == 1){
				entry nw;
				nw.x = top.x + direct[i][0];
				nw.y = top.y + direct[i][1];
				if(nw.x < 1 || nw.x > H || nw.y < 1 || nw.y > W)
					continue;
				if(visited[nw.x][nw.y] == 0){
					G[nw.x][nw.y] = G[top.x][top.y] + 1; 
					que.push(nw);
					visited[nw.x][nw.y] = 1;
				}
			}
		}
	}
	return;
}
	
//==================

int main(){
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	cin>>W>>H;
	HH = 2 * H + 1;
	WW = 2 * W + 1;
	getchar();
	for(int i = 0; i < HH; i++){
		getline(cin, maze[i]);
	}
	memset(wall, 0, sizeof(wall));
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			if(maze[2*i][2*j-1] == ' ')
				wall[i][j][0] = 1;
			if(maze[2*i-2][2*j-1] == ' ')
				wall[i][j][1] = 1;
			if(maze[2*i-1][2*j-2] == ' ')
				wall[i][j][2] = 1;
			if(maze[2*i-1][2*j] == ' ')
				wall[i][j][3] = 1;
		}
	}
	
	entry tmp;
	for(int i = 1; i <= H; i++){
		if(wall[i][1][2] == 1){
			tmp.x = i, tmp.y = 1;
			entrys.push_back(tmp);
		}
		if(wall[i][W][3] == 1){
			tmp.x = i, tmp.y = W;
			entrys.push_back(tmp);
		}
	}

	for(int j = 1; j <= W; j++){
		if(wall[1][j][1] == 1){
			tmp.x = 1, tmp.y = j;
			entrys.push_back(tmp);
		}
		if(wall[H][j][0] == 1){
			tmp.x = H, tmp.y = j;
			entrys.push_back(tmp);
		}
	}

	result = 0;
	memset(visited, 0, sizeof(visited));
	memset(G, INF, sizeof(G));
	BFS(entrys[0]);
	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++)
			Gtmp[i][j] = G[i][j];
	}
	memset(visited, 0, sizeof(visited));
	memset(G, INF, sizeof(G));
	BFS(entrys[1]);

	for(int i = 1; i <= H; i++){
		for(int j = 1; j <= W; j++){
			G[i][j] = min(G[i][j], Gtmp[i][j]);
			if(G[i][j] > result && G[i][j] != INF)
				result = G[i][j];
		}
	}


	cout<<result<<endl;
	return 0;
}
