/*
ID:kevin_s1
PROG:comehome
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


#define MAXN 53
#define INF 99999

//gobal variable====

int P;
int Graph[MAXN][MAXN];
int result;
int Dist[MAXN];

int visited[MAXN];
//==================


//function==========
int Convert(char ch){
	int index = -1;
	if(ch >= 'A' && ch <= 'Z'){
		index = ch - 'A' + 1;
	}
	else if(ch >= 'a' && ch <= 'z'){
		index = ch - 'a' + 27;
	}
	else
		index = -1;
	return index;
}

int Dijkstra(int v0){
	int min;
	int k;
	//init
	for(int i = 1; i < MAXN; i++){
		visited[i] = false;
		Dist[i] = Graph[v0][i];
	}
	Dist[v0] = 0;
	visited[v0] = 1;
	for(int v = 1; v < MAXN; v++){
		min = INF;
		for(int w = 1; w < MAXN; w++){
			if(!visited[w] && (Dist[w] < min)){
				min = Dist[w];
				k = w;
			}
		}
		visited[k] = 1;
		for(int w = 1; w < MAXN; w++){
			if(!visited[w] && (min + Graph[k][w] < Dist[w])){
				Dist[w] = min + Graph[k][w];
			}
		}
	}
	int Min = INF;
	for(int i = 1; i < MAXN; i++){
		if(Dist[i] < Min && i >= 1 && i <= 26 && Dist[i] > 0){
			Min = Dist[i];
			result = i;
		}
	}
	return Min;
}

//==================

int main(){
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	cin>>P;

	for(int i = 1; i < MAXN; i++){
		Graph[i][i] = INF;
		for(int j = 1; j < MAXN; j++){
			Graph[i][j] = INF;
		}
	}
	memset(visited, 0, sizeof(visited));
	while(P--){
		char chst, chen;
		int dist;
		cin>>chst>>chen>>dist;
		int st = Convert(chst);	
		int en = Convert(chen);
		if(dist < Graph[st][en]){
			Graph[st][en] = dist;
			Graph[en][st] = dist;
		}
	}
	int ans = Dijkstra(26);
	char chfarm = 'A' + result - 1;
	cout<<chfarm<<" ";
	cout<<ans<<endl;
	return 0;
}
